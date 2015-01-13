#pragma once
#include <string>
using namespace std;
class SalaryType
{
public:
	SalaryType(string a, string b, string c, double d):departName(a),salaryType(b),jobName(c),money(d)
	{		
		additionDate = "";
	}
	~SalaryType(void){}
public:
	string departName;	
	string salaryType;
	string jobName;
	double money;
	string additionDate;

};

