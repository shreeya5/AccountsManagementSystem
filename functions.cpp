#include <iostream>
#include <string>
#include <fstream>
#include "AccountHolder.h"

using namespace std;

//Function to check if budget has been reached
void AccountHolder::BudgetCheck(double sum)
{
	if (budget-sum == 0)
	{
		cout << "Reached Budget Limit!" << endl;
	}
	else if (budget-sum < 0)
	{
		cout << "Exceeded Budget Limit by HK$" << sum-budget << endl;
	}
}

//Function to manage expenses : add/edit/delete/view
void AccountHolder::ManageExpenses()
{
	cout << "\n*************** Expense Management ***************\n" << endl;
	string ExpenseMenu[5] = {"Back to Main menu." , "Add an expenditure." , "Edit an expenditure." , "Delete an expenditure." , "View all Expenses Category wise."};
	int choice, accountChoice, editChoice, deleteChoice;
	double NewExpenseValue, total, UpdateValue;
	string NewExpenseType, UpdateType;
	bool flag = false;

	do
	{
		cout << endl;
		for(int i=0; i<5; i++)
		{
		cout << i+1 << " - " << ExpenseMenu[i] << endl;
		}
		cout << endl;
		cout << "\nPlease enter your choice : " ;
		cin >> choice;
		if (logs.category.size()==0)
		{
			cout<<"\nNo existing accounts found. Please create one first by choosing Option 4 in the menu below.\n"<<endl;
			return;
		}
		if(budget==0)
		{
			cout << "\nPlease set a budget first by choosing Option 3 in the menu below.\n";
			break;
		}
		switch(choice)
		{
			case 1:
				break;
			case 2:
				cout << "Which account do you want to deduct the expense from? : Enter the corresponding number.\n";
				for(int i=0; i<logs.category.size(); i++)
				{
					cout << i+1 << " - " << logs.category[i] << " HK$" << logs.value[i] << endl;
				}
				cin >> accountChoice;
				cout << "Please enter the type of expense : " ;
				cin >> 	NewExpenseType;
				cout << "Please enter the amount of expenditure : HK$" ;
				cin >> NewExpenseValue;
				if(NewExpenseValue > logs.value[accountChoice-1])
				{
					cout << "Insufficient Balance! Choose anoher account." << endl;
					for(int i=0; i<logs.category.size(); i++)
					{
						cout << i+1 << " - " << logs.category[i] << " HK$" << logs.value[i] << endl;
					}
					cin >> accountChoice;
				}
				for(int i=0; i<expense.category.size(); i++)
				{
					if(NewExpenseType==expense.category[i])
					{
						expense.value[i] = expense.value[i] + NewExpenseValue;
						flag = true;
						break;
					}
					flag = false;
				}
				if(flag==false)
				{
					expense.category.push_back(NewExpenseType);
					expense.value.push_back(NewExpenseValue);
				}
				for(int i=0; i<expense.category.size(); i++)
				{
					total = total + expense.value[i];
				}
				BudgetCheck(total);
				cout << "\nSuccessfully added new expense!\n" << endl;

				logs.value[accountChoice-1] = logs.value[accountChoice-1] - NewExpenseValue;
				total = 0;

				break;

			case 3:
				if(!expense.category.empty())
				{
					cout << "Which expense would you like to edit?" << endl;
					for(int i=0; i<expense.category.size(); i++)
					{
						cout << i+1 << " - " << expense.category[i] << " HK$" << expense.value[i] << endl;
					}
					cin >> editChoice;
					cout << "Please enter the edited type of expense : " ;
					cin >> 	UpdateType;
					cout << "Please enter the edited amount of expenditure : HK$" ;
					cin >> UpdateValue;
					expense.category[editChoice-1] = UpdateType;
					expense.value[editChoice-1] = UpdateValue;

					for(int i=0; i<expense.category.size(); i++)
					{
						total = total + expense.value[i];
					}
					BudgetCheck(total);

					cout << "\nSuccessfully edited the expense!\n" << endl;
				}
				else
				{
					cout << "\nNo expenses to edit!\n" << endl;
				}
				break;

			case 4:
				if(!expense.category.empty())
				{
					cout << "Which expense would you like to delete?" << endl;
					for(int i=0; i<expense.category.size(); i++)
					{
						cout << i+1 << " - " << expense.category[i] << " HK$" << expense.value[i] << endl;
					}
					cin >> deleteChoice;
					logs.value[accountChoice-1] = logs.value[accountChoice-1] + expense.value[deleteChoice-1];
					expense.category.erase(expense.category.begin()+deleteChoice-1);
					expense.value.erase(expense.value.begin()+deleteChoice-1);
					cout << "\nSuccessfully deleted the selected expense\n" << endl;
				}
				else
				{
					cout << "\nNo expenses to delete!\n" << endl;
				}
				break;

			case 5:
				for(int i=0; i<expense.category.size(); i++)
				{
					cout << i+1 << " - " << expense.category[i] << " HK$" << expense.value[i] << endl;
				}
				break;

			default:
				cout << "\nInvalid input\n" << endl;
		}
		if (choice!=5)
		{
			cout << "Current Expenses : " << endl;
			for(int i=0; i<expense.category.size(); i++)
			{
				cout << i+1 << " - " << expense.category[i] << " HK$" << expense.value[i] << endl;
			}
		}
	} while(choice!=1);
}


