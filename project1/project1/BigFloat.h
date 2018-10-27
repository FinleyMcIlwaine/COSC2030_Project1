// BigFloat.h
// Finley McIlwaine
// COSC2030 Project 1
// 10.26.2018

#pragma once

#ifndef BIG_FLOAT
#define BIG_FLOAT

#include <iostream>
using std::ostream;

class BigFloat
{
public:
	// Default constructor
	BigFloat() { currentSum = 0; overflowCount = 0; }

	// Overloaded operators.
	// + for member
	BigFloat operator + (const BigFloat &rhs) const;
	// + operator overload for non-member float
	BigFloat operator + (const float &rhFloat) const;
	// = float
	void operator = (const float &rhFloat);
	// < float
	bool operator < (const float &rhFloat) const;
	// > float
	bool operator > (const float &rhFloat) const;
	// == float
	bool operator == (const float &rhFloat) const;

	// Accessor functions
	int getOverflowCount() const { return overflowCount; }
	float getCurrentSum() const  { return currentSum; }

	// Setter functions
	// Sets current sum value
	void setSum(const float &rhFloat);
	// Sets overflow counter
	void setOverflowCounter(const int &num);

private:
	// Private sum and overflow count variables
	float currentSum;
	int overflowCount;
};

// Stream insertion operator overload.
ostream& operator << (ostream& outStream, const BigFloat& output);

#endif // !BIG_FLOAT

