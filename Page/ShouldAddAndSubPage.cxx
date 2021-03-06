// generated by Fast Light User Interface Designer (fluid) version 1.0303

#include "ShouldAddAndSubPage.h"
Fl_Input * ShouldAddAndSubPage::personNumIP = NULL;

Fl_Box * ShouldAddAndSubPage::_personNameBox = NULL;
Fl_Box * ShouldAddAndSubPage::_departNameBox = NULL;
Fl_Box * ShouldAddAndSubPage::_jobNameBox = NULL;
Fl_Box * ShouldAddAndSubPage::_personGenderBox = NULL;

Fl_Input * ShouldAddAndSubPage::addsubIP = NULL;
Fl_Spinner * ShouldAddAndSubPage::moneySP = NULL;
Fl_Spinner * ShouldAddAndSubPage::yearSP = NULL;
Fl_Spinner * ShouldAddAndSubPage::monthSP = NULL;
Fl_Spinner * ShouldAddAndSubPage::daySP = NULL;

Fl_Double_Window* ShouldAddAndSubPage:: container = NULL;

EmployeeData ShouldAddAndSubPage::_employeeData;

Fl_Button* ShouldAddAndSubPage:: confirmBt = NULL;
ShouldAddAndSubPage::ShouldAddAndSubPage() {
  { Fl_Double_Window* o = new Fl_Double_Window(535, 433, "\345\272\224\345\242\236\345\272\224\345\207\217");
  container = o;
    o->user_data((void*)(this));
    { personNumIP = new Fl_Input(105, 22, 255, 43, "\345\221\230\345\267\245\347\274\226\345\217\267\357\274\232");
    } // Fl_Input* personNumIP
    { Fl_Button* bt = new Fl_Button(415, 22, 90, 43, "\346\237\245\350\257\242\345\221\230\345\267\245");
	bt->callback((Fl_Callback*)ShouldAddAndSubPage::buttonCallBack,(void*)QUERY_PERSON);
    } // Fl_Button* o
	{ 
		Fl_Group* o = new Fl_Group(/*25, 25, 520, 105,*/30, 100, 480, 100, "\345\221\230\345\267\245\344\277\241\346\201\257");
		o->box(FL_FLAT_BOX);
		o->color((Fl_Color)166);
		{ new Fl_Box(50, 38+75, 65, 29, "\345\220\215\345\255\227\357\274\232");
		} // Fl_Box* o
		{ _personNameBox = new Fl_Box(125, 38+75, 65, 29);
		} // Fl_Box* personNameBox
		{ new Fl_Box(50, 81+75, 65, 29, "\351\203\250\351\227\250\357\274\232");
		} // Fl_Box* o
		{ _departNameBox = new Fl_Box(125, 81+75, 65, 29);
		} // Fl_Box* departNameBox
		{ new Fl_Box(265, 81+75, 65, 29, "\350\201\214\344\275\215\357\274\232");
		} // Fl_Box* o
		{ _jobNameBox = new Fl_Box(335, 81+75, 65, 29);
		} // Fl_Box* jobNameBox
		{ new Fl_Box(265, 38+75, 65, 29, "\346\200\247\345\210\253\357\274\232");
		} // Fl_Box* o
		{ _personGenderBox = new Fl_Box(335, 38+75, 65, 29);
		} // Fl_Box* personGenderBox
		o->end();
	} // Fl_Group* o
    { addsubIP = new Fl_Input(105, 231, 162, 43, "\345\272\224\345\242\236\345\272\224\345\207\217\357\274\232");
    } // Fl_Input* addsubIP
    { moneySP = new Fl_Spinner(340, 231, 162, 43, "\351\207\221\351\242\235\357\274\232");
      moneySP->maximum(100000);
    } // Fl_Spinner* moneySP
    { yearSP = new Fl_Spinner(65, 301, 105, 43, "\345\271\264\357\274\232");
	yearSP->maximum(3000);
	yearSP->value(2015);
    } // Fl_Spinner* yearSP
    { monthSP = new Fl_Spinner(235, 301, 105, 43, "\346\234\210\357\274\232");
	monthSP->maximum(12);
    } // Fl_Spinner* monthSP
    { daySP = new Fl_Spinner(397, 301, 105, 43, "\346\227\245\357\274\232");
	daySP->maximum(31);
    } // Fl_Spinner* daySP
    { Fl_Button* o = new Fl_Button(105, 372, 90, 43, "\347\241\256\345\256\232");
	o->callback((Fl_Callback*)ShouldAddAndSubPage::buttonCallBack,(void*)CONFIRM);
	confirmBt = o;
      o->deactivate();
    } // Fl_Button* o
    { new Fl_Button(330, 372, 90, 43, "\345\217\226\346\266\210");
    } // Fl_Button* o
    o->end();
  } // Fl_Double_Window* o
}
