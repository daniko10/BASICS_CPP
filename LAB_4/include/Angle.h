#ifndef ANGLE_H
#define ANGLE_H

#include <iostream>
#include <cmath>

class Angle {
    public:
        Angle() = default;
        static Angle fromRadians(double);
        static Angle fromDegrees(double);
        Angle& add(const Angle&);
        double toDeg() const;
        void print() const;
    private:
        double _radians = 0;
};

double rad(double);

#endif