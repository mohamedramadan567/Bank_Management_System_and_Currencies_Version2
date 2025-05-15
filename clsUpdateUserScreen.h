#pragma once
#include"clsScreen.h"
#include<iostream>
#include"clsUser.h"
#include"clsInputValidate.h"
using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
private:
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
        return Permissions;
    }

public:
    static void ShowUpdateUserScreen()
    {
        _DrawShowHeader("\t Update User Screen");
        string UserName = "";

        cout << "\Please Enter User Name: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);
        
        cout << "\nAre you sure you want to update this User y/n? ";
        char Answer = 'n';
        Answer = clsInputValidate::ReadYandN();

        if (Answer)
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";

            _ReadUserInfo(User1);

            clsUser::enSaveResults SaveResult;

            SaveResult = User1.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";
                _PrintUser(User1);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }
        }
    }

};

