#pragma once
#include"clsScreen.h"
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;

class clsTransactionsScreen : protected clsScreen
{
    enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, 
        eTrasnfer = 4, eTransferLog = 5, eShowMainMenue = 6 };


    static short _ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6?");
        return Choice;
    }


    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();        
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransfersLogListScreen()
    {
        clsTransferLogScreen::ShowTranferLogScreen();
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...\n";
        system("pause>0");
        ShowTransactionsMenue();
    }

    static void _PerfromMainMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eTrasnfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eTransferLog:
        {
            system("cls");
            _ShowTransfersLogListScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
            break;
        }
        }
    }



public:
    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRigths(clsUser::enPermissions::pTranactions))
        {
            return;
        }
        system("cls");
        _DrawShowHeader("\t  Transactions Screen");
        cout << setw(37) << "" << "============================================\n";
        cout << setw(37) << "" << "\t\t    Transactions Menue \n";
        cout << setw(37) << "" << "============================================\n";
        cout << setw(37) << "" << "\t[1] Deposit.\n";
        cout << setw(37) << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << "" << "\t[4] Transfer.\n";
        cout << setw(37) << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << "" << "============================================\n";

        _PerfromMainMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
    }

};

