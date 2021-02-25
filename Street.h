
#ifndef BASS_HASHCODE_STREET_H
#define BASS_HASHCODE_STREET_H

#include <vector>
#include "Car.h"
using namespace std;


class Street {
public:
    int src, dest, weight, id;
    vector<Car*> cars;
    TrafficLight* traffic_light;

    Street(vector<Car*> cars, int src, int dest, int weight, int id): src(src), dest(dest), weight(weight), id(id){
        cars=cars;
        traffic_light=nullptr;
    }
};


#endif //BASS_HASHCODE_STREET_H

