#ifndef KSZTALT_H
#define KSZTALT_H
#define PI 3.1415

#include <iostream>

class Ksztalt {
    public:
        Ksztalt(int x): _x(x) {}
        virtual double polePow() const = 0;
        virtual void wypisz() const = 0;
    protected:
        int _x;
};

void wypisz(const Ksztalt&);

#endif