// Week.h
// Finley McIlwaine
// COSC2030 Project 1
// 10.26.18

#include "pch.h"
#include <iostream>
#include "Week.h"
#include "day.h"

using std::cout;
using std::endl;

// Default constructor definition
Week::Week() {
	// Initialize sum, min, max, count, and dayCount
	// variables for week.
	totSum = 0;
	totMax = 0;
	totMin = 0;
	totEntriesCount = 0;
	dayCount = 1;

	// Initialize first day
	currentDay = new Day;
	currentDay->next = nullptr;
	currentDay->last = nullptr;
	firstDay = currentDay;
	
	// Initialize pointers to previous week and next week
	Week* lastweek = nullptr;
	Week* nextWeek = nullptr;
}

// Returns the day with the biggest delta in
// readings count
int Week::getBiggestDelta() {
	// Set test at beginning of week
	Day* test = firstDay;

	// Initialize day index, count, and max delta variables
	int dayNum = 1, count = 1;
	int maxDelta = 0;

	// If only 1 day into week and entried have been made, return 1.
	// If one day into week and no entries, return 0.
	if (test->next == nullptr && !(test->getSum() == 0)) { return 1; }
	else if (test->next == nullptr) { return 0; }

	// Loop through week
	while (test != nullptr && count <= 7)
	{
		// Save day that has greatest delta
		if (maxDelta < std::abs(test->getDelta())) {
			dayNum = count;
			maxDelta = std::abs(test->getDelta());
		}
		// Increment to next day
		count++;
		test = test->next;
	}

	// return day index with greatest delta
	return dayNum;
}

// This function logs the user's pre-validated blood sugar
// input. The data is stored within the current week
// and day object.
void Week::enterBloodSugar(const float &bloodSugar) {
	// Send the reading to the day object
	currentDay->enterBloodSugar(bloodSugar);

	// Add reading to weekly sum OVERFLOW CHECK HERE
	totSum = totSum + bloodSugar;

	// Increment readings count
	totEntriesCount++;

	// Reset max and min variables if appropriate
	if (totMax < bloodSugar) { totMax = bloodSugar; }
	if (totMin == 0 || totMin > bloodSugar) { totMin = bloodSugar; }
}

// This function moves the application to a new day and,
// if appropriate, a new week.
void Week::newDay(Week* &thisWeek) {
	// If at the end of the current week:
	if (dayCount == 7) {
		// Create a new week object
		Week* newWeek = new Week;

		// Set the next week ptr of the new week to null
		newWeek->nextWeek = nullptr;

		// Set the last week ptr of the new week to the
		// current week
		newWeek->lastWeek = thisWeek;

		// Set the current week's next week ptr to the new week
		thisWeek->nextWeek = newWeek;

		// Delete the current week's last week
		delete[] thisWeek->lastWeek;

		// Set the current week to the new week
		thisWeek = newWeek;

		// Output new week message to user and reset day counter
		cout << endl << "                      *** NEW WEEK ***                      " << endl;
		dayCount = 0;
	}
	// Make a new day object
	Day* newDay = new Day;

	// Set the new day's tomorrow ptr to null
	newDay->next = nullptr;

	// Set the new day's yesterday ptr to the current day
	newDay->last = currentDay;

	// Set the current day's tomorrow ptr to the new day
	currentDay->next = newDay;

	// Set the current day to the new day
	currentDay = newDay;

	// Increment our day count
	dayCount++;

	// Display new day message to user.
	cout << endl << "      ***  You are now on day " << dayCount << " of the current week.  ***   \n" << endl;
}

// Shows the weekly summary of blood sugar statistics. If the previous
// has data, it displays the current week and the previous week.
// Otherwise, just the previous week.
void Week::showSummary() {
	cout << " ___________________________________________________________ " << endl;
	cout << "|         ~+~+~+~ WEEKLY BLOOD SUGAR SUMMARY ~+~+~+~        |" << endl;
	cout << "|___________________________________________________________|" << endl;
	cout << "                                                             " << endl;
	cout << "  This week's SUM:                   " << this->getSum() << endl;
	cout << "                                                             " << endl;
	cout << "  This week's MAX:                   " << this->getMax() << endl;
	cout << "                                                             " << endl;
	cout << "  This week's MIN:                   " << this->getMin() << endl;
	cout << "                                                             " << endl;
	cout << "  # of readings this week:           " << this->getCount() << endl;
	cout << "                                                             " << endl;
	cout << "  Day with biggest DELTA this week:  " << this->getBiggestDelta() << endl;
	cout << "                                                             " << endl;
	// Check if the previous week exists, display no data msg if it doesn't. Else
	// data.
	if (this->lastWeek == nullptr) {
		cout << "                                                            " << endl;
		cout << "                *** NO DATA FOR LAST WEEK ***               " << endl;
		cout << "                                                          \n" << endl;
	}
	else
	{
		cout << "                                                             " << endl;
		cout << "  Last week's SUM:                   " << this->lastWeek->getSum() << endl;
		cout << "                                                             " << endl;
		cout << "  Last week's MAX:                   " << this->lastWeek->getMax() << endl;
		cout << "                                                             " << endl;
		cout << "  Last week's MIN:                   " << this->lastWeek->getMin() << endl;
		cout << "                                                             " << endl;
		cout << "  # of readings last week:           " << this->lastWeek->getCount() << endl;
		cout << "                                                             " << endl;
		cout << "  Day with biggest DELTA last week:  " << this->lastWeek->getBiggestDelta() << endl;
		cout << "                                                             " << endl;
	}
	cout << " ___________________________________________________________ " << endl;
	cout << "|                    *** END SUMMARY ***                    |" << endl;
	cout << "|___________________________________________________________|\n" << endl;
}