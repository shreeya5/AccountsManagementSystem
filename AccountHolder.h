#include <vector>
#include <string>

using namespace std;

struct Account
{
	vector <string> category;
	vector <double> value;
};

class AccountHolder
{
	public:
		void ManageExpenses();
		void ManageIncomes();
		void BudgetCheck(double);
		void ManageBudget();
		void ManageAccountLogs();
		void TransferAmount();
		void ViewStats();
		void MainMenu();
		void ManageCommands(int);
		
		
	
	
	string username;
	double budget;
	Account income, expense, logs;	
		
};

