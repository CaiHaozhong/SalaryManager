#include "salaryManagePage.h"


//button type
#define SALARY_TYEP_ADD 1
#define GEN_SALARY_CHART 2
#define COMPUTE_AV_SALARY 3
#define ADD_AND_SUB 4
#define DEPART_AV_SALARY 5

//添加工资类别
Fl_Choice* SalaryManagePage:: departNameFC = NULL;
Fl_Choice* SalaryManagePage:: jobNameFC = NULL;
Fl_Input* SalaryManagePage:: salaryTypeIP = NULL;
Fl_Spinner* SalaryManagePage:: moneyFS = NULL;

//生成工资表
Fl_Input* SalaryManagePage:: numIP = NULL;

//部门平均工资
Fl_Choice* SalaryManagePage:: departNameIP02 = NULL;

SalaryManagePage::SalaryManagePage() {
  { 
		Fl_Double_Window* o = new Fl_Double_Window(505, 605, "\345\267\245\350\265\204\347\256\241\347\220\206");
		container = o;
		container->color((Fl_Color)91);
		o->user_data((void*)(this));
		{ 
			  Fl_Group* o = new Fl_Group(40, 40, 425, 230, "\345\267\245\350\265\204\347\261\273\345\210\253");
			  o->box(FL_FLAT_BOX);
			  o->color((Fl_Color)67);
			  {
				  Fl_Choice* o = new Fl_Choice(145, 60, 270, 40, "\351\203\250\351\227\250\345\220\215\347\247\260\357\274\232");
				  departNameFC = o;
				  o->down_box(FL_BORDER_BOX);
				  vector<string> departments = Storage::getInstance()->getAllDepartment();
				  for(int i = 0; i < departments.size(); i++)
					  o->add(departments.at(i).c_str());
				  o->value(0);
				  departNameFC->callback((Fl_Callback*)SalaryManagePage::departmentChoiceChangeCallback,NULL);
				  o->when(FL_WHEN_CHANGED);
			  } 
			  { 
				  Fl_Choice* o = new Fl_Choice(145, 113, 270, 40, "\345\262\227\344\275\215\345\220\215\347\247\260\357\274\232");
				  jobNameFC = o;
				  o->down_box(FL_BORDER_BOX);
				  string currentDepart = departNameFC->text();
				  resetJobInput(currentDepart);
			  } 
			  {  
				  salaryTypeIP = new Fl_Input(145, 168, 150, 40, "\345\267\245\350\265\204\347\261\273\345\210\253\357\274\232");
			  } 
			  { 
				  moneyFS = new Fl_Spinner(345, 171, 65, 40, "\345\267\245\350\265\204\357\274\232");
				  moneyFS->step(0.1);
				  moneyFS->maximum(100000);
			  } 
			  { 
				  Fl_Button * bt = new Fl_Button (195, 220, 120, 40, "\346\267\273\345\212\240");
				  bt->callback((Fl_Callback*)SalaryManagePage::buttonCallback,(void*)SALARY_TYEP_ADD);
			  } 
			  o->end();
		} 
		{ 
			  Fl_Group* o = new Fl_Group(40, 312, 425, 145, "\345\221\230\345\267\245\345\267\245\350\265\204");
			  o->box(FL_FLAT_BOX);
			  o->color((Fl_Color)87);
			  { 
				  numIP = new Fl_Input(145, 338, 270, 40, "\345\221\230\345\267\245\347\274\226\345\217\267\357\274\232");
			  } 
			  { 
				  Fl_Button * bt = new Fl_Button (70, 407, 98, 40, "\347\224\237\346\210\220\345\267\245\350\265\204\350\241\250");
				  bt->callback((Fl_Callback*)SalaryManagePage::buttonCallback,(void*)GEN_SALARY_CHART);
			  } 
			  { 
				  Fl_Button * bt = new Fl_Button (350, 407, 98, 40, "\345\272\224\345\242\236\345\272\224\345\207\217");
				  bt->callback((Fl_Callback*)SalaryManagePage::buttonCallback,(void*)COMPUTE_AV_SALARY);
			  } 
			  { 
				  Fl_Button * bt = new Fl_Button (200, 407, 115, 40, "\350\256\241\347\256\227\345\271\264\345\271\263\345\235\207\345\267\245\350\265\204");
				  bt->callback((Fl_Callback*)SalaryManagePage::buttonCallback,(void*)ADD_AND_SUB);
			  } 
			  o->end();
		} 
		{ 
			  Fl_Group* o = new Fl_Group(40, 492, 425, 88, "\351\203\250\351\227\250\345\267\245\350\265\204");
			  o->box(FL_FLAT_BOX);
			  o->color((Fl_Color)132);
			  { 
				  Fl_Choice* o = new Fl_Choice(120, 512, 224, 40, "\351\203\250\351\227\250\345\220\215\347\247\260\357\274\232");
				  departNameIP02 = o;
				  o->down_box(FL_BORDER_BOX);
			  } 
			  { 
				  Fl_Button * bt = new Fl_Button (362, 512, 98, 40, "\346\237\245\350\257\242\345\271\263\345\235\207\345\267\245\350\265\204");
				  bt->callback((Fl_Callback*)SalaryManagePage::buttonCallback,(void*)DEPART_AV_SALARY);
			  } 
			  o->end();
		} 
		o->end();
  } 
}

void SalaryManagePage::show()
{
	container->show();
}

void SalaryManagePage::buttonCallback( Fl_Widget* sender, void* data )
{
	int btType = (int)data;
	switch (btType)
	{
	case SALARY_TYEP_ADD:
		callback01();
		break;
	case GEN_SALARY_CHART:
		callback02();
		break;
	case COMPUTE_AV_SALARY:
		callback03();
		break;
	case ADD_AND_SUB:
		callback04();
		break;
	case DEPART_AV_SALARY:
		callback05();
		break;
	default:
		break;
	}
}
