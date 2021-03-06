// project1.cpp
// Finley McIlwaine
// COSC2030 Project 1
/*
Description: 
	This program accepts and displays
	blood sugar data throughout a
	2-week period.
*/

#include "pch.h"
#include <iostream>
#include <string>
#include "Day.h"
#include "Week.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stof;

void initScreen();
void getInput(string& req, float& bloodSug);
void inputError();


int main()
{
	// Welcome screen & use instructions.
	initScreen();
	// Initialize input variables
	// @bloodSugar --> holds blood sugar input
	// @request --> holds string request input
	float bloodSugar = 0;
	string request = "";
	Week* currentWeek = new Week;

	while (true) {
		// Prompt for user input
		getInput(request, bloodSugar);

		// Check for exit input
		if (request == "E") { return 0; }

		// Process other input
		if (bloodSugar != 0) { 
			currentWeek->enterBloodSugar(bloodSugar);
		}
		else if (request == "D") { currentWeek->currentDay->showSummary(); }
		else if (request == "W") { currentWeek->showSummary(); }
		else if (request == "N") { currentWeek->newDay(currentWeek); }
	}
}

// Displays the introduction screen
// with instructions in the blood sugar terminal.
void initScreen() {
	cout << " ___________________________________________________________ " << endl;
	cout << "|~+~+~+~ BLOOD SUGAR LEVELS AND INFORMATION TERMINAL ~+~+~+~|" << endl;
	cout << "|                                                           |" << endl;
	cout << "|                       *INSTRUCTIONS*                      |" << endl;
	cout << "| To record blood sugar:      Enter blood sugar level as a  |" << endl;
	cout << "|                             positive numerical value.     |" << endl;
	cout << "|                                                           |" << endl;
	cout << "| To show today's summary:    Enter 'D' or 'Day'.           |" << endl;
	cout << "|                                                           |" << endl;
	cout << "| To show weekly summary:     Enter 'W' or 'Week'.          |" << endl;
	cout << "|                                                           |" << endl;
	cout << "| To increment to next day:   Enter 'N' or 'Next'.          |" << endl;
	cout << "|                                                           |" << endl;
	cout << "| To display instructions:    Enter 'H' or 'Help'.          |" << endl;
	cout << "|                                                           |" << endl;
	cout << "| To exit the application:    Enter 'E' or 'Exit'.          |" << endl;
	cout << "|___________________________________________________________|\n" << endl;
}

// Outputs the input prompt and gets/validates
// the user's input.
void getInput(string& req, float& bloodSug) {
	// Reset input variables
	req = "";
	bloodSug = 0;

	// Input prompt
	cout << "  INPUT: ";

	// Handle exceptions
	try
	{
		cin >> req;
		cout << endl;

		// Check for recognized input strings
		if (req == "D" || req == "Day") { req = "D"; }
		else if (req == "W" || req == "Week") { req = "W"; }
		else if (req == "N" || req == "Next") { req = "N"; }
		else if (req == "E" || req == "Exit") { req = "E"; }
		else if (req == "H" || req == "Help") { initScreen(); getInput(req, bloodSug); }
		else
		{
			// Try to convert to float if not recognized string
			bloodSug = stof(req);
			if (bloodSug <= 0) {
				// Silently ignore input and reprompt
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin.clear();
				getInput(req, bloodSug);
			}
		}
	}
	catch(...)
	{
		// Exception thrown, display error message
		inputError();
		// Reprompt for input
		getInput(req, bloodSug);
	}
}

// Ignores following input, clears input state,
// and displays error message.
void inputError() {
	 cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	 cin.clear();
	 cout << "                 **** ERROR: INVALID INPUT ****              " << endl;
	 cout << "                  Input 'H' or 'Help' for help.              \n" << endl;
 }