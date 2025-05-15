#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"clsString.h"

using namespace std;

class clsCurrency
{
public:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string> vCurrecncyData;
		vCurrecncyData = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrecncyData[0], vCurrecncyData[1], vCurrecncyData[2],
			stof(vCurrecncyData[3]));

	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currecncy, string Seperator = "#//#")
	{

		string CurrencyRecord = "";
		CurrencyRecord += Currecncy.Country() + Seperator;
		CurrencyRecord += Currecncy.CurrencyCode() + Seperator;
		CurrencyRecord += Currecncy.CurrencyName() + Seperator;
		CurrencyRecord += to_string(Currecncy.Rate());

		return CurrencyRecord;

	}

	static  vector <clsCurrency> _LoadCurrenciesDataFromFile()
	{

		vector <clsCurrency> vCurrencies;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsCurrency Cuurency = _ConvertLinetoCurrencyObject(Line);

				vCurrencies.push_back(Cuurency);
			}

			MyFile.close();

		}

		return vCurrencies;

	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencies)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency C : vCurrencies)
			{
				DataLine = _ConvertCurrencyObjectToLine(C);
				MyFile << DataLine << endl;
			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsCurrency> _vCurrencies;
		_vCurrencies = _LoadCurrenciesDataFromFile();

		for (clsCurrency& C : _vCurrencies)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}

		}

		_SaveCurrencyDataToFile(_vCurrencies);

	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	float Rate()
	{
		return _Rate;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}
		return _GetEmptyCurrencyObject();
	}


	static bool IsCurrencyExit(string CurrencyCode)
	{
		clsCurrency C1 = FindByCode(CurrencyCode);
		return(!C1.IsEmpty());
	}


	static vector<clsCurrency>GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}


	float ConvertToUSD(float Amount)
	{
		return (float)Amount / Rate();
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)AmountInUSD * Currency2.Rate();
	}

};

