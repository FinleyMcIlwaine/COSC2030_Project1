// day.cpp
// Finley McIlwaine
// COSC2030 Project 1
// 10.26.2018

#include "pch.h"
#include <iostream>
#include "day.h"

using std::cout;
using std::endl;

// Logs the user's blood sugar entry in the
// daily scope.
void Day::enterBloodSugar(const float &bloodSugar) {
	// Add to sum of the day. OVERFLOW CHECK HERE
	daySum = daySum + bloodSugar;

	// Increment entries counter
	entriesCount++;

	// Update max and min entry variables if appropriate
	if (dayMax < bloodSugar) { dayMax = bloodSugar; }
	if (dayMin == 0 || dayMin > bloodSugar) { dayMin = bloodSugar; }
}

// Shows the summary stats of the current day
void Day::showSummary() {
	cout << " ___________________________________________________________ " << endl;
	cout << "|          ~+~+~+~ DAILY BLOOD SUGAR SUMMARY ~+~+~+~        |" << endl;
	cout << "|___________________________________________________________|" << endl;
	cout << "                                                             " << endl;
	cout << "  Today's SUM:                       " << this->getSum() << endl;
	cout << "                                                             " << endl;
	cout << "  Today's MAX:                       " << this->getMax() << endl;
	cout << "                                                             " << endl;
	cout << "  Today's MIN:                       " << this->getMin() << endl;
	cout << "                                                             " << endl;
	cout << "  # of readings today:               " << this->getCount() << endl;
	cout << "                                                             " << endl;
	cout << " ___________________________________________________________ " << endl;
	cout << "|                    *** END SUMMARY ***                    |" << endl;
	cout << "|___________________________________________________________|\n" << endl;
}