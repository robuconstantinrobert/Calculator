#pragma once
#pragma warning (disable:4996)
#include <iostream>
#include <string>
#include <fstream>

class Functions
{
private:

	char* functionName;
	int noSavedItems;
	int* savedItems;
	const double functionDate;
	static int IDFunction;

	double a;
	double b;


public:

	Functions() :functionDate(1999)
	{
		this->functionName = new char[strlen("unknown") + 1];
		strcpy(this->functionName, "unknown");
		this->noSavedItems = 0;
		this->savedItems = nullptr;
		this->a = 0;
		this->b = 0;
	}

	Functions(const char* functionName, int noSavedItems, int* savedItems, double a, double b, double year) :functionDate(year)
	{
		if (strlen(functionName) > 1)
		{
			this->functionName = new char[strlen(functionName) + 1];
			strcpy(this->functionName, functionName);
		}
		else
		{
			this->functionName = new char[strlen("unknown") + 1];
			strcpy(this->functionName, "unknown");
		}

		if (noSavedItems > 0 && savedItems != nullptr)
		{
			this->noSavedItems = noSavedItems;
			this->savedItems = new int[noSavedItems];
			for (int i = 0; i < noSavedItems; i++)
			{
				if (savedItems[i] >= 1 && savedItems[i] <= 15)
				{
					this->savedItems[i] = savedItems[i];
				}
				else
				{
					this->savedItems[i] = 0;
				}
			}
		}
		else
		{
			this->noSavedItems = 0;
			this->savedItems = nullptr;
		}
		this->a = a;
		this->b = b;

	}

	~Functions()
	{
		delete[] this->functionName;
		delete[] this->savedItems;
	}

	Functions(const Functions& source) :functionDate(source.functionDate)
	{
		this->a = source.a;
		this->b = source.b;
		this->functionName = new char[strlen(source.functionName) + 1];
		strcpy(this->functionName, source.functionName);
		this->noSavedItems = source.noSavedItems;
		this->savedItems = new int[source.noSavedItems];
		for (int i = 0; i < source.noSavedItems; i++)
		{
			this->savedItems[i] = source.savedItems[i];
		}
	}

	Functions& operator= (const Functions& source)
	{
		delete[] this->functionName;
		delete[] this->savedItems;

		this->a = source.a;
		this->b = source.b;
		this->functionName = new char[strlen(source.functionName) + 1];
		strcpy(this->functionName, source.functionName);
		this->noSavedItems = source.noSavedItems;
		this->savedItems = new int[source.noSavedItems];
		for (int i = 0; i < source.noSavedItems; i++)
		{
			this->savedItems[i] = source.savedItems[i];
		}

		return *this;
	}

	static void setIDfunction(int x)
	{
		if (x > 0 && x <= 15)
		{
			Functions::IDFunction = x;
		}
	}

	static int getIDfunction()
	{
		return Functions::IDFunction;
	}

	void setFunctionName(const char* fname)
	{
		if (strlen(fname) > 1)
		{
			delete[] this->functionName;
			this->functionName = new char[strlen(fname) + 1];
			strcpy(this->functionName, fname);
		}
	}

	void setNoSavedItems(int noSitems)
	{
		if (noSitems >= 1)
		{
			this->noSavedItems = noSitems;
		}
	}

	void setSavedItems(int noSitems, int* savedItems)
	{
		if (noSitems >= 1 && savedItems != nullptr)
		{
			delete[] this->savedItems;

			this->noSavedItems = noSitems;
			this->savedItems = new int[noSitems];
			for (int i = 0; i < noSitems; i++)
			{
				if (savedItems[i] >= 1 && savedItems[i] <= 15)
				{
					this->savedItems[i] = savedItems[i];
				}
				else
				{
					this->savedItems[i] = 0;
				}
			}
		}
	}

	void setA(double a)
	{
		if (a >= 0)
		{
			this->a = a;
		}
	}

	void setB(double b)
	{
		if (b >= 0)
		{
			this->b = b;
		}
	}

