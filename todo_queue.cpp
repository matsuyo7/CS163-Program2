#include "todo_queue.h"
using namespace std;

//Molina Nhoung, CS163, 4/25/23, Program 2
//The purpose of this file is the implement the functions from the queue class
//using the todo_item class which will be dealing with the data information.
//The queue is implemented using a CLL which will be a list of todo_items, each
//node contain a todo_item.

//Constructor- initialize the data members to their equivalent zeros
queue::queue()
{}
//Destructor- deallocate the memory by deleting the data members
queue::~queue()
{}
//Add a todo_item to the rear of the list and return success/failure
int queue::enqueue(const todo & to_add)
{}
//Removes an item from the front of the list and return success/failure
int queue::dequeue()
{}
//Take the top item and store it in todo_item struct but doesn't modify the list. return success/failure
int queue::peek(todo & found_at_top) const
{}
//Displays the todo_items and return success/failure
int queue::display_all() const
{}
