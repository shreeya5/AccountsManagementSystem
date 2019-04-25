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

void AccountHolder::writeToFile()
{
  int i;
  ofstream fout;
  fout.open((username+".txt").c_str());
  for (i=0;i<income.category.size();i++)
  {
    fout << income.category[i]<<" ";
  }
  fout<<endl;
  for (i=0;i<income.value.size();i++)
  {
    fout << income.value[i]<<" ";
  }
  fout<<endl;
  fout<<endl;
  for (i=0;i<expense.category.size();i++)
  {
    fout << expense.category[i]<<" ";
  }
  fout<<endl;
  for (i=0;i<expense.value.size();i++)
  {
    fout << expense.value[i]<<" ";
  }
  fout<<endl;
  fout<<endl;
  for (i=0;i<logs.category.size();i++)
  {
    fout << logs.category[i]<<" ";
  }
  fout<<endl;
  for (i=0;i<logs.value.size();i++)
  {
    fout << logs.value[i]<<" ";
  }
  fout<<endl;
  fout<<endl;
  fout<<budget;
  fout.close();
}
