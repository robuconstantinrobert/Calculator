#pragma once

class Calculator :Methods, Functions
{
private:
	Stack<double>values[SIZE];
	Stack<char>ops[SIZE];
	string character;
	int i;
public:

	Calculator()
	{
		string character = "na";
		int i = 0;
	}

	Calculator(string character, int i)
	{
		this->character = character;
		this->i = i;
	}

	Calculator(const Calculator& source)
	{
		this->character = source.character;
		this->i = source.i;
	}

	~Calculator()
	{

	}

	Calculator& operator= (const Calculator& source)
	{
		this->character = source.character;
		this->i = source.i;

		return *this;
	}

	int priority(char op) {
		if (op == '+' || op == '-')
			return 1;
		if (op == '*' || op == '/')
			return 2;
		if (op == '^' || op == '#')
			return 3;
		return 0;
	}


	double applyOperators(double a, double b, char op) {
		switch (op) {
		case '+': return Functions::additionFunction(a, b);
		case '-': return Functions::substractionFunction(a, b);
		case '*': return Functions::multiplyFunction(a, b);
		case '/': return Functions::divisionFunction(a, b);
		case '^': return Functions::powerFunction(a, b);
		case '#': return Functions::nthRootFunction(a, b);
		}
	}



	double check()
	{
		for (i = 0; i < character.length(); i++)
		{
			if (character[i] == ' ')
				continue;


			else if (character[i] == '(' || character[i] == '[')
			{
				ops->push(character[i]);
			}

			else if (isdigit(character[i]))
			{


				double val = stod(character.substr(i));
				while (i < character.length() && (isdigit(character[i]) || character[i] == '.'))
				{
					i++;
				}

				values->push(val);
				i--;
			}

			else if (character[i] == ')' || character[i] == ']')
			{
				while (!ops->empty() && (ops->peekOperator() != '(' && ops->peekOperator() != '['))
				{
					double val2 = values->peekValue();
					values->pop();

					double val1 = values->peekValue();
					values->pop();

					char op = ops->peekOperator();
					ops->pop();

					values->push(applyOperators(val1, val2, op));
				}

				if (!ops->empty())
					ops->pop();

			}

			else if (i == 0 && character[i] == '-')
			{
				values->push(0);
				ops->push('-');
			}

			else
			{
				while (!ops->empty() && priority(ops->peekOperator())
					>= priority(character[i])) {
					double val2 = values->peekValue();
					values->pop();

					double val1 = values->peekValue();
					values->pop();

					char op = ops->peekOperator();
					ops->pop();

					values->push(applyOperators(val1, val2, op));
				}
				ops->push(character[i]);
			}
		}

		while (!ops->empty()) {
			double val2 = values->peekValue();
			values->pop();

			double val1 = values->peekValue();
			values->pop();

			char op = ops->peekOperator();
			ops->pop();

			values->push(applyOperators(val1, val2, op));
		}

		return values->peekValue();
	}

	void setCharacter(string character)
	{
		this->character = character;
	}

	void setCounter(int i)
	{
		this->i = i;
	}


	string getCharacter()
	{
		return this->character;
	}

	int getCounter()
	{
		return this->i;
	}

	bool operator>(Calculator source)
	{
		if (this->i > source.i)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Calculator operator+(int x)
	{
		Calculator c(*this);
		c.i += x;
		return c;
	}


	friend   ostream& operator<< (ostream& out, Calculator source);

	friend  istream& operator>> (istream& in, Calculator& source);

	friend   ofstream& operator<< (ofstream& out, Calculator source)
	{

		out.write((char*)&source.i, sizeof(int));
		out.write((char*)&source.character, sizeof(string));


		return out;
	}

	friend ifstream& operator<< (ifstream& in, Calculator source)
	{
		in >> source.i;
		in >> source.character;

		return in;
	}

	void saveTxt(ofstream& out)
	{
		out << this->character << endl;
		out << this->i << endl;
	}

	void takeTxt(ifstream& in)
	{
		in >> this->i;
		in >> this->character;
	}

};