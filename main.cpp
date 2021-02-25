
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Street.h"
#include "Car.h"

using namespace std;

void readStatsFiile(string path, int* stats){
}

vector<Street> readStreetsFile(string path){
    ifstream in_file(path);
    string line;
    vector<Street> streets;

    while (getline(in_file, line)){
        istringstream iss(line);
        streets.push_back(Street(iss));
    }

    return streets;
}

vector<Car> readCarFile(string path){
    return vector<Car>();
}


int main() {
    string path = "out\\dataset_parser\\a\\streets_out.txt";
    vector<Street> streets = readStreetsFile(path);
    for (int i =0 ; i<streets.size(); i++){
        cout << streets[i] << endl;
    }
}