//Function to manage incomes : add/edit/delete/view
void AccountHolder::ManageIncomes()
{
	cout << "\n*************** Income Management ***************\n" << endl;
	string IncomeMenu[5] = { "Back to Main menu." , "Add a new income." , "Edit an income." , "Delete an income." , "View all incomes Category wise."};
	int choice, accountChoice, editChoice, deleteChoice;
	double NewIncomeValue, UpdateValue;
	string NewIncomeType, UpdateType;
	bool flag = false;

	do
	{
		cout << endl;
		for(int i=0; i<5; i++)
		{
		cout << i+1 << " - " << IncomeMenu[i] << endl;
		}
		cout << endl;
		cout << "\nPlease enter your choice : " ;
		cin >> choice;
		switch(choice)
		{
			case 1:
				break;

			case 2:
				cout << "Which account do you want to add income to? Enter the corresponding number. \n";
				for(int i=0; i<logs.category.size(); i++)
				{
					cout << i+1 << " - " << logs.category[i] << " HK$" << logs.value[i] << endl;
				}
				cin >> accountChoice;
				cout << "Please enter the type of income : " ;
				cin >> NewIncomeType;
				cout << "Please enter the amount of income : HK$" ;
				cin >> NewIncomeValue;
				for(int i=0; i<income.category.size(); i++)
				{
					if(NewIncomeType==income.category[i])
					{
						income.value[i]+=  NewIncomeValue;
						flag = true;
						break;
					}
					flag = false;
				}
				if(flag==false)
				{
					income.category.push_back(NewIncomeType);
					income.value.push_back(NewIncomeValue);
				}
				logs.value[accountChoice-1] = logs.value[accountChoice-1] + NewIncomeValue;
				cout << "\nSuccessfully added the income!\n" << endl;
				break;

			case 3:
				if(!income.category.empty())
				{
					cout << "Which income would you like to edit?" << endl;
					for(int i=0; i<income.category.size(); i++)
					{
						cout << i+1 << " - " << income.category[i] << " HK$" << income.value[i] << endl;
					}
					cin >> editChoice;
					logs.value[editChoice-1] = logs.value[editChoice-1] - income.value[editChoice-1];
					cout << "Please enter the edited type of income : " ;
					cin >> 	UpdateType;
					cout << "Please enter the edited amount of income : HK$" ;
					cin >> UpdateValue;
					income.category[editChoice-1] = UpdateType;
					income.value[editChoice-1] = UpdateValue;
					logs.value[editChoice-1] = logs.value[editChoice-1] + UpdateValue;
					cout << "\nSuccessfully edited the income!\n" << endl;
				}
				else
				{
					cout << "\nNo incomes to edit!\n" << endl;
				}
				break;

			case 4:
				if(!income.category.empty())
				{
					cout << "Which income would you like to delete?" << endl;
					for(int i=0; i<income.category.size(); i++)
					{
						cout << i+1 << " - " << income.category[i] << " HK$" << income.value[i] << endl;
					}
					cin >> deleteChoice;
					logs.value[accountChoice-1] = logs.value[accountChoice-1] - income.value[deleteChoice-1];
					income.category.erase(income.category.begin()+deleteChoice-1);
					income.value.erase(income.value.begin()+deleteChoice-1);
					cout << "\nSuccessfully deleted the selected income!\n" << endl;
				}
				else
				{
					cout << "\nNo incomes to delete!\n" << endl;
				}
				break;

			case 5:
				for(int i=0; i<income.category.size(); i++)
				{
					cout << i+1 << " - " << income.category[i] << " HK$" << income.value[i] << endl;
				}
				break;

			default:
				cout << "\nInvalid input\n" << endl;
		}

		cout << "\nCurrent Incomes : \n" << endl;
		for(int i=0; i<income.category.size(); i++)
		{
			cout << i+1 << " - " << income.category[i] << " HK$" << income.value[i] << endl;
		}
		cout<<"\n";

	} while(choice!=1);
}


