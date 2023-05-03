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
//Retrieve the top of the stack and display it, return failure/success
int binder::retrieve_binder(binder & found)
{
	if (subject == nullptr || status == nullptr || b_desc == nullptr || b_priority == 0)
		return 0;
	found.subject = new char [strlen(subject) + 1];
	strcpy(found.subject, subject);
	found.status = new char [strlen(status) + 1];
	strcpy(found.status, status);
	found.b_desc = new char [strlen(b_desc) + 1];
	strcpy(found.b_desc, b_desc);
	found.b_priority = b_priority;
	return 1;
}

//Constructor- initialize the data memebers to their equivalent zeros
todo::todo()
{
	name = nullptr;
	t_desc = nullptr;
	link = nullptr;
	t_priority = 0;
}
//Destructor-  deallocate the memory by deleting
todo::~todo()
{}
//Copy the client information into the todo_item, return success/failure
int todo::copy_todo(const client_todo & to_add)
{
	if (to_add.c_name == nullptr || to_add.c_t_desc == nullptr || to_add.c_link == nullptr || to_add.c_t_priority == 0)
		return 0;
	name = new char [strlen(to_add.c_name) + 1];
	strcpy(name, to_add.c_name);
	t_desc = new char [strlen(to_add.c_t_desc) + 1];
	strcpy(t_desc, to_add.c_t_desc);
	link = new char [strlen(to_add.c_link) + 1];
	strcpy(link, to_add.c_link);
	t_priority = to_add.c_t_priority;
	return 1;
}
//Display todo item contents, return success/failure
int todo::display_todo() const
{
	if (name == nullptr || t_desc == nullptr || link == nullptr || t_priority == 0)
		return 0;
	cout << "\nName: " << name
		<< "\nDescription: " << t_desc
		<< "\nLink: " << link
		<< "\nPriority: " << t_priority << endl;
	return 1;
}
