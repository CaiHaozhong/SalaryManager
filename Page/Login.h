#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include "MainPage.h"
#include "Storage.h"
class Login
{
public:
	static Fl_Double_Window* container;
	static Fl_Button* loginBt;
	static Fl_Button* registerBt;
	static Fl_Input* userNameInput;
	static Fl_Input* pswInput;
public:
	Login(void)
	{
		container = new Fl_Double_Window(314, 204);

		loginBt = new Fl_Button(60, 140, 95, 50, "\347\231\273\351\231\206");
		loginBt->callback((Fl_Callback*)Login::buttonCallback, (void*)(1));

		userNameInput = new Fl_Input(65, 32, 232, 36, "\347\224\250\346\210\267\345\220\215\357\274\232");
		 
		pswInput = new Fl_Input(65, 84, 232, 36, "\345\257\206\347\240\201   \357\274\232");
		
		registerBt = new Fl_Button(180, 140, 95, 50, "\346\263\250\345\206\214");
		registerBt->callback((Fl_Callback*)buttonCallback, (void*)(2));
		
		container->end();
	}
	~Login(void)
	{

	}
	void show()
	{
		container->show();
	}

	static void buttonCallback(Fl_Widget* sender,void* userdata)
	{
		printf("Hello, World!\n");
		Storage* storage = Storage::getInstance();
		string userName = userNameInput->value();
		string password = pswInput->value();
		int t = (int)userdata;
		if(t == 1)
		{
			if(storage->login(UserData(userName,password)))
			{
				sender->parent()->hide();
				MainPage* mainpage = new MainPage;
				mainpage->show();
			}
		}
		else
		{
			if(storage->registerUser(UserData(userName,password)))
			{
				sender->parent()->hide();
				MainPage* mainpage = new MainPage;
				mainpage->show();
			}
		}
	}
};

