// day.h
// Finley McIlwaine
// COSC2030 Project 1
// 10.26.18

#pragma once
#ifndef DAY_H
#define DAY_H

#include "BigFloat.h"

class Day
{
public:
	// Default contrsuctor
	Day() { daySum = 0; dayMax = 0; dayMin = 0; entriesCount = 0; next = nullptr; }

	// Accessor methods
	BigFloat getSum() { return daySum; }
	BigFloat getMax() { return dayMax; }
	BigFloat getMin() { return dayMin; }
	int getCount() { return entriesCount; }
	int getDelta() { return (last != nullptr) ? (entriesCount - last->entriesCount) : 0; }

	// Entry method
	void enterBloodSugar(const float &bloodSug);

	// Summary method
	void showSummary();

	// Public last/next day ptrs
	Day* next;
	Day* last;

private:
	// Private member variables
	BigFloat daySum, dayMax, dayMin;
	int entriesCount;
};

#endif // !DAY_H

