#pragma once
#include <string>
using namespace std;
class AlterationData
{
public:
	AlterationData(string d,string a, double b, string c):personNum(d),alterationName(a),alterationMoney(b),alterationDay(c){};
	~AlterationData(void){};
public:
	string personNum;
	string alterationName;
	double alterationMoney;
	string alterationDay;
};

