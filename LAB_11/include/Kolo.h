#ifndef KOLO_H
#define KOLO_H

#include "Ksztalt.h"

class Kolo: public Ksztalt {
    public:
        Kolo(int x) : Ksztalt(x) {}
        void wypisz() const;
        double polePow() const;
};

#endif