#pragma once
#include <string>
using namespace std;
class EmployeeData
{
public:
	EmployeeData(string a, string b, string c, string d):personNum(a),personName(b),jobName(c),gender(d){};
	EmployeeData()
	{
		string personNum = "";
		string personName = "";
		string jobName = "";
		string gender = "";
		string departName = "";
	}
	~EmployeeData(void){}
public:
	string personNum;
	string personName;
	string jobName;
	string gender;
	string departName;

};

