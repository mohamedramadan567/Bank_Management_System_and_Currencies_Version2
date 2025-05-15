#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsScreen.h"
#include "clsInputValidate.h"
class clsFindCurrencyScreen : protected clsScreen
{
    enum enChoice { eCode = 1, eCountry = 2 };

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:";
        cout << "\n______________________________\n";
        cout << "\nCountry     : " << Currency.Country();
        cout << "\nCode        : " << Currency.CurrencyCode();
        cout << "\nName        : " << Currency.CurrencyName();
        cout << "\nRate/(1$) = : " << Currency.Rate();
        cout << "\n______________________________";

    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:
    static void ShowFindCurrencyScreen()
    {
        clsScreen::_DrawShowHeader("\t  Find Currency Screen");

        enChoice Answer;
        cout << "\nFind By: [1] Code or [2] Country ? ";
        Answer = enChoice(clsInputValidate::ReadIntNumberBetween(1, 2));
        
        if (Answer == enChoice::eCode)
        {
            string CurrencyCode = "";
            cout << "\n\nPlease Enter CurrencyCode: ";
            CurrencyCode = clsInputValidate::ReadString();

            clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);

            _ShowResults(Currency1);
        }
        else if (Answer == enChoice::eCountry)
        {
            string CountryName = "";
            cout << "\n\nPlease Enter Country Name: ";
            CountryName = clsInputValidate::ReadString();

            clsCurrency Currency1 = clsCurrency::FindByCountry(CountryName);

            _ShowResults(Currency1);
        }

        
        
    }

};

