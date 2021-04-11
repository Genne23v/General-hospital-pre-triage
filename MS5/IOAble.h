/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.h
Version 1.0
Author	Wonkeun No
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/22  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>

using namespace std;
namespace sdds 
{
	class IOAble
	{
	public:
		//IOABle() {};
		virtual ostream& csvWrite(ostream& os) const = 0;
		virtual istream& csvRead(istream& is) = 0;
		virtual ostream& write(ostream& os) const = 0;
		virtual istream& read(istream& is) = 0;
		virtual ~IOAble() {};
	};
	ostream& operator<<(ostream& os, const IOAble& src);
	istream& operator>>(istream& is, IOAble& src);

}

#endif // !SDDS_IOABLE_H

