#include "Login.h"
#include "AddEmployeePage.h"
#include "queryEmployeePage.h"
#include "salaryManagePage.h"
int main()
{
	SalaryManagePage* a = new SalaryManagePage;
	a->show();
// 	Login* login = new Login;
// 	login->show();
	return Fl::run();
}