	double getA()
	{
		return this->a;
	}

	double getB()
	{
		return this->b;
	}

	char* getFunctionName()
	{
		return this->functionName;
	}

	int getNoSavedItems()
	{
		return this->noSavedItems;
	}

	int* getSavedItems()
	{
		return this->savedItems;
	}

	double additionFunction(double a, double b)
	{
		return a + b;

	}

	double substractionFunction(double a, double b)
	{

		return a - b;
	}

	double multiplyFunction(double a, double b)
	{
		return a * b;
	}

	double divisionFunction(double a, double b)
	{
		if (b == 0)
		{
			cout << "Error";
			return 0;
		}
		else
		{
			return a / b;
		}

	}

	double getFunctionDate()
	{
		return this->functionDate;
	}

	double powerFunction(double a, double b)
	{

		for (int i = 1; i < b; i++)
		{
			a = a * a;
		}

		return a;
	}

	double nthRootFunction(double a, double b)
	{
		double x1 = rand() % 10;
		double x2;
		double delimiter = INT_MAX;
		double epsilon = 1e-3;
		while (delimiter > epsilon)
		{
			x2 = ((b - 1.0) * x1 + a / powerFunction(x1, b - 1)) / b;
			delimiter = abs(x2 - x1);
			x1 = x2;
		}
		a = x2;
		return a;
	}

	friend   ostream& operator<< (ostream& out, Functions source);

	friend  istream& operator>> (istream& in, Functions& source);


	explicit operator int()
	{
		return noSavedItems;
	}

	Functions& operator+= (const char* funcName)
	{
		char buffer[500];
		strcpy(buffer, this->functionName);
		delete[] this->functionName;
		strcat(buffer, funcName);
		this->functionName = new char[strlen(buffer) + 1];
		strcpy(this->functionName, buffer);
		return *this;
	}

	Functions& operator+= (double a)
	{
		this->a += a;
		return *this;
	}

	friend   ofstream& operator<< (ofstream& out, Functions source)
	{
		int nameDimension = strlen(source.functionName) + 1;
		out.write((char*)&nameDimension, sizeof(int));
		out.write(source.functionName, nameDimension);


		out.write((char*)&source.noSavedItems, sizeof(int));
		for (int i = 0; i < source.noSavedItems; i++)
		{
			out.write((char*)&source.savedItems[i], sizeof(int));
		}

		out.write((char*)&source.a, 8);
		out.write((char*)&source.b, 8);

		return out;
	}


	friend  ifstream& operator>> (ifstream& in, Functions& source)
	{
		int nameDimension;
		in.read((char*)&nameDimension, sizeof(int));
		delete[] source.functionName;
		source.functionName = new char[nameDimension];
		in.read(source.functionName, nameDimension);

		in.read((char*)&source.noSavedItems, sizeof(int));
		delete[] source.savedItems;
		source.savedItems = new int[source.noSavedItems];
		for (int i = 0; i < source.noSavedItems; i++)
		{
			in.read((char*)&source.savedItems[i], sizeof(int));
		}

		in.read((char*)&source.a, 8);
		in.read((char*)&source.b, 8);

		return in;
	}

	void saveTxt(ofstream& out)
	{
		out << this->functionName << endl;

		out << this->noSavedItems << endl;
		for (int i = 0; i < this->noSavedItems; i++)
		{
			out << this->savedItems[i] << endl;
		}

		out << this->a << endl;
		out << this->b << endl;
	}

	void takeTxt(ifstream& in)
	{
		in >> this->a;
		in >> this->b;
		in.ignore();
		char bufferName[500];
		in.getline(bufferName, 499);
		delete[]this->functionName;
		this->functionName = new char[strlen(bufferName) + 1];
		strcpy(this->functionName, bufferName);

		in >> this->noSavedItems;
		delete[] this->savedItems;
		this->savedItems = new int[this->noSavedItems];
		for (int i = 0; i < this->noSavedItems; i++)
		{
			in >> this->savedItems[i];
		}
	}

};

