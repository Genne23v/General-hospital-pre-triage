/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
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
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds 
{
	class Menu
	{
		char* m_text;
		int m_noOfsel;
		void display()const;
	public:
		Menu() {};
		Menu(const char* MenuContent, int NoOfSelection);
		virtual ~Menu();
		Menu(const Menu& src);
		Menu& operator=(const Menu& src);
		int& operator>>(int& Selection);
	};

}
#endif // !SDDS_MENU_H_

