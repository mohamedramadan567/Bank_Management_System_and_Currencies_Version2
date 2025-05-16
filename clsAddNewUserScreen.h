#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include"clsScreen.h"

class clsAddNewUserScreen : protected clsScreen
{
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter User Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permissions: ";
        User.Permissions = _ReadPermissionsToSet();


    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUsername    : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {
        int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo you want to give full access? y/n? ";
        Answer = clsInputValidate::ReadYandN();

        if (Answer)
        {
            return -1;
        }

        cout << "\nDo you want to give access to: \n";

        // Show Client List
        cout << "\nShow Client List? y/n? ";
        Answer = clsInputValidate::ReadYandN();
        if (Answer)
        {
            Permissions += clsUser::enPermissions::pListClients;
        }

        // Add New Client
        cout << "\nAdd New Client? y/n? ";
        Answer = clsInputValidate::ReadYandN();
        if (Answer)
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        // Delete Client
        cout << "\nDelete Client? y/n? ";
        Answer = clsInputValidate::ReadYandN();
        if (Answer)
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        // Update Client
        cout << "\nUpdate Client? y/n? ";
        Answer = clsInputValidate::ReadYandN();
        if (Answer)
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        // Find Client
        cout << "\nFind Client? y/n? ";
        Answer = clsInputValidate::ReadYandN();
        if (Answer)
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        // Transactions
        cout << "\nTransactions? y/n? ";
        Answer = clsInputValidate::ReadYandN();
        if (Answer)
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        Answer = clsInputValidate::ReadYandN();
        if (Answer)
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nLogin Register? y/n? ";
        Answer = clsInputValidate::ReadYandN();
        if (Answer)
        {
            Permissions += clsUser::enPermissions::pLoginRegister;
        }

        cout << "\nCurrency Exchange? y/n? ";
        Answer = clsInputValidate::ReadYandN();
        if (Answer)
        {
            Permissions += clsUser::enPermissions::pCurrencyExchange;
        }

        return Permissions;
    }


public:
    static void ShowAddNewUser()
    {
        _DrawShowHeader("\t  Add New User Screen");

        string UserName = "";
        cout << "\nPlease Enter Username: ";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName is already used, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
        
        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError User was not saved because Username is used!\n";
            break;

        }
        }
    }
};

