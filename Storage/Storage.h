#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "EmployeeData.h"
#include "UserData.h"
#include "Database.h"
#include "SalaryType.h"
using namespace std;
class Storage
{
private:
	Storage(void):database(NULL)
	{
		database = new SQLite::Database("database.db",SQLITE_OPEN_READWRITE);
		string a = database->getFilename().c_str();
		bool bExists = database->tableExists("DataBaseUser");
	}
	SQLite::Database* database;
public:

	~Storage(void){}
	static Storage* instance;
public:

	static Storage* getInstance()
	{
		if (instance == NULL)
		{
			instance = new Storage;
		}
		return instance;
	}

	bool addNewPerson(const EmployeeData& data){}

	bool login(const UserData& data)
	{
		string sql = "SELECT dataBaseUserPassword FROM DataBaseUser WHERE dataBaseUserName = '" + data.userName + "'";
		string colum;
		try{
			colum = database->execAndGet(sql);
		}catch(std::exception& e)
		{
			std::cout << "SQLite exception: " << "User Not Exits!" << std::endl;
			return false;
		}		
		if(colum == data.password)
			return true;
		return false;
	}

	bool registerUser(const UserData& data)
	{

		string sql = "SELECT dataBaseUserPassword FROM DataBaseUser WHERE dataBaseUserName = '" + data.userName + "'";
		string colum;
		try{
			colum = database->execAndGet(sql);
		}catch(std::exception& e)
		{
			string cm = "'";
			string sql = "INSERT INTO DataBaseUser VALUES ("+ cm + data.userName +"'," + cm + data.password + cm +",1)";
			int ret = database->exec(sql);
			return true;
		}		
		std::cout << "SQLite exception: " << "User has Exited!" << std::endl;
		return false;
	}

	bool addEmployee(const EmployeeData& data)
	{
		string jobNum = database->execAndGet("SELECT Job.jobNum FROM Job WHERE Job.jobName = '" + data.jobName +"'");
		string sql = "INSERT INTO Person VALUES('" + data.personNum + "','" + data.personName + "','" + data.gender + "','" + jobNum + "')";
		try
		{
			database->exec(sql);
		}
		catch (std::exception& e)
		{
			std::cout << "SQLite exception: " << e.what() << std::endl;
			return false;
		}		
		return true;

	}

	const vector<string> getAllDepartment()
	{
		vector<string> ret;
		string sql = "SELECT departmentName FROM Department";
		SQLite::Statement st(*database,sql);
		while (st.executeStep())
		{
			string str = st.getColumn(0);
			ret.push_back(str);
		}
		return ret;
	}

	const vector<string> getJobName(string depart)
	{
		vector<string> ret;
		string sql = "SELECT Job.jobName FROM Department,Job WHERE Department.departmentName = '"+ depart + "' AND Job.departmentNum = Department.departmentNum";
		//std::cout << sql;
		//database->exec(sql);
		SQLite::Statement st(*database,sql);
		//st.bind(1,depart);
		while (st.executeStep())
		{
			string str = st.getColumn(0);
			ret.push_back(str);
		}
		return ret;
	}

	const vector<EmployeeData> queryPersonByName(string name)
	{
		vector<EmployeeData> ret;
		
		string sql = "SELECT Person.personNum, Person.personName, Person.personGender, Job.JobName FROM Person,Job WHERE Person.personName= '"+ name + "' AND Person.personJobNum = Job.jobNum";
		//std::cout << sql;
		//database->exec(sql);
		try{
		SQLite::Statement st(*database,sql);
		//st.bind(1,depart);
		while (st.executeStep())
		{
			string personNum = st.getColumn(0);
			string personName = st.getColumn(1);
			string personGender = st.getColumn(2);
			string JobName = st.getColumn(3);
			ret.push_back(EmployeeData(personNum,personName,JobName,personGender));
		}
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		return ret;
	}

	const vector<EmployeeData> queryPersonByNum(string num)
	{
		vector<EmployeeData> ret;
		string sql = "SELECT Person.personNum, Person.personName, Person.personGender, Job.JobName FROM Person,Job WHERE Person.personNum= '"+ num + "' AND Person.personJobNum = Job.jobNum";
		//std::cout << sql;
		//database->exec(sql);
		try{
			SQLite::Statement st(*database,sql);
			//st.bind(1,depart);
			while (st.executeStep())
			{
				string personNum = st.getColumn(0);
				string personName = st.getColumn(1);
				string personGender = st.getColumn(2);
				string JobName = st.getColumn(3);
				ret.push_back(EmployeeData(personNum,personName,JobName,personGender));
			}
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		return ret;
	}

	bool addSalaryType(const SalaryType& data)
	{
		/*string departNum = database->execAndGet("SELECT Department.departmentNum FROM Department WHERE Department.departmentName = '" + data.departName +"'");*/
		string jobNum = database->execAndGet("SELECT Job.jobNum FROM Job WHERE Job.jobName = '" + data.jobName +"'");
		char money[128];
		sprintf(money,"%lf",data.money);
		string sql = "INSERT INTO Salary VALUES('" + jobNum + "','" + data.salaryType + "'," + string(money) + ")";
		try
		{
			database->exec(sql);
		}
		catch (std::exception& e)
		{
			std::cout << "SQLite exception: " << e.what() << std::endl;
			return false;
		}		
		return true;
	}
};

