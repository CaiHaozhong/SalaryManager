// generated by Fast Light User Interface Designer (fluid) version 1.0303

#include "salaryManagePage.h"

SalaryManagePage::SalaryManagePage() {
  { Fl_Double_Window* o = new Fl_Double_Window(505, 605, "\345\267\245\350\265\204\347\256\241\347\220\206");
    container = o;
	container->color((Fl_Color)91);
    o->user_data((void*)(this));
    { Fl_Group* o = new Fl_Group(40, 40, 425, 230, "\345\267\245\350\265\204\347\261\273\345\210\253");
      o->box(FL_FLAT_BOX);
      o->color((Fl_Color)67);
      { Fl_Choice* o = new Fl_Choice(145, 60, 270, 40, "\351\203\250\351\227\250\345\220\215\347\247\260\357\274\232");
        o->down_box(FL_BORDER_BOX);
      } // Fl_Choice* o
      { Fl_Choice* o = new Fl_Choice(145, 113, 270, 40, "\345\262\227\344\275\215\345\220\215\347\247\260\357\274\232");
        o->down_box(FL_BORDER_BOX);
      } // Fl_Choice* o
      { new Fl_Input(145, 168, 150, 40, "\345\267\245\350\265\204\347\261\273\345\210\253\357\274\232");
      } // Fl_Input* o
      { new Fl_Spinner(345, 171, 65, 40, "\345\267\245\350\265\204\357\274\232");
      } // Fl_Spinner* o
      { new Fl_Button(195, 220, 120, 40, "\346\267\273\345\212\240");
      } // Fl_Button* o
      o->end();
    } // Fl_Group* o
    { Fl_Group* o = new Fl_Group(40, 312, 425, 145, "\345\221\230\345\267\245\345\267\245\350\265\204");
      o->box(FL_FLAT_BOX);
      o->color((Fl_Color)87);
      { new Fl_Input(145, 338, 270, 40, "\345\221\230\345\267\245\347\274\226\345\217\267\357\274\232");
      } // Fl_Input* o
      { new Fl_Button(70, 407, 98, 40, "\347\224\237\346\210\220\345\267\245\350\265\204\350\241\250");
      } // Fl_Button* o
      { new Fl_Button(350, 407, 98, 40, "\345\272\224\345\242\236\345\272\224\345\207\217");
      } // Fl_Button* o
      { new Fl_Button(200, 407, 115, 40, "\350\256\241\347\256\227\345\271\264\345\271\263\345\235\207\345\267\245\350\
\265\204");
      } // Fl_Button* o
      o->end();
    } // Fl_Group* o
    { Fl_Group* o = new Fl_Group(40, 492, 425, 88, "\351\203\250\351\227\250\345\267\245\350\265\204");
      o->box(FL_FLAT_BOX);
      o->color((Fl_Color)132);
      { Fl_Choice* o = new Fl_Choice(120, 512, 224, 40, "\351\203\250\351\227\250\345\220\215\347\247\260\357\274\232");
        o->down_box(FL_BORDER_BOX);
      } // Fl_Choice* o
      { new Fl_Button(362, 512, 98, 40, "\346\237\245\350\257\242\345\271\263\345\235\207\345\267\245\350\265\204");
      } // Fl_Button* o
      o->end();
    } // Fl_Group* o
    o->end();
  } // Fl_Double_Window* o
}

void SalaryManagePage::show()
{
	container->show();
}