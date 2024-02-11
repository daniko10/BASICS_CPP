#include "Car.h"

using std::cout;
using std::endl;

Car::~Car() {
    if(to_delete)
        return;
    delete [] _car_name;
    delete _mileage;
}

Car::Car(const char* car_name, int year, int mileage) {
    strcpy(_car_name, car_name);
    _year_prod = year;
    _mileage = new int(mileage);
}

Car::Car(const Car& obj) {
    strcpy(_car_name, obj._car_name);
    _year_prod = obj._year_prod;
    _mileage = new int(*(obj._mileage));
}

Car::Car(const Car&& obj): _car_name(std::move(obj._car_name)), _year_prod(std::move(obj._year_prod)), _mileage(std::move(obj._mileage)), to_delete(std::move(obj.to_delete)){
    obj.to_delete = true;
}

Car& Car::operator=(Car&& obj) {
    if(this!=&obj) {
        *this = obj;
        delete [] obj._car_name;
        delete obj._mileage;
        obj.to_delete = true;
    }

    return *this;
}

Car& Car::operator=(const Car& obj) {
    if(this!=&obj) {
        delete [] _car_name;
        delete _mileage;
    }
    _car_name = new char[10];
    strcpy(_car_name, obj._car_name);
    _mileage = new int (*(obj._mileage));
    _year_prod = obj._year_prod;

    return *this;
}

void Car::displayInfo() const {
    if(!to_delete)
        cout << "Brand: "<<_car_name<< ", Year: "<<_year_prod<< ", Mileage: "<<*_mileage<<endl;
    else
        cout << "Brand: ? Year: ? Mileage: ?"<<endl;
}
