#ifndef AccountHolder_h
#define AccountHolder_h

#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Account
{
	vector <string> category;
	vector <double> value;
};

class AccountHolder
{
	public:
		void readFromFile();
		void BudgetCheck(double);
		void ManageExpenses();
		void ManageIncomes();
		void ManageBudget();
		void ManageAccountLogs();
		void TransferAmount();
		void ViewStats();
		void MainMenu();
		void ManageCommands(int);
		void writeToFile();


	string username;
	double budget;
	Account income, expense, logs;

};

#endif
