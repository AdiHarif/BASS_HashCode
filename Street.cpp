

#include "Street.h"

#include <iostream>


ostream& operator<<(ostream& stream, Street Street){
    return stream <<"Street "<< Street.id <<": " << Street.src << " " << Street.dest << " " << Street.weight;
}