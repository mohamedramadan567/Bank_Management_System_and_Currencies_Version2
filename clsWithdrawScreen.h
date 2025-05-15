#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

class clsWithdrawScreen : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}
public:
	static void ShowWithdrawScreen()
	{
		clsScreen::_DrawShowHeader("\t  Withdraw Screen");
		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\Client with[" << AccountNumber << "] does not exist.";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "Please enter Withdraw amount? ";
		Amount = clsInputValidate::ReadDblNumberBetween(0, Client1.AccountBalance);

		char answer = 'n';
		cout << "\nAre you sure you want Perform this transaction? Y/N? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			if (Client1.Withdraw(Amount))
			{

				cout << "\nAmount Withdrew Successfully.\n";
				cout << "\nNew Balance Is: " << Client1.AccountBalance;
			}
			else
			{
				cout << "\nCannont withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to withdraw is: " << Amount;
				cout << "\nYour Balance is: " << Client1.AccountBalance;
			}
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}
};

