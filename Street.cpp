

#include "Street.h"

using std::ostream;

ostream& operator<<(ostream& stream, Street Street){
    return stream <<"Street "<< Street.id <<": " << Street.src << " " << Street.dest << " " << Street.weight << std::endl;
}