/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.h
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
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H

#include "Patient.h"

namespace sdds {

	class TriagePatient : public Patient
	{
		char* m_symptom;
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


