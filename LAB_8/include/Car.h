#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <cstring>

class Car {
    public:
        ~Car();
        Car(const char*, int, int);
        Car(const Car&);
        Car(const Car&&);
        Car& operator=(Car&&);
        Car& operator=(const Car&);
        void displayInfo() const;
    private:
        char* _car_name = new char[10];
        int _year_prod = 0;
        int *_mileage = nullptr;
        mutable bool to_delete = false;
};

#endif