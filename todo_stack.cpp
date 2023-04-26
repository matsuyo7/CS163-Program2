#include "todo_stack.h"
using namespace std;

//Molina Nhoung, CS163, 4/25/23, Program 2
//The purpose of this file is the implement the functions from the stack class
//using the binder class that will deal with the information. This stack is
//implemented using a LLL of arrays of size 5 where each element of the array
//will contain a binder

//Constructur- Initialize the data members to the equivalent zeros
stack::stack()
{}
//Destructor - Deallocate the data members by deleting the memory
stack::~stack()
{}
//Takes a binder as an argument to add the binder to the top of the stack. return success/failure
int stack::push(const binder & to_add)
{}
//Removes a binder from the top of the stack and returns success/failure
int stack::pop()
{}
//Retrieve the binder from the top of the stack, but not modify the stack and return success/failure
int stack::peek(binder & front_line)
{}
//Display the binder data and return success/failure
int stack::display_all() const
{}
