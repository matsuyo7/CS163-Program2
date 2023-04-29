#include <iostream>
#include <cctype>
#include <cstring>

//Molina Nhoung, CS163, 4/25/23, Program 2
//The purpose of this file is the organize the data for binders, todo_items, and client
//inputed data to be used by other classes and functions. This allows other programmers
//to examine this file to know what to take and give the user.

const int SIZE {200};	//client inputed data will have a max array size of 200

struct client_binder
{
	char c_sub[SIZE];	//user input what the subject is
	char c_stat[SIZE];	//user input status (complete of still in progress)
	char c_desc[SIZE];	//user input description of the type of information in the binder
	int c_priority;	//user input importance (1-5)
};

struct client_todo
{
	char c_name[SIZE];	//user input name of the item
	char c_t_desc[SIZE];	//user input desciption of what should be done
	char c_link[SIZE];	//user input link/website of where this information can be found
	int c_t_priority;	//user input importance (1-5)
};

class binder
{
	public:
		binder();	//constructor
		~binder();	//destructor
		int copy_binder(const client_binder & to_add); //copy the client info and store it, return success/failure
		//int copy_binder(const binder & new_binder);	//copy the binder info into a new binder, return success/failure
		int display_binder() const;	//display binder's contents, return success/failure
		int retrieve_binder(binder & found);	//retrieve the top of the stack and display it, return failure/success
	private:
		char * subject;	//what the subject is
		char * status;	//complete or still in progress
		char * b_desc;	//description of the type of information in the binder
		int b_priority;	//how important is this
};

class todo
{
	public:
		todo();	//constructor
		~todo();	//destructor
		int copy_todo(const client_todo & to_add);	//copy the client information into the todo_item, return success/failure
		int display_todo() const;	//display todo item contents, return success/failure
	private:
		char * name;	//name of the todo item
		char * t_desc;	//description of what should be done
		char * link;	//link/website of where this information can be found
		int t_priority;	//how important is this
};