//Function to manage budget : set a new budget/ check budget
void AccountHolder::ManageBudget()
{
	cout << "\n*************** Budget Management ***************\n" << endl;
	string BudgetMenu[3] = { "Back to main menu." , "Create a new budget" , "Check Budget"};
	int choice;
	double total, budgetLeft;

	do
	{
		cout << endl;
		for(int i=0; i<3; i++)
		{
		cout << i+1 << " - " << BudgetMenu[i] << endl;
		}
		cout << endl;
		cout << "\nPlease enter your choice : " ;
		cin >> choice;
		switch(choice)
		{
			case 1:
				break;

			case 2:
				cout << "Enter the new Budget : ";
				cin >> budget;
				cout << "\nBudget successfully changed!\n" << endl;
				break;

			case 3:
				for(int i=0; i<expense.category.size(); i++)
				{
					total = total + expense.value[i];
				}
				cout << "Budget : HK$" << budget << endl;
				cout << "Amount spent : HK$" << total << endl;
				cout << "Budget left : HK$" << total-budget << endl;
				budgetLeft = (total/budget)*100;
				cout << "Percentage of budget spent : " << budgetLeft << "%" << endl;
				total =0;
				break;

			default:
				cout << "\nInvalid Input!\n" << endl;
		}
	}while(choice!=1);
}


//Function to manage account logs : add/edit/delete/view
void AccountHolder::ManageAccountLogs()
{
	cout << "\n*************** Account Logs Management ***************\n" << endl;
	string AccountLogsMenu[5] =  { "Back to Main menu." , "Add a new account log." , "Edit an account log." , "Delete an account log." , "View all account logs Category wise."};
	int choice, editChoice, deleteChoice;
	double amount, editValue;
	string NewLog , editLog;

	do
	{
		cout << endl;
		for(int i=0; i<5; i++)
		{
		cout << i+1 << " - " << AccountLogsMenu[i] << endl;
		}
		cout << endl;
		cout << "\nPlease enter your choice : " ;
		cin >> choice;
		switch(choice)
		{
			case 1:
				break;

			case 2:
				cout << "Which account do you want to add? ";
				cin >> NewLog;
				cout << "Please enter the amount in the account : HK$" ;
				cin >> amount;
				logs.category.push_back(NewLog);
				logs.value.push_back(amount);
				cout << "\nSuccessfully added a new account log!\n" << endl;
				break;

			case 3:
				if(!logs.category.empty())
				{
					cout << "Which acount log would you like to edit? Enter the corresponding number.\n" << endl;
					for(int i=0; i<logs.category.size(); i++)
					{
						cout << i+1 << " - " << logs.category[i] << " HK$" << logs.value[i] << endl;
					}
					cin >> editChoice;
					cout << "Please enter the edited type of account log : " ;
					cin >> 	editLog;
					cout << "Please enter the edited amount of income : HK$" ;
					cin >> editValue;
					logs.category[editChoice-1] = editLog;
					logs.value[editChoice-1] = editValue;
					cout << "\nSuccessfully edited the account log!\n" << endl;
				}
				else
				{
					cout << "\nNo account logs to edit!\n" << endl;
				}
				break;

			case 4:
				if(!logs.category.empty())
				{
					cout << "Which account log would you like to delete? Enter the corresponding number. \n" << endl;
					for(int i=0; i<logs.category.size(); i++)
					{
						cout << i+1 << " - " << logs.category[i] << " HK$" << logs.value[i] << endl;
					}
					cin >> deleteChoice;
					logs.category.erase(expense.category.begin()+deleteChoice-1);
					logs.value.erase(expense.value.begin()+deleteChoice-1);
					cout << "\nSuccessfully deleted the selected income!\n" << endl;
				}
				else
				{
					cout << "\nNo incomes to delete!\n" << endl;
				}
				break;

			case 5:
				cout<<"\n";
				for(int i=0; i<logs.category.size(); i++)
				{
					cout << i+1 << " - " << logs.category[i] << " HK$" << logs.value[i] << endl;
				}
				cout<<"\n";
				break;

			default:
				cout << "\nInvalid input\n" << endl;
		}
	}while(choice!=1);
}


