#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include "Storage.h"
class AddEmployeePage
{
public:
	static Fl_Double_Window* container;
	static Fl_Input* nameIP;
	static Fl_Input* numIP;
	static Fl_Choice* gendFC;
	static Fl_Choice* depaFC;
	static Fl_Choice* jobFC;
public:
	AddEmployeePage(void)
	{		
		Fl_Double_Window* o = new Fl_Double_Window(292, 451, "\346\267\273\345\212\240\350\201\214\345\267\245");
		container = o;
		{ 
			nameIP = new Fl_Input(54, 50, 200, 40, "\345\220\215\345\255\227\357\274\232");
		} // Fl_Input* o
		{ 
			numIP = new Fl_Input(54, 115, 200, 40, "\347\274\226\345\217\267\357\274\232");
		} // Fl_Input* o
		{ 
			Fl_Choice* o = new Fl_Choice(54, 190, 200, 40, "\346\200\247\345\210\253\357\274\232");
			o->add("\347\224\267");
			o->add("\345\245\263");
			o->value(0);
			o->down_box(FL_BORDER_BOX);
			gendFC = o;
		} // Fl_Choice* o
		{ 
			Fl_Choice* o = new Fl_Choice(54, 255, 200, 40, "\351\203\250\351\227\250\357\274\232");
			vector<string> departments = Storage::getInstance()->getAllDepartment();
			for(int i = 0; i < departments.size(); i++)
				o->add(departments.at(i).c_str());
			o->value(3);
			o->down_box(FL_BORDER_BOX);
			depaFC = o;
			depaFC->callback((Fl_Callback*)AddEmployeePage::departmentChoiceChangeCallback,NULL);
			o->when(FL_WHEN_CHANGED);

		} // Fl_Choice* o
		{ 
			Fl_Choice* o = new Fl_Choice(54, 325, 200, 40, "\345\262\227\344\275\215\357\274\232");
			jobFC = o;
			o->down_box(FL_BORDER_BOX);
			string currentDepart = depaFC->text();
			resetJobInput(currentDepart);

		} // Fl_Choice* o
		{ 
			Fl_Button* bt = new Fl_Button(45, 400, 64, 40, "\347\241\256\345\256\232");
			bt->callback((Fl_Callback*)AddEmployeePage::buttonCallback,(void*)2);
		} // Fl_Button* o
		{ 
			Fl_Button* bt = new Fl_Button(180, 400, 64, 40, "\345\217\226\346\266\210");
			bt->callback((Fl_Callback*)AddEmployeePage::buttonCallback,(void*)1);
		} // Fl_Button* o
		o->end();
	}
	~AddEmployeePage(void)
	{

	}
	void show()
	{
		container->show();
	}
	static void departmentChoiceChangeCallback(Fl_Widget* sender, void* userdata)
	{
		Fl_Choice* dFC = (Fl_Choice*)sender;
		resetJobInput(dFC->text());
		std::cout << "callback";
	}

	static void resetJobInput(string depart)
	{
		jobFC->clear();
		vector<string> jobs = Storage::getInstance()->getJobName(depart);
		for(int i = 0; i < jobs.size(); i++)
			jobFC->add(jobs.at(i).c_str());
		jobFC->value(0);
	}

	static void buttonCallback(Fl_Widget* sender, void* userdata)
	{
		if((int)userdata == 1)
		{
			sender->parent()->hide();
			return ;
		}
		string name = nameIP->value();
		string num = numIP->value();
		string gender = gendFC->text();
		string job = jobFC->text();		
		bool ret = Storage::getInstance()->addEmployee(EmployeeData(num,name,job,gender));
		Fl_Widget* par = sender->parent();

		if(ret)
		{
			//par->hide();
			//Fl_Window* o = new Fl_Window(par->x(),par->y(),100,50,"Alert");
			make_window(par->x()+50, par->y()+50)->show();
		}
	}
	static Fl_Double_Window* make_window(int x, int y) {
		Fl_Double_Window* w;
		{ Fl_Double_Window* o = new Fl_Double_Window(x,y,253,126);
		w = o;
		{ Fl_Box* o = new Fl_Box(35, 24, 190, 76, "\346\267\273\345\212\240\346\210\220\345\212\237\357\274\201");
		o->box(FL_FLAT_BOX);
		o->labelsize(28);
		} // Fl_Box* o
		o->end();
		} // Fl_Double_Window* o
		return w;
	}


};

