#include "Stack.h"

int main() {
	Stack* head = nullptr;
	
	for (int i = 0; i < 10; i++)
		push(&head, 5 * i);
	
	print(head);
	pop(&head);
	print(head);
	isEmpty(head);
	free_stack(&head);
}