//Function to Transfer amount from one account to another
void AccountHolder::TransferAmount()
{
	int from, to;
	double amount;
	cout << "\n*************** Transfer Money ***************\n" << endl;
	if(logs.category.size()<2)
	{
		cout << "\nMinimum 2 accounts required to transfer money. Please create another account first.\n" << endl;
	}
	else
	{
		cout << "Existing account logs : " << endl;
		for(int i=0; i<logs.category.size(); i++)
		{
			cout << i+1 << " - " << logs.category[i] << " HK$" << logs.value[i] << endl;
		}
		cout << "Which account do you want to transfer from? Enter the corresponding number. \n";
		cin >> from;
		cout << "Which account do you want to transfer to? Enter the corresponding number. \n" ;
		cin >> to;
		cout << "Amount to be transfered : HK$" ;
		cin >> amount;
		logs.value[from-1] = logs.value[from-1] - amount;
		logs.value[to-1] = logs.value[to-1] + amount;
		cout << "\nSuccessfully transfered amount!\n" << endl;

	}
}


//Function to view overall statistics of income, expenses, account logs and budget
void AccountHolder::ViewStats()
{
	cout << "\n*************** View Overall Statistics ***************\n" << endl;
	cout << "\n Income: \n" ;
	double incomes = 0;
	for(int i=0; i<income.category.size(); i++)
	{
		cout << i+1 << " - " << income.category[i] << " HK$" << income.value[i] << endl;
		incomes = incomes + income.value[i];
	}
	cout << "\n Total Income : HK$" << incomes << endl;
	cout << "\n\n Expenses: \n";
	double expenses=0;
	for(int i=0; i<expense.category.size(); i++)
	{
		cout << i+1 << " - " << expense.category[i] << " HK$" << expense.value[i] << endl;
		expenses = expenses + expense.value[i];
	}
	cout << "\n Total Expense : HK$" << expenses << endl;
	cout << "\n\n Account logs \n";
	for(int i=0; i<logs.category.size(); i++)
	{
		cout << i+1 << " - " << logs.category[i] << " HK$" << logs.value[i] << endl;
	}
	cout << "\n\nBudget : ";
	double total=0 , budgetSpent=0;
	for(int i=0; i<expense.category.size(); i++)
	{
		total = total + expense.value[i];
	}
	cout << "Budget left : HK$" << budget-total << endl;
	budgetSpent = (total/budget)*100;
	cout << "Percentage of budget spent : " << budgetSpent << "%" << endl;
}


//Function to display the main menue with different fucntions
void AccountHolder::MainMenu()
{
	cout << "\nWelcome to your Accounts Management System" << endl;
	cout << "************************************************" << endl;
	cout << "1. Manage Expenses." << endl;
	cout << "2. Manage Incomes." << endl;
	cout << "3. Manage Budget." << endl;
	cout << "4. Manage Account Logs." << endl;
	cout << "5. Transfer money." << endl;
	cout << "6. View Overall Statistics." << endl;
	cout << "7. Exit" << endl;
	cout << "***********************************************\n" << endl;
}


//Function to coordinate user input
void AccountHolder::ManageCommands(int choice_of_action)
{
	switch(choice_of_action)
	{
		case 1:
			ManageExpenses();
			break;
		case 2:
			ManageIncomes();
			break;
		case 3:
			ManageBudget();
			break;
		case 4:
			ManageAccountLogs();
			break;
		case 5:
			TransferAmount();
			break;
		case 6:
			ViewStats();
			break;
		case 7:
			cout << "Thank you for using Accounts Management System!" << endl;
			break;

		default:
			cout << "Invalid Input! Please Try again" << endl;

	}
}
