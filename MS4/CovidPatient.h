/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.h
Version 1.0
Author	Wonkeun No
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/31  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_

#include <iostream>
#include "Patient.h"
#include "Ticket.h"

namespace sdds 
{
	class CovidPatient : public Patient
	{
	public:
		CovidPatient();
		char type() const;
		std::ostream& csvWrite(std::ostream& os) const;
		std::istream& csvRead(std::istream& is);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);
		//virtual ~CovidPatient() = 0;
	};
}
#endif // !SDDS_COVIDPATIENT_H_



