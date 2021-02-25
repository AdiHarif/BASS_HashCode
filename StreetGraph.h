
#ifndef BASS_HASHCODE_STREETGRAPH_H
#define BASS_HASHCODE_STREETGRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include "utils.h"
using namespace std;

typedef pair<int, int> Edge; //first int is dest intersection, second int is weight

// A class to represent a graph object

class StreetGraph{
public:
    // a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Edge>> adjList;
    vector<Intersection> intersections;
    vector<Street> streets;

    // StreetGraph Constructor
    StreetGraph(vector<Street> &streets, int N) : streets(streets){

        // resize the vector to hold `N` elements
        adjList.resize(N);
        intersections.resize(N);

        // add edges to the directed graph
        for (int i=0; i<streets.size(); i++)
        {
            Street* street = &(streets[i]);
            int src = street->src;
            int dest = street->dest;
            int weight = street->weight;

            // insert at the end
            adjList[src].push_back(make_pair(dest, weight));
            intersections[dest].trafficLights.push_back(TrafficLight(street->id, 0, false)); //initializing all traffic lights with green duration of 0
            street->traffic_light = &(intersections[dest].trafficLights.back());
        }
    }
};

// Function to print adjacency list representation of a graph
void printStreetGraph(StreetGraph const &graph, int N)
{
    for (int i = 0; i < N; i++)
    {
        // Function to print all neighboring vertices of a given vertex
        for (Pair v: graph.adjList[i]) {
            cout << "(" << i << ", " << v.first <<
                 ", " << v.second << ") ";
        }
        cout << endl;
    }
}

int main()
{
    // vector of graph edges as per the above diagram.
    // Please note that the initialization vector in the below format will
    // work fine in C++11, C++14, C++17 but will fail in C++98.
    vector<Edge> edges =
            {
                    // `(x, y, w)` —> edge from `x` to `y` having weight `w`
                    { 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
                    { 3, 2, 10 }, { 5, 4, 1 }, { 4, 5, 3 }
            };

    // total number of nodes in the graph
    int N = 6;

    // construct graph
    Graph graph(edges, N);

    // print adjacency list representation of a graph
    printGraph(graph, N);

    return 0;
}


#endif //BASS_HASHCODE_STREETGRAPH_H

