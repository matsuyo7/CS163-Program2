#include "todo_stack.h"
using namespace std;

//Molina Nhoung, CS163, 4/27/23, Program 2
//The purpose of this file is to act as the client program to send information
//to the ADT to be use, and recieve returned values to output the right messages,
//such as successes and errors. The client program will prompt the user and send
//the information to the ADT.

//Prototypes
int menu();
void add_subject(client_binder & your_binder, stack & my_binder);
int todo_menu();
void add_todo(client_todo & your_todo);

int main()
{
	client_binder your_binder;	//client binder object
	client_todo your_todo;	//client todo object
	binder to_find, a_binder;	//a binder object
	todo find_todo, one_todo;	//a todo object
	stack my_binder;	//stack object
	queue my_todo;	//queue object
	char response {'n'};	//does the user want to add another todo
	int pick {0};	//what option does the user want to do for a binder
	int todo_pick {0};	//what option does the user want to do for a todo
	
	do
	{
		pick = main();
		//Add a subject and its todo list
		if (pick == 1)
		{
			add_subject(your_binder, my_binder);
			do
			{
				todo_pick = todo_menu();
				if (todo_pick == 1)
				{}
				if (todo_pick == 2)
				{}
				if (todo_pick == 3)
				{}
				if (todo_pick == 4)
				{}
			} while (todo_pick != 5);
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
	//Peek at the front of the todo list
	if (my_todo.peek(find_todo))
		cout << "\nPeeked" << endl;
	else
		cout << "\nCouldn't peek" << endl;
	cout << "\nTodo at the front of the list: " << find_todo.display_todo() << endl;



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
			"\n1. Create a subject and its todo's"
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
void add_subject(client_binder & your_binder, stack & my_binder)
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
