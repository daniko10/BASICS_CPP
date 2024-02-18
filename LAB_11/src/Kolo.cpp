#include "Kolo.h"

void Kolo::wypisz() const {
    std::cout<<"Kolo o promieniu: "<<_x<<std::endl;
}

double Kolo::polePow() const {
    return PI*_x*_x;
}