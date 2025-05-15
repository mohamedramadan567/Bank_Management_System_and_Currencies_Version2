#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsDate.h"
#include "Global.h"

using namespace std;


class clsScreen
{
protected:
	static void _DrawShowHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t  " << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t  " << SubTitle;
		}
		cout << "\n\t\t\t\t\t______________________________________\n";

		cout << "\n\t\t\t\t\tUser: " << CurrentUser.GetUserName() << "\n";
		cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";

	}

	static bool CheckAccessRigths(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t  " << "Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t______________________________________\n";
			return false;
		}
		else
			return true;
	}
};

