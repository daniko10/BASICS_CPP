#include "Line.h"

LineSmartPtr::~LineSmartPtr() {
    if(*copy_count > 1) 
        (*copy_count)--;
    else if(*copy_count == 1) {
        delete ptr_to_line;
        delete copy_count;
    }
}

Line::Line(double a, double b) {
    _a = a;
    _b = b;
}

std::ostream& operator<<(std::ostream& strm, Line& obj) {
    strm << "y = "<<obj._a<<"*x + "<<obj._b<<"\tx0="<<-obj._b/obj._a;
    return strm;
}

LineSmartPtr::LineSmartPtr(Line* obj) noexcept {
    ptr_to_line = obj;
    copy_count = new int(1);
}

Line& operator*(LineSmartPtr& obj) {
    return *obj.ptr_to_line;
}

LineSmartPtr& LineSmartPtr::operator=(LineSmartPtr& obj) {
    delete ptr_to_line;
    delete copy_count;
    ptr_to_line = obj.ptr_to_line;
    (*obj.copy_count)+=1;
    copy_count = obj.copy_count;

    return *this;
}