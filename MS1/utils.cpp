/* Citation and Sources...
Final Project Milestone 1
Module: utils
Filename: utils.cpp
Version 1.0
Author	Wonkeun No
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
	bool debug = false;  // made global in utils.h
	int getTime() {
		int mins = -1;
		if (debug) {
			Time t(0);
			cout << "Enter current time: ";
			do {
				cin.clear();
				cin >> t;   // needs extraction operator overloaded for Time
				if (!cin) {
					cout << "Invalid time, try agian (HH:MM): ";
					cin.clear();
				}
				else {
					mins = int(t);
				}
				cin.ignore(1000, '\n');
			} while (mins < 0);
		}
		else {
			time_t t = time(NULL);
			tm lt = *localtime(&t);
			mins = lt.tm_hour * 60 + lt.tm_min;
		}
		return mins;
	}

	int getInt(const char* prompt)
	{
		int input = 0;
		bool ok = false;
		string line;

		if (prompt != nullptr)
		{
			cout << prompt;
		}
		do
		{
			getline(cin, line, '\n');

			if (all_of(line.begin(), line.end(), isdigit))
			{
				ok = true;
			}
			else
			{
				if (!isdigit(line.at(0)))
				{
					cout << "Bad integer value, try again: ";
				}
				else
				{
					cout << "Enter only an integer, try again: ";
				}
				cin.clear();
				//cin.ignore(100, '\n');
			}

		} while (!ok);
		input = stoi(line);
		return input;
	}

	int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
	{
		int input = 0;
		bool ok = false;
		string line;

		if (prompt != nullptr)
		{
			cout << prompt;
		}
		do
		{
			getline(cin, line, '\n');

			auto isdigit = [](char ch) {return std::isdigit(static_cast<unsigned char>(ch)); };

			if (std::all_of(line.begin(), line.end(), [](char c) { return std::isdigit(c);}))
			{
				input = stoi(line);
				if (input >= min && input <= max)
				{
					ok = true;
				}
				else if ((input < min || input > max) && showRangeAtError == false)
				{
					cout << errorMessage;
					showRangeAtError = true;
				}
				else
				{
					cout << "Invalid value, retry [" << min << " <= value <= " << max << "]: ";
				}
			}
			else
			{
				if (!isdigit(line.at(0)))
				{
					cout << "Bad integer value, try again: ";
				}
				else
				{
					cout << "Enter only an integer, try again: ";
				}
				cin.clear();
			}
		} while (!ok);

		return input;
	}

	char* getcstr(const char* prompt, std::istream& istr, char delimiter)
	{
		cout << prompt;
		string line;
		getline(istr, line, delimiter);
		int size = line.size();

		char* stringObj = new char[size + 1];
		strcpy(stringObj, line.c_str());

		return stringObj;
	}
}