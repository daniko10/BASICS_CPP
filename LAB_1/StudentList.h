#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

void show(TStudent*);
TStudent* InitTStudent();
void push_front(TStudent**, int);
void clear(TStudent**);

#endif