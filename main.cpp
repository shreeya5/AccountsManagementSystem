#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "AccountHolder.h"

using namespace std;

void Login_Screen()
{
	cout << "1. Do you want to create a new account?" << endl;
	cout << "2. Do you want to log in an existing account?" << endl;
	cout << "3. Close application."<<endl;
	cout << "Please enter your prefered option : ";
}

int main()
{
	AccountHolder user;
	Login_Screen();
	int userChoice, choice_of_action;
	string name, username;
	bool usernameExists;
	cin >> userChoice;

	vector <string> usernames;
	ofstream fout;
	ifstream fin;
	fin.open("userids.txt");
	while(getline(fin, username))
	{
		usernames.push_back(username);
	}
	fin.close();

	switch(userChoice)
	{
		case 1:
			cout << "Please enter your desired username : " ;
			getline(cin,name);
			for(int j=0; j<username.size(); j++)
			{
				if(name==usernames[j])
				{
					cout << "Username already exists. Please try another one." << endl;
					getline(cin,name);
					j=-1;
				}
			}
			user.username = name;
			usernames.push_back(name);
			break;

		case 2:
			cout << "Please enter your username : " ;
			getline(cin,name);
			usernameExists = false;
			for(int j=0; j<usernames.size(); j++)
			{
				if(name==usernames[j])
				{
					usernameExists = true;
					user.username = name;
					break;
				}
			}
			if(usernameExists==false)
			{
				cout << "Username does not exist." << endl;
				exit(1);
			}
			break;
		case 3:
			cout <<"Successfully closed application"<<endl;
			exit(1);
			break;

		default:
			cout << "Invalid Input!" << endl;
	}

	//updating file userids.txt

	fout.open("userids.txt");
	if(fout.fail())
	{
		cout << "Error in opening Userids.txt \n";
		exit(1);
	}
	for(int j = 0; j<usernames.size(); j++)
	{
		fout << usernames[j] << "\n";
	}
	fout.close();

	do
	{
		user.MainMenu();
		cout << "Please enter your choice : ";
		cin >> choice_of_action;
		user.ManageCommands(choice_of_action);
	}while(choice_of_action != x);
	return 0;
}
