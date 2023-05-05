#include "todo_stack.h"
using namespace std;

//Molina Nhoung, CS163, 4/27/23, Program 2
//The purpose of this file is to act as the client program to send information
//to the ADT to be use, and recieve returned values to output the right messages,
//such as successes and errors. The client program will prompt the user and send
//the information to the ADT.

//Prototypes
int menu();
void add_subject(client_binder & your_binder, stack & my_binder, queue * qptr);
int todo_menu();
void add_todo(client_todo & your_todo, queue * qptr);

int main()
{
	client_binder your_binder;	//client binder object
	client_todo your_todo;	//client todo object
	binder to_find;	//a binder object
	todo find_todo;	//a todo object
	stack my_binder;	//stack object
	int pick {0};	//what option does the user want to do for a binder
	int todo_pick {0};	//what option does the user want to do for a todo
	
	do
	{
		pick = menu();
		//Add a subject and its todo list
		if (pick == 1)
		{
			queue * qptr = new queue;
			do
			{
				todo_pick = todo_menu();
				//Add a todo item to the todo list
				if (todo_pick == 1)
				{
					add_todo(your_todo, qptr);
				}
				//Display the todo list
				if (todo_pick == 2)
				{
					qptr->display_all();
				}
				//Dequeue the beginning of the queue
				if (todo_pick == 3)
				{
					qptr->dequeue();
					cout << "\nAfter dequeue: " << endl;
					qptr->display_all();
				}
				//Peek at the front of the todo list
				if (todo_pick == 4)
				{
					if (qptr->peek(find_todo))
						cout << "\nTodo at the front of the list: " << find_todo.display_todo() << endl;
					else
						cout << "\nCouldn't peek" << endl;
				}
			} while (todo_pick != 5);
			add_subject(your_binder, my_binder, qptr);
		}
		//Display all todo binders and their todo list
		if (pick == 2)
		{
			cout << "\nContents in the binder: " << endl;
			my_binder.display_all();
		}
		//Pop at the top of the stack of binders
		if (pick == 3)
		{
			my_binder.pop();
			cout << "\nAfter popping it is now: " << endl;
			my_binder.display_all();
		}
		//Peek at the top of the stack of binders
		if (pick == 4)
		{
			if (my_binder.peek(to_find))
				cout << "\nBinder at the top of the stack: " << to_find.display_binder() << endl;
			else
				cout << "\nCouldn't peek" << endl;
		}
	} while (pick != 5);

	return 0;
}

//Functions
//Binder menu
int menu()
{
	int option = 0;
	do
	{
		cout << "\n***TODO ORGANIZER***"
			"\n1. Create a todo list and its subject binder"
			"\n2. Display all subjects and their todo's"
			"\n3. Remove the most recent subject"
			"\n4. See the most recent subject"
			"\n5. Quit"
			"\n\nPick an option: ";
		cin >> option;
		cin.ignore(100, '\n');
		if (option < 1 || option > 5)
			cout << "\nTry again" << endl;
	} while (option < 1 || option > 5);
	return option;
}
//Add a subject and prompt a todo menu for the user to add the todo to the subject binder
void add_subject(client_binder & your_binder, stack & my_binder, queue * qptr)
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
	my_binder.push(your_binder, qptr);
}
//Menu for the todo list
int todo_menu()
{
	int option = 0;
	do
	{
		cout << "\n***TODO LIST***"
			"\n1. Add a todo item"
			"\n2. Display the todo list"
			"\n3. Remove the first todo item"
			"\n4. Peek at the first todo item"
			"\n5. Quit"
			"\n\nPick an option: ";
		cin >> option;
		cin.ignore(100, '\n');
		if (option < 1 || option > 5)
			cout << "\nTry again" << endl;
	} while (option < 1 || option > 5);
	return option;
}
//Add a todo item to the todo list
void add_todo(client_todo & your_todo, queue * qptr)
{
	//Promp the user for todo item information
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
	qptr->enqueue(your_todo);
}
