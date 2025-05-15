#pragma once
#include <iostream>
#include "clsDate.h"
#include <cstdlib> // for RandomNumber fun
#include <time.h> // for run srand
using namespace std;
class clsUtil
{
public:

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }
    
    static void Swap(int& x, int& y)
    {
        int temp;
        temp = x;
        x = y;
        y = temp;
    }

    static void Swap(double& x, double& y)
    {
        double temp;
        temp = x;
        x = y;
        y = temp;
    }

    static void Swap(string& x, string& y)
    {
        string temp;
        temp = x;
        x = y;
        y = temp;
    }

    static void  Swap(clsDate& Date1, clsDate& Date2)
    {

        clsDate TempDate;
        TempDate = Date1;
        Date1 = Date2;
        Date2 = TempDate;

    }

    static enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, digit = 4, MixChars = 5 };
    static char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SmallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        case enCharType::MixChars:
            return GetRandomCharacter((enCharType)RandomNumber(1, 4));
        }
    }

    static string GenerateWord(enCharType CharType, short length)
    {
        string word = "";
        for (int i = 1; i <= length; i++)
        {
            word += GetRandomCharacter(CharType);
        }
        return word;
    }

    static string GenerateKey(enCharType CharType)
    {
        string key = "";
        key += GenerateWord(CharType, 4) + "-";
        key += GenerateWord(CharType, 4) + "-";
        key += GenerateWord(CharType, 4) + "-";
        key += GenerateWord(CharType, 4);
        return key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key[" << i << "] : " << GenerateKey(CharType) << endl;
        }
    }

    static void SuffelArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static void SuffelArray(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {

        for (int i = 0; i < arrLength; i++)
        {

            arr[i] = RandomNumber(From, To);
        }
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short wordLength)
    {

        for (int i = 0; i < arrLength; i++)
        {

            arr[i] = GenerateWord(CharType, wordLength);

        }

    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {

        for (int i = 0; i < arrLength; i++)
        {

            arr[i] = GenerateKey(CharType);

        }

    }
    
    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }

    static string EncryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }

    static string DecryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }

    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }

};

