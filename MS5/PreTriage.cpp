/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Author	Wonkeun No
Revision History
-----------------------------------------------------------
Date      Reason
2020/4/10  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "PreTriage.h"

namespace sdds {
    void PreTriage::reg()
    {
        if (m_lineupSize >= maxNoOfPatients)
        {
            cout << "Line up full" << endl;
        }
        else
        {
            int selection;
            m_pMenu >> selection;
            switch (selection)
            {
            case 1:
                m_lineup[m_lineupSize] = new CovidPatient();
                break;
            case 2:
                m_lineup[m_lineupSize] = new TriagePatient();
                break;
            case 0:
                break;
            }

            m_lineup[m_lineupSize]->setArrivalTime();

            cout << "Please enter patient information: ";
            //FILE IO??
            m_lineup[m_lineupSize]->read(cin);

            cout << endl;
            cout << "******************************************" << endl;
            cout << m_lineup[m_lineupSize] << endl;
            cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
            cout << "******************************************" << endl << endl;
        }
    }
    void PreTriage::admit()
    {
        int selection;
        char type;
        m_pMenu >> selection;
        switch (selection)
        {
        case 1:
            type = 'C';
            break;
        case 2:
            type = 'T';
            break;
        case 0:
            break;
        }

        int firstIndex = indexOfFirstInLine(type);
        cout << "******************************************" << endl;
        //FILE IO
        cout << "Calling for " << m_lineup[m_lineupSize]<< endl;
        cout << "******************************************" << endl << endl;

        setAverageWaitTime(*m_lineup[m_lineupSize]);
        removePatientFromLineup(firstIndex);

    }
    const Time PreTriage::getWaitTime(const Patient& p)const
    {
        Time estimatedWait;

        if (p.type() == 'C')
        {
            estimatedWait = m_averCovidWait * (unsigned)nextCovidTicket;
        }
        else if (p.type() == 'T')
        {
            estimatedWait = m_averTriageWait * (unsigned)nextTriageTicket;
        }

        return estimatedWait;
    }
    void PreTriage::setAverageWaitTime(const Patient& p)
    {
        Time currentTime;
        m_averCovidWait = (currentTime.setToNow() - Time(p)) + (m_averCovidWait * (unsigned)(p.number() - 1)) / (unsigned)p.number();
    }
    void PreTriage::removePatientFromLineup(int index)
    {
        
        removeDynamicElement<Patient>(m_lineup, index, m_lineupSize);
    }
    int PreTriage::indexOfFirstInLine(char type) const
    {
        bool found = false;
        int i = 0;
        while (found)
        {
            if (m_lineup[i]->type() == type)
            {
                found = true;
            }
            i++;
        }
        if (found == false)
        {
            i = -1;
        }
        return i;
    }
    void PreTriage::load()
    {
        cout << "Loading data..." << endl;

        ifstream fin(m_dataFilename);
        string temp;
        int i = 0;

        Patient* tempP;

        if (fin.is_open())
        {
            fin >> m_averCovidWait;
            fin.ignore();
            fin >> m_averTriageWait;
            fin.ignore();

            if (fin.good())
            { 
                for (i=0; i< maxNoOfPatients; i++)
                {
                    getline(fin, temp, ',');
                    if (temp[0] == 'C')
                    {
                        m_lineup[i] = new CovidPatient();
                        tempP = new CovidPatient();
                    }
                    else if (temp[0] == 'T')
                    {
                        m_lineup[i] = new TriagePatient();
                    }
                    
                    if (m_lineup[i])
                    {
                        m_lineup[i] ->fileIO(true);
                        m_lineup[i]->csvRead(fin);

                        m_lineup[i]->fileIO(false);
                        m_lineupSize++;
                    }
                }
            }
            cout << endl;

            if (!fin.eof())
            {
                cout << "Warning: number of records exceeded 100";
            }
            if (i > 0)
            {
                cout << i + 1 << " Records imported..." << endl;
            }
            else
            {
                cout << "No data or bad data file!" << endl;
            }
        }
    }

    PreTriage::PreTriage(const char* dataFilename) : m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2), m_averCovidWait(15), m_averTriageWait(5)

    {
        if (dataFilename != nullptr)
        {
            m_dataFilename = new char[strlen(dataFilename) + 1];
            strcpy(m_dataFilename, dataFilename);
        }

        load();
    }
    PreTriage::~PreTriage()
    {
        delete[] m_dataFilename;
    }
    
    void PreTriage::run(void)
    {
        int selection=0;

        while (selection != 0)
        {
            m_appMenu >> selection;
            switch (selection)
            {
            case 1:
                reg();
                break;
            case 2:
                admit();
                break;
            case 0:
                break;
            }
        }

    }
}