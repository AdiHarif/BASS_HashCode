#include "Car.h"
#include <iterator> 

Car::Car(list<int>* streets){
	streets=streets;
	just_passed=false;
}

void Car::step(){
	remaining_steps_in_street = std::max(remaining_steps_in_street-1, 0);
}

int Car::getNextStreet(){
	list<int>::iterator it = streets->begin();
	it++;
	if(it==streets->end()){
		return -1;
	}
	return *it;
}

void Car::newStreet(int value){
	remaining_steps_in_street = value;
	streets->pop_front();
}