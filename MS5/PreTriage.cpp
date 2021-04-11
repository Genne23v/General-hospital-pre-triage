/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Author	Wonkeun No
Revision History
-----------------------------------------------------------
Date      Reason
2020/4/11  Preliminary release
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
            cout << "Line up full!" << endl;
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

            cout << "Please enter patient information: " << endl;
            m_lineup[m_lineupSize]->fileIO(false);
            m_lineup[m_lineupSize]->read(cin);

            cout << endl;
            cout << "******************************************" << endl;
            m_lineup[m_lineupSize]->write(cout);
            cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
            cout << "******************************************" << endl << endl;
            
            m_lineupSize++;
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
        cout << endl;
        cout << "******************************************" << endl;
        m_lineup[firstIndex]->fileIO(false);
        cout << "Calling for ";
        m_lineup[firstIndex]->write(cout);
        cout << "******************************************" << endl << endl;

        setAverageWaitTime(*m_lineup[firstIndex]);
        removePatientFromLineup(firstIndex);

    }
    const Time PreTriage::getWaitTime(const Patient& p)const
    {
        Time estimatedWait;

        if (p.type() == 'C')
        {
            estimatedWait = m_averCovidWait * (unsigned)(p.number()-1);
        }
        else if (p.type() == 'T')
        {
            estimatedWait = m_averTriageWait * (unsigned)(p.number()-1);
        }

        return estimatedWait;
    }
    void PreTriage::setAverageWaitTime(const Patient& p)
    {
        Time currentTime;
        if (p.type() == 'C')
        {
            m_averCovidWait = ((currentTime.setToNow() - Time(p)) + m_averCovidWait * (unsigned)(p.number() - 1)) / (unsigned)p.number();
        }
        else if (p.type() == 'T') {
            m_averTriageWait = ((currentTime.setToNow() - Time(p)) + m_averTriageWait * (unsigned)(p.number() - 1)) / (unsigned)p.number();
        }
    }
    void PreTriage::removePatientFromLineup(int index)
    {
        
        removeDynamicElement<Patient>(m_lineup, index, m_lineupSize);
    }
    int PreTriage::indexOfFirstInLine(char type) const
    {
        bool found = false;
        int i = 0;
        int index = 0;
        do
        {
            if (m_lineup[i]->type() == type)
            {
                found = true;
                index = i;
            }
            i++;
        } while (!found);

        if (found == false)
        {
            index = -1;
        }
        return index;
    }
    void PreTriage::load()
    {
        cout << "Loading data..." << endl;

        ifstream fin(m_dataFilename);
        string type;
        int i = 0;
        m_lineupSize = 0;
        //Patient* P;

        if (fin.is_open())
        {
            fin >> m_averCovidWait;
            fin.ignore();
            fin >> m_averTriageWait;
            fin.ignore();

            while (i < maxNoOfPatients && !fin.eof())
            {
                bool initialized = false;

                getline(fin, type, ',');

                if (type[0] == 'C')
                {
                    //P = new CovidPatient;
                    m_lineup[i] = new CovidPatient;
                    initialized = true;
                }
                else if (type[0] == 'T')
                {
                    m_lineup[i] = new TriagePatient;
                    initialized = true;
                }

                if (initialized)
                {
                    m_lineup[i]->fileIO(true);
                    m_lineup[i]->csvRead(fin);

                    m_lineup[i]->fileIO(false);
                    m_lineupSize++;
                    i++;
                }
            }

            if (!fin.eof())
            {
                cout << "Warning: number of records exceeded 100" << endl;
            }
            if (i > 0)
            {
                cout << i << " Records imported..." << endl;
            }
            else
            {
                cout << "No data or bad data file!" << endl;
            }
            cout << endl;
        }
    }

    PreTriage::PreTriage(const char* dataFilename) : m_averCovidWait(15), m_averTriageWait(5), m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
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
        ofstream fout(m_dataFilename);
        fout << m_averCovidWait << ',' << m_averTriageWait << endl;
        for (int i = 0; i < m_lineupSize; i++)
        {
            m_lineup[i]->fileIO(true);
            m_lineup[i]->write(fout);
            fout << endl;
        }

        cout << "Saving Average Wait Times," << endl;
        cout << "   COVID Test: " << m_averCovidWait << endl;
        cout << "   Triage: " << m_averTriageWait << endl;
        cout << "Saving m_lineup..." << endl;
        
        for (int i = 0; i < m_lineupSize; i++)
        {
            cout << i + 1 << "- ";
            m_lineup[i]->write(cout);
            cout << endl;
        }
        cout << "done!" << endl;

        delete m_lineup;
        delete[] m_dataFilename;
        m_dataFilename = nullptr;
    }
    
    void PreTriage::run(void)
    {
        int selection=0;

        do
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
        } while (selection != 0);

    }
}