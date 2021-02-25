//
// Created by Alon on 2021-02-25.
//

#ifndef BASS_HASHCODE_STREET_H
#define BASS_HASHCODE_STREET_H


class Street {
public:
    int src, dest, weight, id;

    Street(int src, int dest, int weight, int id): src(src), dest(dest), weight(weight), id(id){

    }
};


#endif //BASS_HASHCODE_STREET_H
