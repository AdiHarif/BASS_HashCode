
#pragma once

#include <sstream>
#include <iostream>

using std::ws;
using std::istream;
using std::ostream;
class Street {
public:
    int src, dest, weight, id;

    Street(istream& iss){
        iss >> src >> ws >> dest >> ws >> weight >> ws >> id;
    }

};


ostream& operator<<(ostream& stream, Street Street);