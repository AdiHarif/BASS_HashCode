#include <stdlib.h>
#include <list>
#include "utils.h"

using std::list;

class Car {
public:
    list<int>* streets;//current street is the head of the list
    int remaining_steps_in_street;
    bool just_passed;

    Car(list<int>* streets);
    void newStreet(int value);
    void step();
    int getNextStreet();
};