#include <iostream>
#include <strings>

using namespace std;


struct Category
{
	string type[100];
	double value[100];
};

struct User
{
	string username;
	Categoy account, income, expense;
	double budget;
};

void DisplayMainMenu()
{
	cout << "0: exit \n";
}
