#include "Simulator.h"

Simulator::Simulator(vector<Street> streets, int num_of_intersections, vector<Car> cars) : finished_cars(0){
	street_graph = new StreetGraph(streets, num_of_intersections);
	cars = cars;
}

void Simulator::step(){
	//TODO:
	//for each intersection advance traffic lights

	for(auto street_ptr = street_graph->streets.begin(); street_ptr < street_graph->streets.end(); street_ptr++){
		if(street_ptr->cars.empty()){
			continue;
		}
		Car* first_car = street_ptr->cars[0];
		if(first_car->remaining_steps_in_street == 0 && street_ptr->traffic_light->is_green){
			int next_street_id = first_car->getNextStreet();
			if(next_street_id==-1){
				finished_cars++;
			}
			else{
				Street* next_street = &(street_graph->streets[next_street_id]);
				first_car->newStreet(next_street->weight);
				first_car->just_passed=true;
				next_street->cars.push_back(first_car);
			}
			street_ptr->cars.erase(street_ptr->cars.begin());
		}

		for(auto car_ptr = street_ptr->cars.begin(); car_ptr < street_ptr->cars.end(); car_ptr++){
			if((*car_ptr)->just_passed){
				(*car_ptr)->just_passed=false;
				continue;
			}
			(*car_ptr)->step();
		}
	}

	for(auto intersection_ptr = street_graph->intersections.begin(); intersection_ptr < street_graph->intersections.end(); intersection_ptr++){
		for(auto tl_ptr = intersection_ptr->traffic_lights.begin(); tl_ptr < intersection_ptr->traffic_lights.end(); tl_ptr++){
			
		}
	}

	steps++;
}