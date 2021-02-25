#include <stdlib.h>
#include <list>
#include "utils.h"

using std::list;

class Car {
    list<int>* streets;//current street is the head of the list
    int remaining_steps_in_street;

public:
    Car(list<int>* streets, int remaining_steps_in_street);
    void newStreet(int value);
    void step();
    int getNextStreet();
};