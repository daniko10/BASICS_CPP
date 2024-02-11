#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <vector>

class LArray;

class Line {
    public:
        Line();
        Line(int);
        double operator()(double);
        double X0();

        friend class LPrint;
        friend class LArray;
    private:
        double a;
        double b;
};

class LPrint {
    public:
        void operator()(Line&);
        void operator()(LArray&);
};

class LArray {
    public:
        ~LArray();
        LArray(int);
        LArray& Add(Line);

        friend class LPrint;
    private:
        Line *T_lines  = nullptr;
        int n=0;
        int index=0;
};

#endif