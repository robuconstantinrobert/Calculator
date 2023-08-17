#pragma once
#define SIZE 100


template <typename T>
class Stack
{
private:
	T stack[SIZE];
	int top;
public:

	Stack()
	{
		top = -1;

	}

	~Stack()
	{

	}

	int empty()
	{
		if (top == -1)
			return 1;
		else
			return 0;
	}

	int isFull()
	{
		if (top == (SIZE - 1))
			return 1;
		else
			return 0;
	}

	void push(T x)
	{

		if (isFull())
		{
			return;
		}
		else {
			++top;
			stack[top] = x;
		}
	}

	void pop()
	{
		if (top < 0)
		{
			cout << "underflow";
		}
		else
		{
			top--;

		}
	}

	T peekValue()
	{
		if (top < 0)
		{
			return -1;
		}
		else
		{
			return  stack[top];
		}
	}
	T peekOperator()
	{
		if (top < 0)
		{
			return 0;
		}
		else
		{
			return  stack[top];
		}
	}


	void setTop(int TOP)
	{
		if (TOP >= 0)
		{
			this->top = TOP;
		}

	}

	int getTop()
	{
		return this->top;
	}


	Stack& operator++()
	{
		this->top += 2;
		return *this;
	}

	bool operator!()
	{
		if (this->top = 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};