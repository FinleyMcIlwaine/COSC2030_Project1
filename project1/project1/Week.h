// Week.h
// Finley McIlwaine
// COSC2030 Project 1
// 10.26.18

#pragma once
#ifndef WEEK
#define WEEK

#include "Day.h"
#include "BigFloat.h"

class Week
{
public:
	// Default constructor
	Week();

	// Accessor methods
	BigFloat getSum() { return totSum; }
	BigFloat getMax() { return totMax; }
	BigFloat getMin() { return totMin; }
	int getCount() { return totEntriesCount; }
	int getBiggestDelta();

	// Summary method
	void showSummary();

	// Set and increment methods
	void enterBloodSugar(const float &bloodSug);
	void newDay(Week* &thisWeek);

	// Public day and week variables
	Day* currentDay;
	Day* firstDay;
	Week* lastWeek;
	Week* nextWeek;

private:
	// Private member variables
	BigFloat totSum, totMax, totMin;
	int totEntriesCount;
	int dayCount;
};


#endif // !DAY_LIST

