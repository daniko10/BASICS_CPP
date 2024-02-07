#include "MapPoint.h"

using std::cout;
using std::endl;

double MapPoint::distanceVal(MapPoint& obj) const {
    return modul(obj._x, _x, obj._y, _y);
}

double MapPoint::distanceVal(MapPoint* obj) const {
    return modul(obj->_x, _x, obj->_y, _y);
}

double modul(double x1, double x2, double y1, double y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void MapPoint::set_coordinates(double x, double y) {
    _x = x;
    _y = y;
}

void MapPoint::print() const {
    cout<<"Point: ("<<_x<<", "<<_y<<")"<<endl;
}