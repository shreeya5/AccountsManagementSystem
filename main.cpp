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
	AccountHolder user;
	Login_Screen()
	int userChoice, no_of_users=0, choice_of_action;
	string name, username;
	cin >> userChoice;
	
	string usernames[100];
	ofstream fout;
	ifstream fin;
	fin.open("userids.txt");
	while(getline(fin, username))
	{
		usernames[no_of_users] = username;
		i++;
	}
	fin.close();
		
	switch(userChoice)
	{
		case 1:
			cout << "Please enter your desired username : " ;
			cin << name;
			for(int j=0; j<no_of_users; j++)
			{
				if(name==usernames[j)
				{
					cout << "Username already exists. Please try another one." << endl;
					cin << name;
					j=-1;
				}
			}
			user.username = name;
			usernames[no_of_users] = name;
			no_of_users++;
			break;
			
		case 2:
			cout << "Please enter your username : " ;
			cin << name;
			bool usernameExists = false;
			for(int j=0; j<no_of_users; j++)
			{
				if(name==usernames[j])
				{
					usernameExists = true;
					break;
				}
			}
			if(usernameExists==false)
			{
				cout << "Username does not esist." << endl;
				exit(1);
			}
			break;
		
		default:
			cout << "Invalid Input!" << endl;
	}
	
	//updating file userids.txt 
	
	fout.open("userids.txt")
	if(fout.fail())
	{
		cout << "Error in opening Userids.txt"<< "\n";
		exit(1);
	}
	for(int j = 0; j<no_of_users; j++)
	{
		fout << usernames[j] << "\n";
	}
	fout.close();
	
	
	
	
	do
	{
		user.MainMenu();
		cout << "Please enter your choice : ";
		cin << choice_of_action;
		user.ManageCommands(choice_of_action);
	}while(choice_of_action != x);
	
}
