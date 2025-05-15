#pragma once
#include"clsScreen.h"
#include<iostream>
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"Global.h"
class clsLoginScreen : protected clsScreen
{
private:
	static void _Login()
	{
		bool LoginFailed = false;
		string Username, Password;
		short trials = 3;
		
		do
		{
			if (LoginFailed)
			{
				trials--;
				cout << "\nInvalid Username/Password!";
				cout << "\nYou have " << trials << " Trials to login.\n\n";

				if (!trials)
				{
					cout << "\nYou are Locked after 3 failed trials\n";
					exit(0);
				}
			}
			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();
			
		} while (LoginFailed);

		CurrentUser.RegisterLogIn();

		clsMainScreen::ShowMainMenue();
	}

public:
	static void ShowLoginScreen()
	{
		system("cls");
		_DrawShowHeader("\t     Login Screen");
		_Login();
	}
};

