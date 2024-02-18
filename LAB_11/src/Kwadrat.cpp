#include "Kwadrat.h"

void wypisz(const Ksztalt& ksztalt_obj) {
    ksztalt_obj.wypisz();
}

void Kwadrat::wypisz() const {
    std::cout<<"Kwadrat o boku: "<<_x<<std::endl;
}

double Kwadrat::polePow() const {
    return _x*_x;
}