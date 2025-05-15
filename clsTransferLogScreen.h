#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"
class clsTransferLogScreen : protected clsScreen
{
    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogrRecord)
    {

        cout << setw(8) << left << "" << "| " << left << setw(22) << TransferLogrRecord.DateTime;
        cout << "| " << left << setw(9) << TransferLogrRecord.SourceAccountNumber;
        cout << "| " << left << setw(9) << TransferLogrRecord.DestinationAccountNumber;
        cout << "| " << left << setw(9) << TransferLogrRecord.Amount;
        cout << "| " << left << setw(12) << TransferLogrRecord.SourceBalance;
        cout << "| " << left << setw(12) << TransferLogrRecord.DestinationBalance;
        cout << "| " << left << setw(10) << TransferLogrRecord.UserName;
    }

public:
	static void ShowTranferLogScreen()
	{
        vector <clsBankClient::stTransferLogRecord> vtransferLogRecord = clsBankClient::GetTransfersLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vtransferLogRecord.size()) + ") Record(s).";

        _DrawShowHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(22) << "Date/Time";
        cout << "| " << left << setw(9) << "s.Acct";
        cout << "| " << left << setw(9) << "d.Acct";
        cout << "| " << left << setw(9) << "Amount";
        cout << "| " << left << setw(12) << "s.Balance";
        cout << "| " << left << setw(12) << "d.Balance";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vtransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vtransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}
};

