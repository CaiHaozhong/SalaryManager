// generated by Fast Light User Interface Designer (fluid) version 1.0303

#include "queryEmployeePage.h"

QueryEmployeePage::QueryEmployeePage() {

  { Fl_Double_Window* o = new Fl_Double_Window(541, 513, "\345\221\230\345\267\245\347\256\241\347\220\206");
    container = o;
    o->user_data((void*)(this));
    { Fl_Box* o = new Fl_Box(45, 60, 465, 200);
      o->box(FL_THIN_UP_BOX);
      o->color((Fl_Color)76);
    } // Fl_Box* o
    { new Fl_Input(129, 95, 200, 40, "\345\221\230\345\267\245\347\274\226\345\217\267\357\274\232");
    } // Fl_Input* o
    { new Fl_Button(345, 95, 125, 45, "\346\214\211\347\274\226\345\217\267\346\237\245\350\257\242");
    } // Fl_Button* o
    { Fl_Box* o = new Fl_Box(195, 14, 119, 31, "\346\237\245\350\257\242\345\221\230\345\267\245");
      o->labelsize(32);
    } // Fl_Box* o
    { new Fl_Input(129, 170, 200, 40, "\345\221\230\345\267\245\347\274\226\345\217\267\357\274\232");
    } // Fl_Input* o
    { new Fl_Button(345, 170, 125, 45, "\346\214\211\347\274\226\345\217\267\346\237\245\350\257\242");
    } // Fl_Button* o
    { Fl_Table* o = new Fl_Table(45, 285, 465, 185);
      o->end();
    } // Fl_Table* o
    o->end();
  } // Fl_Double_Window* o
}

void QueryEmployeePage::show()
{
	container->show();
}
