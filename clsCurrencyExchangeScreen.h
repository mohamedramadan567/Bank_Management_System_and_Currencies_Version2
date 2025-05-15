#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include"clsInputValidate.h"
#include "clsCurrency.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"


class clsCurrencyExchangeScreen : protected clsScreen
{
    enum enCurrencyExchangeMenueOptions
    {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalculator = 4, eMainMenue = 5
    };

    static short _ReadCurrencyExchangeMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5?");
        return Choice;
    }

    static void _ShowListCurrenciesScreen()
    {
        //cout << "\nList Currencies Screen Will be here...";
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        //cout << "\nFind Currency Screen Will be here...";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();

    }

    static void _ShowUpdateRateScreen()
    {
        //cout << "\nUpdate Rate Screen Will be here...";
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        //cout << "\nCurrency Calculator Screen Will be here...";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _GoBackToCurrencyExchangeMenue()
    {
        cout << "\n\nPress any key to go back to Currencies Menue...\n";
        system("pause>0");
        ShowCurrencyExchangeMenue();
    }

    static void _PerfromCurrencyExchangeMenueOption(enCurrencyExchangeMenueOptions CurrencyExchangeMenueOption)
    {
        switch (CurrencyExchangeMenueOption)
        {
        case enCurrencyExchangeMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExchangeMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExchangeMenueOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExchangeMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExchangeMenueOptions::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
            break;
        }
        }
    }
public:

    static void ShowCurrencyExchangeMenue()
    {
        /*if (!CheckAccessRigths(clsUser::enPermissions::pManageUsers))
        {
            return;
        }*/
        system("cls");
        _DrawShowHeader("   Currency Exchange Main Screen");
        cout << setw(37) << "" << "============================================\n";
        cout << setw(37) << "" << "\t\t  Currency Exchange Menue \n";
        cout << setw(37) << "" << "============================================\n";
        cout << setw(37) << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << "" << "============================================\n";

        _PerfromCurrencyExchangeMenueOption((enCurrencyExchangeMenueOptions)_ReadCurrencyExchangeMenueOption());
    }
};

