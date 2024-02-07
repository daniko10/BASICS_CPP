#include "Angle.h"

Angle Angle::fromRadians(double radians){
    std::cout<<"... creating angle from radians."<<std::endl;
    
    Angle temp_angle;
    temp_angle._radians = rad(radians);
    return temp_angle;
}

Angle Angle::fromDegrees(double degrees){
    std::cout<<"... creating angle from degrees."<<std::endl;
    
    Angle temp_angle;
    int temp;
    if(degrees < 0) {
        do {
            degrees += 360;
        } while(degrees < 0);
    }
    else {
        temp = degrees/360;
        degrees -= (temp * 360);
    }

    temp_angle._radians = degrees*2*M_PI/360;
    return temp_angle;
}

Angle& Angle::add(const Angle& obj) {
    this->_radians += obj._radians;
    this->_radians = rad(this->_radians);

    return *this;
}

double Angle::toDeg() const {
    return _radians*360/(2*M_PI);
}

double rad(double radians) {
    int temp;
    if(radians >= 0) {
        temp = radians/(2*M_PI);
        radians -= temp*2*M_PI;
    }
    else {
        do {
            radians += 2*M_PI;
        } while(radians < 0);
    }

    return radians;
}

void Angle::print() const {
    std::cout<<"Angle [rad]: "<<_radians<<std::endl;
}