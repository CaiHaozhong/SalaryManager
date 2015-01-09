#include "Login.h"
#include "AddEmployeePage.h"
int main()
{
	AddEmployeePage* a = new AddEmployeePage;
	a->show();
// 	Login* login = new Login;
// 	login->show();
	return Fl::run();
}