#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include "HRPage.h"
#include "salaryManagePage.h"
#define HR 0
#define SALARY 1
#define USER 2
#define DEPART 3
class MainPage
{
public:
	Fl_Double_Window* container;
	Fl_Button* hrBt;
	Fl_Button* salaryBt;
	Fl_Button* userBt;
	Fl_Button* departBt;
public:
	MainPage(void)
	{
		
		container = new Fl_Double_Window(655, 458, "\345\267\245\350\265\204\347\256\241\347\220\206\347\263\273\347\273\237_by\
															   \346\264\252\346\265\251\351\271\217");

		container->box(FL_BORDER_BOX);
		container->color((Fl_Color)91);


		{ 
			Fl_Button* o = new Fl_Button(120, 100, 175, 100, "\344\272\272\345\221\230\347\256\241\347\220\206");
			o->box(FL_ROUNDED_BOX);
			hrBt = o;
			o->callback(((Fl_Callback*)MainPage::buttonCallback),(void*)(HR));
		}
		{
			Fl_Button* o = new Fl_Button(350, 255, 175, 100, "\345\267\245\350\265\204\347\256\241\347\220\206");
			o->box(FL_ROUNDED_BOX);
			salaryBt = o;
			o->callback(((Fl_Callback*)MainPage::buttonCallback),(void*)(SALARY));
		}
		{
			Fl_Button* o = new Fl_Button(120, 255, 175, 100, "\351\203\250\351\227\250\347\256\241\347\220\206");
			o->box(FL_ROUNDED_BOX);
			departBt = o;
			

		}
		{
			Fl_Button* o = new Fl_Button(350, 100, 175, 100, "\347\263\273\347\273\237\347\256\241\347\220\206");
			o->box(FL_ROUNDED_BOX);
			userBt = o;
		}

		container->end();

	}
	~MainPage(void)
	{

	}
	void show()
	{
		container->show();
	}
	static void buttonCallback(Fl_Widget* sender,void* userdata)
	{
		int type = (int)(userdata);
		HRPage* hrPage = NULL;
		SalaryManagePage* smPage = NULL;
		switch (type)
		{
		case HR:
			hrPage = new HRPage;
			hrPage->show();
			break;
		case SALARY:
			smPage = new SalaryManagePage;
			smPage->show();
			break;
		default:
			break;
		}

	}
};

