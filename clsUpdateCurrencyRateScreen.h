#pragma once
#include"clsScreen.h"
#include<iostream>
#include"clsCurrency.h"
#include"clsInputValidate.h"
using namespace std;

class clsUpdateCurrencyRateScreen : protected clsScreen
{
    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        float NewRate = 0;

        NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
    }

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:";
        cout << "\n______________________________\n";
        cout << "\nCountry     : " << Currency.Country();
        cout << "\nCode        : " << Currency.CurrencyCode();
        cout << "\nName        : " << Currency.CurrencyName();
        cout << "\nRate/(1$) = : " << Currency.Rate();
        cout << "\n______________________________\n";

    }

public:
    static void ShowUpdateCurrencyRateScreen()
    {
        clsScreen::_DrawShowHeader("\t  Update Currency Screen");

        string CurrencyCode = "";

        cout << "\n\nPlease Enter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExit(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        
        _PrintCurrency(Currency);
            
        char Answer = 'n';
        
        cout << "\n\nAre you sure you want to update the rate of this Currency y/n? ";
        Answer = clsInputValidate::ReadYandN();

        if (Answer)
        {
            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";
        
        
            Currency.UpdateRate(_ReadRate());
            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(Currency);
        
        }
        
        
        


    }

};

