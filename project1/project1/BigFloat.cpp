// BigFloat.h
// Finley McIlwaine
// COSC2030 Project 1
// 10.26.2018

#include "pch.h"
#include "BigFloat.h"
#include <iostream>

using std::ostream;
using std::cout;
using std::endl;

// + operator overload for non-member float
BigFloat BigFloat::operator + (const float &rhfloat) const {
	// Initialize a max float constant
	const float MAX_FLOAT = std::numeric_limits<float>::max();

	// Declare result object
	BigFloat result;
	result.setOverflowCounter(this->getOverflowCount());

	// Check if sum will overflow
	if (this->currentSum > MAX_FLOAT - rhfloat) {
		// Overflow would occur
		// Increment overflow count
		result.overflowCount = this->overflowCount + 1;

		// Calculate new sum
		result.currentSum = -1 * (MAX_FLOAT - this->currentSum - rhfloat);
	}
	else {
		result.currentSum = this->currentSum + rhfloat;
	}
	// return result object
	return result;
}

// + operator overload for member
BigFloat BigFloat::operator + (const BigFloat &rhs) const {
	// Initialize a max float constant
	const float MAX_FLOAT = std::numeric_limits<float>::max();

	// Declare result object
	BigFloat result;

	// Check if sum will overflow
	if (this->currentSum > MAX_FLOAT - rhs.currentSum) {
		// Overflow would occur
		// Increment overflow count
		result.overflowCount = this->overflowCount + 1;

		// Calculate new sum
		result.currentSum = -1 * (MAX_FLOAT - this->currentSum - rhs.currentSum);
	}
	else {
		result.currentSum = this->currentSum + rhs.currentSum;
	}
	// return result object
	return result;
}

// Output stream insertion operator overload
ostream& operator << (ostream& outStream, const BigFloat& output) {
	// Initialize a max float constant
	const float MAX_FLOAT = std::numeric_limits<float>::max();

	// If the result has overflown:
	if (output.getOverflowCount() > 0) {
		// Display overflow count and current sum
		outStream << output.getCurrentSum() << " + " << output.getOverflowCount() << " * " << MAX_FLOAT;
	}
	else {
		// No overflow, just display sum
		outStream << output.getCurrentSum();
	}
	return outStream;
}

// = float operator
void BigFloat::operator = (const float &rhFloat) {
	// set value
	this->setSum(rhFloat);
}

// < float operator
bool BigFloat::operator < (const float &rhFloat) const {
	// Always false if bigfloat has overflown
	if (this->overflowCount > 0) { return false; }
	// If no overflow, test sum
	return (this->currentSum < rhFloat);
}

// > float operator
bool BigFloat::operator > (const float &rhFloat) const {
	// Always true if bigfloat has overflown
	if (this->overflowCount > 0) { return true; }
	// If no overflow, test sum
	return (this->currentSum > rhFloat);
}

// > float operator
bool BigFloat::operator == (const float &rhFloat) const {
	// Always false if bigfloat has overflown
	if (this->overflowCount > 0) { return false; }
	// If no overflow, test sum
	return (this->currentSum == rhFloat);
}

// SETTER FUNCTIONS:
// Sets current sum value
void BigFloat::setSum(const float &rhFloat) {
	// Set value
	currentSum = rhFloat;
}
// Sets overflow counter value
void BigFloat::setOverflowCounter(const int &num) {
	overflowCount = num;
}