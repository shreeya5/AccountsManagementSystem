#include <iostream>
#incluse <string>
#include <fstream>
#include "AccountHolder.h"

using namespace std;


void AccountHolder::ManageExpenses()
{
	cout << "Manage Your Expenses" << endl;
	cout << "************************************************" << endl;
	cout << "1. Back to Main menu." << endl;
	cout << "2. Add an expenditure." << endl;
	cout << "3. Edit an expenditure." << endl;
	cout << "4. Delete an expenditure." << endl;
	cout << "************************************************" << endl;
	
}

void AccountHolder::ManageIncomes()
{
	cout << "Manage Your Incomes" << endl;
	cout << "************************************************" << endl;
	cout << "1. Back to Main menu." << endl;
	cout << "2. Add a new income." << endl;
	cout << "3. Edit an income." << endl;
	cout << "4. Delete an income." << endl;
	cout << "************************************************" << endl;
}

void AccountHolder::MainMenu()
{
	cout << "welcome to your Accounts Management System" << endl;
	cout << "************************************************" << endl;
	cout << "1. Manage Expenses." << endl;
	cout << "2. Manage Incomes." << endl;
	
	
	
	cout << "x. Exit" << endl;
}

void AccountHolder::ManageCommands(choice_of_action)
{
	switch(choice_of_action)
	{
		case 1:
			ManageExpenses();
		case 2:
			ManageIncomes();
			
			
			
			
		
		
		case x:
			cout << "Thankyou for using Accounts Management System!" << endl;
			break;
		
		default:
			cout << "Invalid Input! Please Try again" << endl;
						
	}
}
