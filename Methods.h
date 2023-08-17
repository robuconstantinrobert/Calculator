#pragma once

class Methods
{
private:

public:

	virtual int priority(char op) = 0;

	virtual double applyOperators(double a, double b, char op) = 0;

	virtual double check() = 0;


};