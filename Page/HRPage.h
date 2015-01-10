#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include "AddEmployeePage.h"
#include "queryEmployeePage.h"
class HRPage
{
public:
	Fl_Double_Window* container;
	Fl_Button* add;
	Fl_Button* query;
public:
	HRPage(void)
	{
		{ 
			Fl_Double_Window* o = new Fl_Double_Window(375, 135);
			container = o;
		{ 
			add = new Fl_Button(30, 35, 135, 70, "\346\267\273\345\212\240\350\201\214\345\267\245");
			add->callback((Fl_Callback*)HRPage::buttonCallback, (void*)(1));
		}
		{ 
			query = new Fl_Button(215, 35, 135, 70, "\346\237\245\350\257\242\350\201\214\345\267\245");
			query->callback((Fl_Callback*)HRPage::buttonCallback, (void*)(2));
		} 
			o->end();
		} 
	}
	~HRPage(void){}

	void show()
	{
		container->show();
	}
	static void buttonCallback(Fl_Widget* sender,void* userdata)
	{			
		int from = (int)userdata;
		if(from == 1)
		{
			AddEmployeePage* addEmployeePage = new AddEmployeePage;
			addEmployeePage->show();
		}
		else if(from == 2)
		{
			QueryEmployeePage* queryEmployeePage = new QueryEmployeePage;
			queryEmployeePage->show();
		}
		
	}
};

