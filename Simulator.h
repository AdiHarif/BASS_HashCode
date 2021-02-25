#include "Car.h"
#include "Street.h"
#include "StreetGraph.h"
#include <vector>

class Simulator{
	int steps;
	int finished_cars;
	StreetGraph* street_graph;
	vector<Car*> cars;

public:
	Simulator(vector<Street> streets, int num_of_intersections, vector<Car> cars);
	void step();
	
};