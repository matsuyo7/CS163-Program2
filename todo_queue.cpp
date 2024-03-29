#include "todo_queue.h"
using namespace std;

//Molina Nhoung, CS163, 4/25/23, Program 2
//The purpose of this file is the implement the functions from the queue class
//using the todo_item class which will be dealing with the data information.
//The queue is implemented using a CLL which will be a list of todo_items, each
//node contain a todo_item.

//Constructor- initialize the data members to their equivalent zeros
queue::queue()
{
	rear = nullptr;
}
//Destructor- deallocate the memory by deleting the data members
queue::~queue()
{
	if (rear)
	{
		q_node * current = rear;
		rear = rear->next;
		current->next = nullptr;
		while (rear)
		{
			current = rear->next;
			delete rear;
			rear = current;
		}
		rear = nullptr;
	}
}
//Add a todo_item to the rear of the list and return success/failure
int queue::enqueue(const client_todo & to_add)
{
	if (to_add.c_name == nullptr || to_add.c_t_desc == nullptr || to_add.c_link == nullptr || to_add.c_t_priority == 0)
		return 0;
	if (!rear)
	{
		rear = new q_node;
		rear->next = rear;
	}
	else
	{
		q_node * hold = rear->next;
		rear->next = new q_node;
		rear = rear->next;
		rear->next = hold;
	}
	rear->item.copy_todo(to_add);
	return 1;
}

//Removes an item from the front of the list and return success/failure
int queue::dequeue()
{
	if (!rear)
		return 0;
	if (rear->next == rear)
	{
		delete rear;
		rear = nullptr;
		return 1;
	}
	q_node * hold = rear->next;
	rear->next = hold->next;
	delete hold;
	return 1;
}
//Take the top item and store it in todo_item struct but doesn't modify the list. return success/failure
int queue::peek(todo & found_at_top) const
{
	if (!rear)
		return 0;
	rear->next->item.retrieve_todo(found_at_top);
	return 1;
}

//Displays the todo_items and return success/failure
int queue::display_all() const
{
	if (!rear)
		return 0;
/*	q_node * current = rear->next;
	while (current != rear)
	{
		current->item.display_todo();
		current = current->next;
	}
	rear->item.display_todo();
	return 1;*/
	int display = display_all(rear->next);
	return display;
}
//Recursive call for display_all queue
int queue::display_all(q_node * rear) const
{
	if (rear == this->rear)
	{
		rear->item.display_todo();
		return 0;
	}
	rear->item.display_todo();
	return display_all(rear->next);
}
	

