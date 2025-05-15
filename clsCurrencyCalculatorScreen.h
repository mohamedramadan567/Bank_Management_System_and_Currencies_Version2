#pragma once
#include"clsScreen.h"
#include<iostream>
#include"clsCurrency.h"
#include"clsInputValidate.h"
using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
	static float _ReadAmount()
	{
		float Amount = 0;

		cout << "\nEnter Amount to Exchange: ";

		Amount = clsInputValidate::ReadFloatNumber();

		return Amount;
	}

	static clsCurrency _GetCurrency(string Message)
	{
		cout << Message << "\n";
		
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExit(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card")
	{
		cout << "\n" << Title << ":";
		cout << "\n______________________________\n";
		cout << "\nCountry     : " << Currency.Country();
		cout << "\nCode        : " << Currency.CurrencyCode();
		cout << "\nName        : " << Currency.CurrencyName();
		cout << "\nRate/(1$) = : " << Currency.Rate();
		cout << "\n______________________________\n";

	}

	static void _PrintCalculationResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1, "Convert From");
		cout << Amount << " " << Currency1.CurrencyCode() << " = " << Currency1.ConvertToUSD(Amount) << " USD";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\n\nConverting from USD to:\n";

		_PrintCurrencyCard(Currency2, "To");
		cout << Amount << " " << Currency1.CurrencyCode() << " = " << 
			Currency1.ConvertToOtherCurrency(Amount, Currency2) << " " << Currency2.CurrencyCode();

	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';
		while (Continue == 'Y' || Continue == 'y')
		{
			system("cls");

			clsScreen::_DrawShowHeader("\tCurrency Calculator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\n\nPlease Enter Currency1 Code: ");
				 
			clsCurrency CurrencyTo = _GetCurrency("\n\nPlease Enter Currency2 Code: ");

			float Amount = _ReadAmount();

			_PrintCalculationResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n?";
			cin >> Continue;
		}
	}
};

