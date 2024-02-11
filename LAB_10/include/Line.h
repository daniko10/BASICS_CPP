#ifndef LINE_H
#define LINE_H

#include <iostream>

class LineSmartPtr;

class Line {
    public:
        Line(double, double);

        friend std::ostream& operator<<(std::ostream&, Line&);
        friend class LineSmartPtr;
    private:
        double _a;
        double _b;
};

class LineSmartPtr {
    public:
        ~LineSmartPtr();
        LineSmartPtr(Line*) noexcept;

        LineSmartPtr& operator=(LineSmartPtr&);
        friend Line& operator*(LineSmartPtr&);
    private:
        Line* ptr_to_line = nullptr;
        int *copy_count = nullptr;
};

#endif