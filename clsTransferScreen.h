#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static double _ReadAmount(clsBankClient SourceClient)
	{
		double Amount = 0;

		cout << "\nEnter Transfer Amount? ";
		Amount = clsInputValidate::ReadDblNumber();
		while (Amount < 0)
		{
			cout << "\nInvalid Amount, Enter another Amount? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}

public:
	static void ShowTransferScreen()
	{
		_DrawShowHeader("\t   Trasnfer Screen");

		string AccountNumber1 = "", AccountNumber2 = "";

		cout << "\nPlease Enter Account Number To Transfer From: ";
		AccountNumber1 = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber1))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber1 = clsInputValidate::ReadString();
		}

		clsBankClient SourceClient = clsBankClient::Find(AccountNumber1);
		_PrintClient(SourceClient);



		cout << "\n\nPlease Enter Account Number To Transfer To: ";
		AccountNumber2 = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber2) || AccountNumber1 == AccountNumber2)
		{
			cout << "\nAccount number is NOT found or Invalid, choose another one: ";
			AccountNumber2 = clsInputValidate::ReadString();
		}

		clsBankClient DestinationClient = clsBankClient::Find(AccountNumber2);
		_PrintClient(DestinationClient);

		double Amount = _ReadAmount(SourceClient);
		
		char Answer = 'n';
		cout << "\nAre you sure you want to perform this operation? y/n?";
		Answer = clsInputValidate::ReadYandN();
		if (Answer)
		{
			if (SourceClient.Transfer(DestinationClient, Amount))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Failed\n";
			}
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};