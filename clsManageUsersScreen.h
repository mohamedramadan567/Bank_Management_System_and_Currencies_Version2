#pragma once
#include"clsScreen.h"
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen
{
    enum enManageUsersMenueOptions
    {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short _ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6?");
        return Choice;
    }


    static void _ShowListUsersScreen()
    {
        //cout << "\nList Users Screen Will be here...";
        clsUsersListScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        //cout << "\nAdd New User Screen Will be here...";
        clsAddNewUserScreen::ShowAddNewUser();
        
    }

    static void _ShowDeleteUserScreen()
    {
        //cout << "\nDelete User Screen Will be here...";
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        //cout << "\nUpdate User Screen Will be here...";
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        //cout << "\nFind User Screen Will be here...";
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...\n";
        system("pause>0");
        ShowManageUsersMenue();
    }


    static void _PerfromManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
    {
        switch (ManageUsersMenueOption)
        {
            case enManageUsersMenueOptions::eListUsers:
            {
                system("cls");
                _ShowListUsersScreen();
                _GoBackToManageUsersMenue();
                break;
            }
            case enManageUsersMenueOptions::eAddNewUser:
            {
                system("cls");
                _ShowAddNewUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }
            case enManageUsersMenueOptions::eDeleteUser:
            {
                system("cls");
                _ShowDeleteUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }
            case enManageUsersMenueOptions::eUpdateUser:
            {
                system("cls");
                _ShowUpdateUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }
            case enManageUsersMenueOptions::eFindUser:
            {
                system("cls");
                _ShowFindUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }
            case enManageUsersMenueOptions::eMainMenue:
            {
                //do nothing here the main screen will handle it :-) ;
                break;
            }
        }
    }



public:
    static void ShowManageUsersMenue()
    {
        if (!CheckAccessRigths(clsUser::enPermissions::pManageUsers))
        {
            return;
        }
        system("cls");
        _DrawShowHeader("\t  Manage Users Screen");
        cout << setw(37) << "" << "============================================\n";
        cout << setw(37) << "" << "\t\t    Manage Users Menue \n";
        cout << setw(37) << "" << "============================================\n";
        cout << setw(37) << "" << "\t[1] List Users.\n";
        cout << setw(37) << "" << "\t[2] Add New User.\n";
        cout << setw(37) << "" << "\t[3] Delete User.\n";
        cout << setw(37) << "" << "\t[4] Update User.\n";
        cout << setw(37) << "" << "\t[5] Find User.\n";
        cout << setw(37) << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << "" << "============================================\n";

        _PerfromManageUsersMenueOption((enManageUsersMenueOptions)_ReadManageUsersMenueOption());
    }

};

