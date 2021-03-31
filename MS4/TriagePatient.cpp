/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "TriagePatient.h"

namespace sdds {
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient() : Patient(nextTriageTicket)
   {
	   nextTriageTicket++;
   }
   char TriagePatient::type() const
   {
	   return 'T';
   }
   std::ostream& TriagePatient::csvWrite(std::ostream& os) const
   {
	   Patient::csvWrite(os);
	   os << ", " << m_symptom;
	   return os;
   }
   std::istream& TriagePatient::csvRead(std::istream& is)
   {
	   Patient::csvRead(is);
	   
	   nextTriageTicket = Ticket::number() + 1;
	   return is;
   }
   std::ostream& TriagePatient::write(std::ostream& os) const
   {
	   if (fileIO())
	   {
		   csvWrite(os);
	   }
	   else
	   {
		   os << "TRIAGE" << std::endl;
		   Patient::write(os);
		   os<< std::endl;
		   os << "Symptoms: " << m_symptom;
		   os << std::endl;
	   }

	   return os;
   }
   std::istream& TriagePatient::read(std::istream& is)
   {
	   char temp[200] = { '\0' };

	   if (fileIO())
	   {
		   csvRead(is);
	   }
	   else
	   {
		   Patient::read(is);

		   std::cout << "Symptoms: ";
		   
	   }

	   is.getline(temp, 200, '\n');
	   delete[] m_symptom;
	   m_symptom = nullptr;
	   m_symptom = new char[strlen(temp) + 1];
	   strcpy(m_symptom, temp);

	   return is;
   }
   TriagePatient::~TriagePatient()
   {
	   delete[] m_symptom;
   }
}