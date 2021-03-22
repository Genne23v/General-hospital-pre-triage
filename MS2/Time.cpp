/* Citation and Sources...
Final Project Milestone 1
Module: time
Filename: Time.cpp
Version 1.0
Author	Wonkeun No
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "Time.h"
#include "utils.h"
#include <sstream>
using namespace std;
namespace sdds {

	Time& Time::setToNow()
	{
		m_min = getTime();
		return *this;
	}
	Time::Time(unsigned int min)
	{
		m_min = min;
	}
	std::ostream& Time::write(std::ostream& ostr) const
	{
		int hour = m_min / 60;
		int min = m_min % 60;

		ostr.width(2);
		ostr.fill('0');
		ostr << hour;
		ostr << ":";
		ostr.width(2);
		ostr << min;

		return ostr;
	}
	std::istream& Time::read(std::istream& istr)
	{
		int hour = 0;
		int min = 0;
		istr >> hour;
		if (hour < 0) istr.setstate(ios::failbit);
		if (istr.get() != ':')
			istr.setstate(ios::failbit);
		istr >> min;
		if (min < 0) istr.setstate(ios::failbit);
		if (istr) {
			m_min = (unsigned)min + hour * 60;
		}
		//string line;
		//istr >> line;
		////regex regEx("^[0-9]{2,3}:[0-9]{2,3}$");
		//std::regex regEx("[0-9][0-9][0-9]*:[0-9][0-9][0-9]*");

		//if (!regex_match(line.begin(), line.end(), regEx))
		//{
		//	istr.setstate(ios::failbit);
		//}
		//else
		//{
		//	istringstream iss(line);
		//	int hour = 0, min = 0;
		//	char rm;
		//	
		//	iss >> hour >> rm >> min;
		//	m_min = (hour * 60) + min;
		//}
		return istr;
	}

	Time& Time:: operator-=(const Time& D)
	{
		if (m_min < D.m_min)
		{
			double m = (double)D.m_min / (24 * 60);
			m_min = m_min + (24 * 60 * ceil(m)) - D.m_min;
		}
		else
		{
			m_min -= D.m_min;
		}
		return *this;
	}
	Time Time::operator-(const Time& D)const
	{
		int timeDiff = 0;
		if (m_min < D.m_min)
		{
			double m = (double)D.m_min / (24 * 60);
			timeDiff = m_min + (ceil(m) * 24 * 60) - D.m_min;
		}
		else
		{
			timeDiff = m_min - D.m_min;
		}
		return timeDiff;
	}
	Time& Time::operator+=(const Time& D)
	{
		m_min += D.m_min;
		return *this;
	}
	Time Time::operator+(const Time& D)const
	{
		int timeAdded = 0;

		timeAdded = m_min + D.m_min;
		return timeAdded;
	}

	Time& Time::operator=(unsigned int val)
	{
		m_min = val;
		return *this;
	}
	Time& Time::operator *= (unsigned int val)
	{
		m_min *= val;
		return *this;
	}
	Time& Time::operator /= (unsigned int val)
	{
		m_min /= val;
		return *this;
	}
	Time Time::operator *(unsigned int val)const
	{
		int timeMultiplied = m_min * val;
		return timeMultiplied;
	}
	Time Time::operator /(unsigned int val)const
	{
		int timeDivided = m_min / val;
		return timeDivided;
	}

	Time::operator unsigned int()const
	{
		int mins = m_min;
		return mins;
	}
	Time::operator int()const
	{
		unsigned mins = m_min;
		return mins;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		return D.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, Time& D)
	{
		return D.read(istr);
	}
}