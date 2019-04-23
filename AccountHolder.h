#include <vector>
#include <string>

using namespace std;

struct Account
{
	string type[100];
	double value[100];
};

class AccountHolder
{
	public:
		void ManageExpenses();
		void ManageIncomes();
		void ManageBudget();
		void MainMenu();
		void ManageCommands();
		
	
	
	string username;
	double budget;
	Account Income, Expense;	
		
};

