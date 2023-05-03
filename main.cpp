#include "todo_stack.h"
using namespace std;

//Molina Nhoung, CS163, 4/27/23, Program 2
//The purpose of this file is to act as the client program to send information
//to the ADT to be use, and recieve returned values to output the right messages,
//such as successes and errors. The client program will prompt the user and send
//the information to the ADT.

//Prototypes
int menu();

int main()
{
	client_binder your_binder;	//client binder object
	client_todo your_todo;	//client todo object
	binder to_find, a_binder;	//a binder object
	todo find_todo, one_todo;	//a todo object
	stack my_binder;	//stack object
	queue my_todo;	//queue object
	char again {'n'};	//does the user want to add another binder
	char response {'n'};	//does the user want to add another todo

	do
	{
		//Promp the user for the binder information
		cout << "\nWhat's the subject: ";
		cin.get(your_binder.c_sub, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		cout << "\nWhat's the status: ";
		cin.get(your_binder.c_stat, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		cout << "\nDescription of the type of information in this subject: ";
		cin.get(your_binder.c_desc, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		cout << "\nLevel of priority (1-5): ";
		cin >> your_binder.c_priority;
		cin.ignore(SIZE, '\n');
		//Push the information into the binder stack
		my_binder.push(your_binder);
		cout << "\nDo again?: ";
		cin >> again;
		cin.ignore(SIZE, '\n');
	} while (again == 'y');
	cout << "\nContents in the journal: " << endl;
	my_binder.display_all();
	//Pop at the top of the stack of binders
	my_binder.pop();
	cout << "\nAfter popping it is now: " << endl;
	my_binder.display_all();
	//Peek the top of the stack of binders
	if (my_binder.peek(to_find))
		cout << "\nPeeked" << endl;
	else
		cout << "\nCouldn't peek" << endl;
	cout << "\nBinder at the top of the stack: " << to_find.display_binder() << endl;

	//Promp the user for todo item information
	do
	{
		cout << "\nName of todo item: ";
		cin.get(your_todo.c_name, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		cout << "\nDescription of what should be done: ";
		cin.get(your_todo.c_t_desc, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		cout << "\nWhere can this information be found (link/website): ";
		cin.get(your_todo.c_link, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		cout << "\nLevel of priority (1-5): ";
		cin >> your_todo.c_t_priority;
		cin.ignore(SIZE, '\n');
		//Enqueue the information into the todo item queue
		my_todo.enqueue(your_todo);
		cout << "\nDo again?: ";
		cin >> response;
		cin.ignore(SIZE, '\n');
	} while (response == 'y');
	my_todo.display_all();
	//Dequeue the beginning of the queue
	my_todo.dequeue();
	cout << "\nAfter dequeue: " << endl;
	my_todo.display_all();



	return 0;
}

//Functions
