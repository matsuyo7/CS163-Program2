//#include "todo.h"
#include "todo_queue.h"

//Molina Nhoung, CS163, 4/25/23, Program 2
//The purpose of this file is to create a LLL where each stack is a binder of todo items.
//The data organized allows other programmers to examine the file to allow the user to
//enter the todo items and to see what connects with what structure.

struct node
{
	binder * binders;	//a dynamically allocated array of binders
	node * next;	//a next pointer
};

const int MAX {5};	//stack will have an array of 5

class stack
{
	public:
		stack();	//constructor
		~stack();	//destructor
		int push(const client_binder & to_add);	//takes a binder as an argument to add the binder to the top of the stack. return success/failure
		int pop();	//removes a binder from the top of the stack and returns success/failure
		int peek(binder & front_line);	//retrieve the binder from the top of the stack, but not modify the stack and return success/failure
		int display_all() const;	//display the binder data and return success/failure
	private:
		node * head;
		int top_index;	//index to indicate where the push next
	//	int display_all(node * rear) const;	//recursive call to display
};
