#include "Stack.h"

using std::cout;
using std::endl;

void push(Stack** head, int x) {
	Stack* new_head = new Stack;
	new_head->next = nullptr;
	new_head->value = x;

	if (*head) {
		Stack* temp = *head;
		for (; temp->next; temp = temp->next);
		temp->next = new_head;
	}
	else 
		*head = new_head;
	
}

void pop(Stack** head) {
	Stack* to_pop = *head;
	Stack* temp = *head;
	if (*head) {
		if ((*head)->next) {
			for (; to_pop->next->next; to_pop = to_pop->next)
				temp = to_pop->next;
			delete temp->next;
			temp->next = nullptr;
		}
		else {
			delete* head;
			*head = nullptr;
		}
	}
	else
		cout << "CANT POP!" << endl;

}

void isEmpty(Stack* head) {
	if (!head)
		cout << "EMPTY!" << endl;
	else
		cout << "NOT EMPTY!" << endl;
}

void free_stack(Stack** head) {
	while (*head)
		pop(head);
}

void print(Stack* head) {
	cout << "Stack -> ";
	if (!head) {
		cout << "Empty" << endl;
		return;
	}
	for (; head; head = head->next)
		cout << head->value << " -> ";
	cout << "NULL" << endl;
}