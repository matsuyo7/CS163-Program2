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
	binder a_binder;	//a binder object
	stack my_binder;
	char again {'n'};
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
		//Store the information
		//to_add.copy_binder(your_binder);
		//Push the information into the binder stack
		my_binder.push(your_binder);
		cout << "\nDo again?: ";
		cin >> again;
		cin.ignore(SIZE, '\n');
	} while (again == 'y');
	cout << "\nContents in the journal: " << endl;
	my_binder.display_all();
	my_binder.pop();
	cout << "\nAfter popping it is now: " << endl;
	my_binder.display_all();












	return 0;
}
