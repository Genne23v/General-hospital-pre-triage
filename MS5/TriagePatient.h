/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.h
Version 1.1
Author	Wonkeun No
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/31  Preliminary release
2020/4/11  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H

#include "Patient.h"

namespace sdds {
	extern int nextTriageTicket;

	class TriagePatient : public Patient
	{
		char* m_symptom = nullptr;
	public:
		TriagePatient();
		char type() const;
		std::ostream& csvWrite(std::ostream& os) const;
		std::istream& csvRead(std::istream& is);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);
		~TriagePatient();
	};
}
#endif // !SDDS_TRIAGEPATIENT_H


