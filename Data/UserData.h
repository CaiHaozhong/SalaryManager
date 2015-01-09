#pragma once
#include <string>
using namespace std;
class UserData
{
public:
	UserData(string a, string b):userName(a),password(b){};
	~UserData(void){};
public:
	string userName;
	string password;
	string power;
};

