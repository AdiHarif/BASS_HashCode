
#ifndef BASS_HASHCODE_UTILS_H
#define BASS_HASHCODE_UTILS_H

class TrafficLight{
public:
    int id;
    int duration;
    bool is_green;

    TrafficLight(int id, int duration, bool is_green) : id(id), duration(duration), is_green(is_green){ }
};


struct Intersection{
    vector<TrafficLight> traffic_lights;
};

#endif //BASS_HASHCODE_UTILS_H

