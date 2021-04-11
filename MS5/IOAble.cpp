/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author	Wonkeun No
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/22  Preliminary release
2020/?/? Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef __IOABLE_H__
#define __IOABLE_H__
#include "IOAble.h"

using namespace std;
namespace sdds 
{
	ostream& operator<<(ostream& os, const IOAble& src)
	{
		return src.write(os);
	}
	istream& operator>>(istream& is, IOAble& src)
	{
		return src.read(is);
	}
	
}
#endif