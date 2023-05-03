#include "todo.h"

//Molina Nhoung, CS163, 4/25/23, Program 2
//The purpose of this file is to create a queue of todo_items using a CLL.
//The data is organized in a class so that the programmer who uses this file
//can use this to examine the functions that were implemented and know what to 
//take and give to the user.

struct q_node
{
	todo item;	//an object for the todo_item class
	q_node * next;	//a next pointer
};

class queue
{
	public:
		queue();	//constructor
		~queue();	//destructor
		int enqueue(const client_todo & to_add);	//add a todo_item to the rear of the list and return success/failure
		int dequeue();	//removes an item from the front of the list and return success/failure
		int peek(todo & found_at_top) const;	//take the top item and store it in todo_item struct but doesn't modify the list. return success/failure
		int display_all() const;	//displays the todo_items and return success/failure
	private:
		q_node * rear;
	//	int display_all(q_node * rear) const;	//recursive call to display
};
