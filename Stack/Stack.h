#ifndef STACK_H
#define STACK_H

#include <iostream>

struct Stack {
	int value;
	struct Stack* next;
};

void push(Stack**, int);
void pop(Stack**);
void free_stack(Stack**);
void isEmpty(Stack*);
void print(Stack*);

#endif

// push
// pop
// isEmpty
// print