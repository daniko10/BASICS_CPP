#ifndef MAPPOINT_H
#define MAPPOINT_H

#include <iostream>
#include <cmath>

class MapPoint {
    public:
        MapPoint(double x=0, double y=0): _x(x), _y(y){};
        double distanceVal(MapPoint&) const;
        double distanceVal(MapPoint*) const;
        void set_coordinates(double, double);
        void print() const;
    private:
        double _x;
        double _y;
};

double modul(double, double, double, double);

#endif