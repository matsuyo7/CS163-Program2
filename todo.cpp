#include "todo.h"
using namespace std;

//Molina Nhoung, CS163, 4/25/23, Program 2
//The purpose of this file is the implement the binder and the todo class functions
//where these class functions will be used by the stack and the queue classes. The binder
//and todo class functions will use the client struct information to copy the content to
//be used by the lists.

//Constructor- initialize the data members to their equivalent zeros
binder::binder()
{
	subject = nullptr;
	status = nullptr;
	b_desc = nullptr;
	b_priority = 0;
}
//Destructor- deallocate the memory be deleting
binder::~binder()
{
	if (subject)
		delete [] subject;
	subject = nullptr;
	if (status)
		delete [] status;
	status = nullptr;
	if (b_desc)
		delete [] b_desc;
	b_priority = 0;
}
//Copy the client info and store it, return success/failure
int binder::copy_binder(const client_binder & to_add)
{
	if (to_add.c_sub == nullptr || to_add.c_stat == nullptr || to_add.c_desc == nullptr || to_add.c_priority == 0)
		return 0;
	subject = new char [strlen(to_add.c_sub) + 1];
	strcpy(subject, to_add.c_sub);
	status = new char [strlen(to_add.c_stat) + 1];
	strcpy(status, to_add.c_stat);
	b_desc = new char [strlen(to_add.c_desc) + 1];
	strcpy(b_desc, to_add.c_desc);
	b_priority = to_add.c_priority;
	return 1;
}
//Copy the client information into a binder, return success/failure
/*int binder::copy_binder(const binder & new_binder)
{
	if (new_binder.subject == nullptr || new_binder.status == nullptr || new_binder.b_desc == nullptr || new_binder.b_priority == 0)
		return 0;
	subject = new char [strlen(new_binder.subject) +1];
	strcpy(subject, new_binder.subject);
	status = new char [strlen(new_binder.status) + 1];
	strcpy(status, new_binder.status);
	b_desc = new char [strlen(new_binder.b_desc) + 1];
	strcpy(b_desc, new_binder.b_desc);
	b_priority = new_binder.b_priority;
	return 1;
}*/
//Display binder's contents, return success/failure
int binder::display_binder() const
{
	if (subject == nullptr || status == nullptr || b_desc == nullptr || b_priority == 0)
		return 0;
	cout << "\nSubject: " << subject
		<< "\nStatus: " << status
		<< "\nDescription: " << b_desc
		<< "\nPriority: " << b_priority << endl;
	return 1;
}

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
