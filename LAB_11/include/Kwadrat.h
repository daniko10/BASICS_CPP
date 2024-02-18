#ifndef KWADRAT_H
#define KWADRAT_H

#include "Ksztalt.h"

class Kwadrat: public Ksztalt {
    public:
        Kwadrat(int x): Ksztalt(x) {}
        void wypisz() const;
        double polePow() const;
};

#endif