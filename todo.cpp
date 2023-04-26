#include "todo.h"
using namespace std;

//Molina Nhoung, CS163, 4/25/23, Program 2
//The purpose of this file is the implement the binder and the todo class functions
//where these class functions will be used by the stack and the queue classes. The binder
//and todo class functions will use the client struct information to copy the content to
//be used by the lists.

//Constructor- initialize the data members to their equivalent zeros
binder::binder()
{}
//Destructor- deallocate the memory be deleting
binder::~binder()
{}
//Copy the client information into a binder, return success/failure
int binder::copy_binder(const client_binder & to_add)
{}
//Display binder's contents, return success/failure
int binder::display_binder() const
{}

//Constructor- initialize the data memebers to their equivalent zeros
todo::todo()
{}
//Destructor-  deallocate the memory by deleting
todo::~todo()
{}
//Copy the client information into the todo_item, return success/failure
int todo::copy_todo(const client_todo & to_add)
{}
//Display todo item contents, return success/failure
int todo::display_todo() const
{}
