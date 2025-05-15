#pragma once

#include<iostream>
#include<vector>
using namespace std;

class clsString
{
private:
	string _Value;

public:
	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;


    static short Length(string S)
    {
        return S.length();
    }

    short Length()
    {
        return Length(_Value);
    }

    static short CountWords(string s)
    {
        string delim = " "; // delimiter
        int pos = 0;
        string sWord;
        short CountWords = 0;
        // use find() function to get the position of the delimiters
        while ((pos = s.find(" ")) != std::string::npos)
        {
            sWord = s.substr(0, pos);
            if (sWord != " ")
            {
                CountWords++;
            }
            //erase() until positon and move to next word.
            s.erase(0, pos + delim.length());
        }
        if (s != "")
        {
            CountWords++;
        }
        return CountWords;
    }

    short CountWords()
    {
        return CountWords(_Value);
    }


    static void PrintFirstLetterOfEachWord(string S1)
    {
        bool IsFirstLetter = true;
        cout << "\nFirst Letters of the string: \n";
        for (int i = 0; i < S1.size(); i++)
        {
            if (S1[i] != ' ' && IsFirstLetter)
            {
                cout << S1[i] << endl;
            }
            IsFirstLetter = (S1[i] == ' ' ? true : false);
        }
    }

    void PrintFirstLetterOfEachWord()
    {
        PrintFirstLetterOfEachWord(_Value);
    }


    static string UpperFirstLetterOfEachWord(string S1)
    {
        bool IsFirstLetter = true;
        for (short i = 0; i < S1.size(); i++)
        {
            if (S1[i] != ' ' && IsFirstLetter)
            {
                S1[i] = toupper(S1[i]);

            }
            IsFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return S1;
    }

    void UpperFirstLetterOfEachWord()
    {
        _Value = UpperFirstLetterOfEachWord(_Value);
    }


    static string LowerFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < S1.size(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = tolower(S1[i]);
            }
            isFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return S1;
    }

    void LowerFirstLetterOfEachWord()
    {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }


    static string UpperAllString(string S1)
    {
        for (short i = 0; i < S1.size(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }

    void UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }


    static string LowerAllString(string S1)
    {
        for (short i = 0; i < S1.size(); i++)
        {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }

    void LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

    
    static char InvertLetterCase(char C1)
    {
        return isupper(C1) ? tolower(C1) : toupper(C1);
    }

    static string InvertAllStringLettersCase(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertLetterCase(S1[i]);
        }
        return S1;
    }

    void InvertAllStringLettersCase()
    {
        _Value = InvertAllStringLettersCase(_Value);
    }



    enum enWhatIsSCount { SmallLetters = 1, CapitalLetters = 2, All = 3 };

    short CountLetters(string S, enWhatIsSCount WhatIsCount)
    {
        short Count = 0;
        if (WhatIsCount == enWhatIsSCount::All)
            return S.length();
        for (int i = 0; i < S.length(); i++)
        {
            if (WhatIsCount == enWhatIsSCount::SmallLetters && islower((S[i])))
                Count++;
            else if (WhatIsCount == enWhatIsSCount::CapitalLetters && isupper((S[i])))
                Count++;
        }
        return Count;
    }

    static short CountCapital(string S1)
    {
        short Capital = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (isupper(S1[i]))
                Capital++;
        }
        return Capital;
    }

    short CountCapital()
    {
        return CountCapital(_Value);
    }


