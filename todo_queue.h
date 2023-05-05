//#include "todo.h"
#include <iostream>
#include <cctype>
#include <cstring>

//Molina Nhoung, CS163, 4/25/23, Program 2
//The purpose of this file is to create a queue of todo_items using a CLL.
//The data is organized in a class so that the programmer who uses this file
//can use this to examine the functions that were implemented and know what to 
//take and give to the user.

const int SIZE {200};	//client inputed data will have a max array size of 200

struct client_todo
{
	char c_name[SIZE];	//user input name of the item
	char c_t_desc[SIZE];	//user input desciption of what should be done
	char c_link[SIZE];	//user input link/website of where this information can be found
	int c_t_priority;	//user input importance (1-5)
};
class todo
{
	public:
		todo();	//constructor
		~todo();	//destructor
		int copy_todo(const client_todo & to_add);	//copy the client information into the todo_item, return success/failure
		int display_todo() const;	//display todo item contents, return success/failure
		int retrieve_todo(todo & found);	//retrieve the first of the list and add it to the given argument, return success/failure
	private:
		char * name;	//name of the todo item
		char * t_desc;	//description of what should be done
		char * link;	//link/website of where this information can be found
		int t_priority;	//how important is this
};
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
