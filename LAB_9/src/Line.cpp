#include "Line.h"

using std::cout;
using std::endl;

Line::Line() {
    a = 1;
    b = 1;
}

Line::Line(int value) {
    a = value;
    b = value;
}

double Line::operator()(double x)  {
    return x*a + b;
}

double Line::X0() {
    return -b/a;
}

void LPrint::operator()(Line& obj) {
    cout<<"y = "<<obj.a<<"*x + "<<obj.b<<"\tx0="<<obj.X0()<<endl;
}

void LPrint::operator()(LArray& obj) {
    for(int i=0; i<obj.n; i++) {
        cout<<"["<<i<<"]";
        cout<<"y = "<<obj.T_lines[i].a<<"*x + "<<obj.T_lines[i].b<<"\tx0="<<obj.T_lines[i].X0()<<endl;
    }
}

LArray::LArray(int n_tab) {
    n = n_tab;
    T_lines = new Line[n];
}

LArray& LArray::Add(Line temp_obj) {
    T_lines[index].a = temp_obj.a;
    T_lines[index].b = temp_obj.b;
    index++;

    return *this;
}

LArray::~LArray() {
    delete [] T_lines;
}