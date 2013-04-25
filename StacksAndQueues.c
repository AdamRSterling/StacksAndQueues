#include <stdio.h>
#include <stdlib.h>

typedef struct Node //A node in the linked list internal representation of the stack
{
	int data; //The data
	Node* next; //A pointer to the next node in the link
} Node;

typedef struct Stack
{
	Node* first; //A pointer to the node at the top of the stack
} Stack;

enum Boolean
{
	FALSE,
	TRUE
};

Boolean isEmpty(Stack* stack)
{
	if(stack->first == NULL) 
		return TRUE;
	else return FALSE;
}

void push(Stack* stack, int data)
{
	Node *oldFirst = stack->first; //Create a temporary pointer to the node currently on top of the stack
	Node *first = (Node*) malloc(sizeof(Node)); //Create and initialize a new node.
	stack->first = first; //The stack's top node is the newest created node
	first->data = data; //Set it's data to the data being pushed.
	first->next = oldFirst; //Set it to point the node that was previously on top of the stack
}

int pop(Stack* stack)
{
	int item = stack->first->data; //Grab the item being held on the top node of the stack
	Node* newFirst = stack->first->next; //Create a pointer to the node that's underneath the node on top of the stack
	free(stack->first); //Free the top node
	stack->first = newFirst; //Have the stack's top node be the 2nd to top node.
	return item; //Return the data grabbed earlier

}

int main(int argc, char* argv[])
{
	Stack *testStack = (Stack*) malloc(sizeof(Stack));
	testStack->first = NULL;
	int input;

	printf("Welcome to the stack! Type an integer to push to the stack! Type -1 to pop, and type 0 to exit.\nInput: ");
	scanf_s("%d", &input);

	while(input != 0) {
		if (input == -1)
		{
			if(isEmpty(testStack) == TRUE)
				printf("Stack is empty!\n");
			else printf("%d\n", pop(testStack));
		}
		else push(testStack, input);
		scanf_s("Input: %d", &input);
	}
	free(testStack);
	return 0;
}
