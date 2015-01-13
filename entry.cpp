#include "Login.h"
#include "AddEmployeePage.h"
#include "queryEmployeePage.h"
#include "salaryManagePage.h"
int main()
{
// 	QueryEmployeePage* a = new QueryEmployeePage;
// 	a->show();
	Login* login = new Login;
	login->show();
	return Fl::run();
}