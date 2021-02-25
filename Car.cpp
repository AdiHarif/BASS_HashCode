#include "Car.h"
#include <iterator> 

Car::Car(list<int>* streets, int remaining_steps_in_street){
	streets=streets;
	remaining_steps_in_street=remaining_steps_in_street;
}

void Car::step(){
	remaining_steps_in_street = std::max(remaining_steps_in_street-1, 0);
}

int Car::getNextStreet(){
	list<int>::iterator it = streets->begin();
	it++;
	return *it;
}
void Car::newStreet(int value){
	remaining_steps_in_street = value;
	streets->pop_front();
}