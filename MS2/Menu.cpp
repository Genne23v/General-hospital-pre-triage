/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "utils.h"
#include "Time.h"
#include "Menu.h"

using namespace std;
namespace sdds 
{
	void Menu::display()const
	{
		cout << m_text << endl;
		cout << "0- Exit" << endl;;
	}
	Menu::Menu(const char* MenuContent, int NoOfSelection)
	{
		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);
		m_noOfsel = NoOfSelection;
	}
	Menu::Menu(const Menu& src)
	{
		m_text = new char[strlen(src.m_text) + 1];
		strcpy(m_text, src.m_text);
		m_noOfsel = src.m_noOfsel;
	}
	Menu::~Menu()
	{
		delete[] m_text;
	}
	Menu& Menu::operator=(const Menu& src)
	{
		delete[] m_text;
		m_text = nullptr;
		m_text = new char[strlen(src.m_text) + 1];
		strcpy(m_text, src.m_text);
		m_noOfsel = src.m_noOfsel;
		return *this;
	}
	int& Menu::operator>>(int& Selection)
	{
		display();
		Selection = getInt(0, m_noOfsel, "> ", nullptr, true);
		return Selection;
	}
		
}