    static short CountSmall(string S1)
    {
        short Small = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (islower(S1[i]))
                Small++;
        }
        return Small;
    }

    short CountSmall()
    {
        return CountSmall(_Value);
    }


    static short CountLetter(string S, char Letter, bool MatchCase = true)
    {
        short Count = 0;
        for (short i = 0; i < S.length(); i++)
        {
            if (MatchCase)
            {

                if (S[i] == Letter)
                    Count++;
            }
            else
            {
                if (tolower(S[i]) == tolower(Letter))
                    Count++;
            }

        }
        return Count;
    }

    short CountLetter(char Letter, bool MatchCase = true)
    {
        return CountLetter(_Value, Letter, MatchCase);
    }


    static bool IsVowel(char c)
    {
        c = tolower(c);
        return((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'));
    }

    static short CountVowels(string s)
    {
        short CountVowel = 0;
        for (short i = 0; i < s.size(); i++)
        {
            if (IsVowel(s[i]))
                CountVowel++;
        }
        return CountVowel;
    }

    short CountVowels()
    {
        return CountVowels(_Value);
    }


    static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (MatchCase)
            {
                if (S1[i] == Letter)
                    Counter++;
            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                    Counter++;
            }

        }

        return Counter;
    }

    short  CountSpecificLetter(char Letter, bool MatchCase = true)
    {
        return CountSpecificLetter(_Value, Letter, MatchCase);
    }


    static void PrintVowels(string s)
    {
        cout << "Vowels in String are: ";
        for (short i = 0; i < s.size(); i++)
        {
            if (IsVowel(s[i])) cout << s[i] << "    ";
        }
    }

    void PrintVowels()
    {
        PrintVowels(_Value);
    }


    static void PrintWords(string s)
    {
        string delim = " ";
        int pos = 0;
        string sWord;
        cout << "\nYour string words are: \n\n";
        while ((pos = s.find(" ")) != std::string::npos)
        {
            sWord = s.substr(0, pos);
            if (sWord != " ")
            {
                cout << sWord << endl;
            }
            s.erase(0, pos + delim.length());
        }
        if (s != "")
        {
            cout << s << endl;
        }

    }

    void PrintWords()
    {
        PrintWords(_Value);
    }


    static vector<string>Split(string s, string delim = " ")
    {
        vector<string>vString;
        int pos = 0;
        string sWord;
        // use find() function to get the position of the delimiters
        while ((pos = s.find(delim)) != std::string::npos)
        {
            sWord = s.substr(0, pos);
            if (sWord != " ")
            {
                vString.push_back(sWord);
            }
            //erase() until positon and move to next word.
            s.erase(0, pos + delim.length());
        }
        if (s != "")
        {
            vString.push_back(s);
        }
        return vString;
    }

    vector<string>Split(string delim = " ")
    {
        return Split(_Value, delim);
    }


    static string TrimLeft(string S)
    {
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] != ' ')
            {
                return S.substr(i, S.length() - i);
            }
        }
        return "";
    }

    string TrimLeft()
    {
        return TrimLeft(_Value);
    }

    static string TrimRight(string S)
    {
        for (int i = S.length() - 1; i >= 0; i--)
        {
            if (S[i] != ' ')
            {
                return S.substr(0, i + 1);
            }
        }
        return "";
    }

    string TrimRight()
    {
        return TrimRight(_Value);
    }

    static string Trim(string S)
    {
        return TrimLeft(TrimRight(S));
    }

    string Trim()
    {
        return Trim(_Value);
    }

    
    static string ReverseWordsInString(string S1)
    {
        vector<string> vString;
        string S2 = "";
        vString = Split(S1, " ");

        vector<string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {
            --iter;
            S2 += *iter + " ";
        }
        return S2.substr(0, S2.length() - 1);
    }


    static string JoinString(vector<string>vString, string delim)
    {
        string S = "";
        for (string& s : vString)
        {
            S = S + s + delim;
        }
        return S.substr(0, S.size() - delim.length());
    }

    static string JoinString(string arrString[], int length, string delim)
    {
        string S = "";
        for (int i = 0; i < length; i++)
        {
            S = S + arrString[i] + delim;
        }
        return S.substr(0, S.size() - delim.length());
    }


    static string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string sReplaceTo, bool MatchCase = true)
    {
        vector<string> vString = Split(S1, " ");

        for (string& s : vString)
        {
            if (MatchCase)
            {
                if (s == StringToReplace)
                {
                    s = sReplaceTo;
                }
            }
            else
            {
                if (LowerAllString(s) == LowerAllString(StringToReplace))
                {
                    s = sReplaceTo;
                }
            }
        }

        return JoinString(vString, " ");
    }
    
    string ReplaceWordInStringUsingSplit(string StringToReplace, string sReplaceTo, bool MatchCase = true)
    {
        return ReplaceWordInStringUsingSplit(_Value, StringToReplace, sReplaceTo, MatchCase);
    }


    static string RemovePunctuation(string S1)
    {        
        string S2 = "";
        for (int i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }
        return S2;
    }

    string RemovePunctuation()
    {
        return RemovePunctuation(_Value);
    }
};
