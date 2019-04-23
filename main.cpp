#include <iostream>
#include <string>
#include <vectors>
#include <fstream>
#include "AccountHolder.h"

using namespace std;

void Login_screen()
{
	cout << "1. Do you want to create a new account?" << endl;
	cout << "2. Do you want to log in an existing account?" << endl;
	cout << "Please enter your prefered option : ";
}

void main()
{
	AccountHolder 
	Login_Screen()
	int userChoice;
	string name;
	AccountHolder user;
	cin >> userChoice;
	
	do
	{
		switch(userChoice)
		{
			case 1:
				cout << "Enter desired username :" ;
				cin << name;
				for(int i=0; i<AccountHolders.size(); i++)
				{
					if(name==AccountHolders[i].username)
					{
						cout << "Username already exists. Please enter another one."
						cin << name;
						i=0;
					}
				}
				AccountHolders.push_back(name);
		}
	}
}
