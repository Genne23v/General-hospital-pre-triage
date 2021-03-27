/* Citation and Sources...
Final Project Milestone 3
Module: Patinet
Filename: Patient.cpp
Version 1.0
Author	Wonkeun No
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/26  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Patient.h"
#include "Time.h"
#include "utils.h"

namespace sdds
{
	Patient::Patient(int ticketNumber, bool ioFlag) : Ticket(ticketNumber)
	{
		m_ioFlag = ioFlag;
	}
	Patient::~Patient()
	{
		delete[] m_name;
	}
	bool Patient::fileIO() const
	{
		return m_ioFlag;
	}
	void Patient::fileIO(bool ioFlag)
	{
		m_ioFlag = ioFlag;
	}
	bool Patient::operator==(const char src) const
	{
		bool compare = false;
		if (type() == src)
		{
			compare = true;
		}
		return compare;
	}
	bool Patient::operator==(const Patient& src) const
	{
		bool compare = false;
		if (type() == src.type())
		{
			compare = true;
		}
		return compare;
	}
	void Patient::setArrivalTime()
	{
		resetTime();
	}
	/*unsigned int Patient::operator Time(const Patient& src) const
	{
		return 1;
	}*/
	int Patient::number() const
	{
		return Ticket::number();
	}
	std::ostream& Patient::csvWrite(std::ostream& os) const
	{
		os << type() << ',' << m_name << ',' << m_insuranceNum << ',';
		Ticket::csvWrite(os);
		//os << std::endl;
		return os;
	}
	std::istream& Patient::csvRead(std::istream& is)
	{
		char temp[100];
		is.getline(temp, 100, ',');
		delete[] m_name;
		m_name = new char[strlen(temp) + 1];
		strcpy(m_name, temp);

		is >> m_insuranceNum;
		is.ignore();

		Ticket::csvRead(is);

		return is;
	}
	std::ostream& Patient::write(std::ostream& os) const
	{
		Ticket::write(os);
		os << std::endl;
		
		if (strlen(m_name) > 25)
		{
			string str(m_name);
			os << str.substr(0, 25);
		}
		else
		{
			os << m_name;
		}
		os << ", OHIP: ";
		os << m_insuranceNum;
		return os;
	}
	std::istream& Patient::read(std::istream& is)
	{
		char temp[100];
		std::cout << "Name: ";
		is.getline(temp, 100, '\n');
		delete[] m_name;
		m_name = nullptr;
		m_name = new char[strlen(temp) + 1];
		strcpy(m_name, temp);
		
		std::cout << "OHIP: ";
		m_insuranceNum = getInt(100000000, 999999999);

		return is;
	}
}