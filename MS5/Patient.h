/* Citation and Sources...
Final Project Milestone 4
Module: Patient
Filename: Patient.h
Version 1.1
Author	Wonkeun No
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/26  Preliminary release
2020/3/31  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include <iostream>
#include <fstream>
#include "Ticket.h"

namespace sdds
{
	class Patient : public Ticket
	{
		char* m_name;
		int m_insuranceNum;
		bool m_ioFlag;
	public:
		Patient(int tcktNum = 0, bool ioFlag = false);
		Patient(const Patient& src) = delete;
		Patient& operator=(const Patient& src) = delete;
		~Patient();
		virtual char type() const = 0;
		bool fileIO() const;
		void fileIO(bool flag);
		bool operator==(const char src) const;
		bool operator==(const Patient& src) const;
		void setArrivalTime();
		int number() const;
		std::ostream& csvWrite(std::ostream& os) const;
		std::istream& csvRead(std::istream& is);
		virtual std::ostream& write(std::ostream& os) const;
		virtual std::istream& read(std::istream& is);
	};
}

#endif // !SDDS_PATIENT_H_

