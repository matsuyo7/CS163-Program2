//#include "todo.h"
#include "todo_queue.h"

//Molina Nhoung, CS163, 4/25/23, Program 2
//The purpose of this file is to create a LLL where each stack is a binder of todo items.
//The data organized allows other programmers to examine the file to allow the user to
//enter the todo items and to see what connects with what structure.


struct client_binder
{
	char c_sub[SIZE];	//user input what the subject is
	char c_stat[SIZE];	//user input status (complete of still in progress)
	char c_desc[SIZE];	//user input description of the type of information in the binder
	int c_priority;	//user input importance (1-5)
};
class binder
{
	public:
		binder();	//constructor
		~binder();	//destructor
		int copy_binder(const client_binder & to_add); //copy the client info and store it, return success/failure
		int display_binder() const;	//display binder's contents, return success/failure
		int retrieve_binder(binder & found);	//retrieve the top of the stack and display it, return failure/success
	private:
		char * subject;	//what the subject is
		char * status;	//complete or still in progress
		char * b_desc;	//description of the type of information in the binder
		int b_priority;	//how important is this
		queue * qptr;	//pointer to the queue
};
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
		int peek(binder & found_at_top);	//retrieve the binder from the top of the stack, but not modify the stack and return success/failure
		int display_all() const;	//display the binder data and return success/failure
	private:
		node * head;
		int top_index;	//index to indicate where the push next
	//	int display_all(node * rear) const;	//recursive call to display
};
