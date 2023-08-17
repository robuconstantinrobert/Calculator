#include <iostream>
#include <string>
#include <fstream>
#define SIZE 100
using namespace std;
#pragma warning (disable:4996)
#include "Functions.h"
#include "Methods.h"
#include "Stack.h"
#include "Calculator.h"

ostream& operator<< (ostream& out, Functions source)
{
	out << "Function Name: " << source.functionName << endl;
	out << "Number of saved items: " << source.noSavedItems << endl;
	for (int i = 0; i < source.noSavedItems; i++) {
		out << "Saved Items: " << i + 1 << source.savedItems[i] << endl;
	}
	out << "Number a: " << source.a << endl;
	out << "Number b: " << source.b << endl;

	return out;
}

istream& operator>> (istream& in, Functions& source)
{
	cout << "Give input for function name:";
	char bufferName[500];
	in >> bufferName;
	source.setFunctionName(bufferName);

	cout << "Give input for number of saved items";
	int nrAux;
	in >> nrAux;
	if (nrAux > 0)
	{
		source.noSavedItems = nrAux;
		delete[] source.savedItems;
		source.savedItems = new int[nrAux];
		for (int i = 0; i < nrAux; i++)
		{
			cout << "Give input for the items that you want to save:" << i + 1;
			int auxSavedItem;
			in >> auxSavedItem;
			if (auxSavedItem >= 1 && auxSavedItem <= 15)
			{
				source.savedItems[i] = auxSavedItem;
			}
			else
			{
				source.savedItems[i] = 0;
			}
		}
	}

	cout << "Give input for number 1:";
	double a1;
	in >> a1;
	source.setA(a1);

	cout << "Give input for number 2:";
	double b1;
	in >> b1;
	source.setB(b1);


	return in;
}
int Functions::IDFunction = 1;


ostream& operator<< (ostream& out, Calculator source)
{
	out << "Index: " << source.i << endl;
	for (int i = 0; i < source.i; i++)
	{
		out << "The input is: " << source.character << endl;
	}
	return out;
}

istream& operator>> (istream& in, Calculator& source)
{
	cout << "Enter the string: ";
	string aux;
	in >> aux;
	source.setCharacter(aux);

	cout << "Enter index: ";
	int x;
	in >> x;
	source.setCounter(x);
	return in;
}


int main()
{

	Calculator V1;
	Functions V2;
	cout << "Calculator Menu \n";
	cout << "=================================== \n";
	cout << "Choose an action: \n";
	cout << "1.Solve equations and save them in a binary file \n";
	cout << "2.Solve equations from a text file \n";
	cout << "3.Save the result \n";
	cout << "4.Solve an equation \n";
	cout << "5.Give the solved equation a description so others can solve it \n";
	cout << "6.Exit \n";
	cout << "Press a digit from 1 to 7 \n";
	int action = 0;
	cin >> action;
	switch (action)
	{


	case 1:
	{
		ofstream file;
		file.open("File.bin", ios::app | ios::binary);
		if (file.is_open()) {
			cout << "Number of equations: ";
			int noEquations;
			cin >> noEquations;
			for (int i = 0; i < noEquations; i++)
			{
				cout << i + 1 << ". Input equation: " << endl;
				string equation = "";
				cin >> equation;
				V1.setCharacter(equation);
				cout << V1.check() << endl;
				V1.saveTxt(file);
				ofstream file;
			}
			file.close();
		}
	}
	break;


	case 2:
	{
		ifstream infile;
		infile.open("File.txt", ios::out);
		if (infile.is_open())
		{

			string equations;
			while (!infile.eof())
			{
				infile >> equations;
				V1.setCharacter(equations);
				cout << V1.check() << endl;


			}

			infile.close();

		}
	}
	break;


	case 3:
	{
		char c;
		ifstream ifile("File.txt");
		ofstream ofile("Save.txt");
		while (ifile.get(c))
		{
			ofile.put(c);
		}
		ifile.close();
		ofile.close();

	}
	break;


	case 4:
	{

		ofstream file1;
		file1.open("Save.txt", ios::in);
		if (file1.is_open()) {
			cout << "Number of equations: ";
			int noEquations;
			cin >> noEquations;
			for (int i = 0; i < noEquations; i++)
			{
				cout << i + 1 << ". Input equation: " << endl;
				string equation = "";
				cin >> equation;
				V1.setCharacter(equation);
				cout << V1.check() << endl;
				V1.saveTxt(file1);
				ofstream file1;
			}
			file1.close();
		}

	}
	break;


	case 5:
	{
		ofstream file2;
		file2.open("ProblemDescription.txt", ios::app);
		if (file2.is_open())
		{

			cout << "Give a name for the problem \n";

			string problemName;
			char* problemName1 = new char[problemName.length() + 1];
			strcpy(problemName1, problemName.c_str());
			cin >> problemName1;
			V2.setFunctionName(problemName1);
			file2 << V2.getFunctionName();
		}
		file2.close();
	}
	break;


	case 6:
	{
		cout << "\nHave a nice day!";
		exit(0);
	}
	break;

defalut:
	cout << "\nInvalid section";

	cout << "\nChoose again!";
	cin >> action;
	}
	return 0;
}
