#include <iostream>
#include <string>
#include <fstream>
#include "AccountHolder.h"

using namespace std;
void AccountHolder::readFromFile()
{
  int i,j;
  string line, group;
  double amount;
  ifstream fin;
  fin.open((username+".txt").c_str());
  if (fin.fail())
  {
    cout << "Failed to open "<<username <<".txt"<< endl;
    return;
  }
  j = 0;
  getline(fin,line);
  for (i = 0; i<line.length();i++)
  {
    if (line[i]==' ')
    {
      group = line.substr(j,(i-j));
      income.category.push_back(group);
      j=i+1;
    }
  }
  j = 0;
  getline(fin,line);
  for (i = 0; i<line.length();i++)
  {
    if (line[i]==' ')
    {
      group = line.substr(j,(i-j));
      income.value.push_back(stof(group));
      j=i+1;
    }
  }
  fin.ignore();
  j = 0;
  getline(fin,line);
  for (i = 0; i<line.length();i++)
  {
    if (line[i]==' ')
    {
      group = line.substr(j,(i-j));
      expense.category.push_back(group);
      j=i+1;
    }
  }
  j = 0;
  getline(fin,line);
  for (i = 0; i<line.length();i++)
  {
    if (line[i]==' ')
    {
      group = line.substr(j,(i-j));
      expense.value.push_back(stof(group));
      j=i+1;
    }
  }
  fin.ignore();
  j = 0;
  getline(fin,line);
  for (i = 0; i<line.length();i++)
  {
    if (line[i]==' ')
    {
      group = line.substr(j,(i-j));
      logs.category.push_back(group);
      j=i+1;
    }
  }
  j = 0;
  getline(fin,line);
  for (i = 0; i<line.length();i++)
  {
    if (line[i]==' ')
    {
      group = line.substr(j,(i-j));
      logs.value.push_back(stof(group));
      j=i+1;
    }
  }
  fin.ignore();
  fin >> budget;
  fin.close();
}
