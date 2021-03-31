/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.cpp
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
#include "CovidPatient.h"
#include "Ticket.h"
#include "Patient.h"

namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient() : Patient(nextCovidTicket)
   {
	   nextCovidTicket++;
   }
   char CovidPatient::type() const
   {
	   return 'C';
   }
   std::ostream& CovidPatient::csvWrite(std::ostream& os) const
   {
	   Patient::csvWrite(os);

	   return os;
   }
   std::istream& CovidPatient::csvRead(std::istream& is)
   {
	   Patient::csvRead(is);
	   nextCovidTicket = Ticket::number() +1;

	   return is;
   }
   std::ostream& CovidPatient::write(std::ostream& os) const
   {
	   if (fileIO())
	   {
		   csvWrite(os);
	   }
	   else
	   {
		   os << "COVID TEST" << std::endl;
		   Patient::write(os);
		   os << std::endl;
	   }

	   return os;
   }
   std::istream& CovidPatient::read(std::istream& is)
   {
	   fileIO() ? csvRead(is) : Patient::read(is);

	   return is;
   }
}