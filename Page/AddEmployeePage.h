#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
class AddEmployeePage
{
public:
	Fl_Double_Window* container;
public:
	AddEmployeePage(void)
	{		
		Fl_Double_Window* o = new Fl_Double_Window(292, 451, "\346\267\273\345\212\240\350\201\214\345\267\245");
		container = o;
		{ 
			new Fl_Input(54, 50, 200, 40, "\345\220\215\345\255\227\357\274\232");
		} // Fl_Input* o
		{ 
			new Fl_Input(54, 115, 200, 40, "\347\274\226\345\217\267\357\274\232");
		} // Fl_Input* o
		{ 
			Fl_Choice* o = new Fl_Choice(54, 190, 200, 40, "\346\200\247\345\210\253\357\274\232");
			o->down_box(FL_BORDER_BOX);
		} // Fl_Choice* o
		{ 
			Fl_Choice* o = new Fl_Choice(54, 255, 200, 40, "\351\203\250\351\227\250\357\274\232");
			o->down_box(FL_BORDER_BOX);
		} // Fl_Choice* o
		{ 
			Fl_Choice* o = new Fl_Choice(54, 325, 200, 40, "\345\262\227\344\275\215\357\274\232");
			o->down_box(FL_BORDER_BOX);
		} // Fl_Choice* o
		{ 
			new Fl_Button(45, 400, 64, 40, "\347\241\256\345\256\232");
		} // Fl_Button* o
		{ 
			new Fl_Button(180, 400, 64, 40, "\345\217\226\346\266\210");
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
};

