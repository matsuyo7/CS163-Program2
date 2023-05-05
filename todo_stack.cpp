#include "todo_stack.h"
using namespace std;

//Molina Nhoung, CS163, 4/25/23, Program 2
//The purpose of this file is the implement the functions from the stack class
//using the binder class that will deal with the information. This stack is
//implemented using a LLL of arrays of size 5 where each element of the array
//will contain a binder

//Constructur- Initialize the data members to the equivalent zeros
stack::stack()
{
	head = nullptr;
	top_index = 0;
}
//Destructor - Deallocate the data members by deleting the memory
stack::~stack()
{
	node * current = head;
	while (current)
	{
		current = current->next;
		if (head->binders)
			delete [] head->binders;
		delete head;
		head = current;
	}
	head = nullptr;
	top_index = 0;
}
//Takes a binder as an argument to add the binder to the top of the stack. return success/failure
int stack::push(const client_binder & to_add)
{
/*	if (!head)
	{
		head = new node;
		head->next = nullptr;
		head->binders = new binder[MAX];
		top_index = 0;
	}*/
	if (to_add.c_sub == nullptr || to_add.c_stat == nullptr || to_add.c_desc == nullptr || to_add.c_priority == 0)
		return 0;
	if (!head || top_index == MAX)
	{
		node * temp = head;
		head = new node;
		head->binders = new binder[MAX];
		head->next = temp;
		top_index = 0;
	}
	if (head->binders[top_index].copy_binder(to_add))
		++top_index;
	return 1;
}
//Removes a binder from the top of the stack and returns success/failure
int stack::pop()
{
	if (!head)
		return 0;
	node * hold = head->next;
	if (!top_index)	//if top index == 0
	{
		if (head->binders)
			delete [] head->binders;
		delete head;
		head = hold;
		top_index = MAX;
	}
	--top_index;
	return 1;
}

//Retrieve the binder from the top of the stack, but not modify the stack and return success/failure
int stack::peek(binder & found_at_top)
{
	if (!head)
		return 0;
	node * current = head->next;
	if (!top_index)
	{
		if (!head->next)
			return 0;
		current->binders[MAX-1].retrieve_binder(found_at_top);
		return 1;
	}
	head->binders[top_index-1].retrieve_binder(found_at_top);
	return 1;
}	

//Display the binder data and return success/failure
int stack::display_all() const
{
	if (!head)
		return 0;
       	node * current = head;
	int size = top_index;
	while (current)
	{
		for (int i = size; i > 0; --i)
		{
			current->binders[i-1].display_binder();
		}
		current = current->next;
		size = MAX;

	}
	return 1;
}
