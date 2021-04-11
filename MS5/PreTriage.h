/* Citation and Sources...
Final Project Milestone 5
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
#ifndef SDDS_PRETRIAGE_H
#define SDDS_PRETRIAGE_H

#include "Menu.h"
#include "Patient.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"

namespace sdds {
        const int maxNoOfPatients = 100;
        class PreTriage {
            Time
                m_averCovidWait,
                m_averTriageWait;
            Patient* m_lineup[maxNoOfPatients]{};
            char* m_dataFilename = nullptr;
            int m_lineupSize = 0;
            Menu
                m_appMenu,
                m_pMenu;
            void reg();
            void admit();
            const Time getWaitTime(const Patient& p)const;
            void setAverageWaitTime(const Patient& p);
            void removePatientFromLineup(int index);
            int indexOfFirstInLine(char type) const;
            void load();
        public:
            PreTriage(const char* dataFilename);
            ~PreTriage();
            void run(void);
        };
}
#endif // !SDDS_TRIAGEPATIENT_H


