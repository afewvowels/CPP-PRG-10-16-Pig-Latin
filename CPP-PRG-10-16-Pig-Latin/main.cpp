//
//  main.cpp
//  CPP-PRG-10-16-Pig-Latin
//
//  Created by Keith Smith on 11/5/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that reads a sentence as input and converts each word to "Pig Latin."
//  In one version, to convert a word to Pig Latin, you remove the first letter and place
//  that letter at the end of the word. Then you append the string "ay" to the word. Here
//  is an example:
//
//      English:    I SLEPT MOST OF THE NIGHT
//      Pig Latin:  IAY LEPTSAY OSTMAY FOAY HETAY IGHTNAY
//

#include <iostream>
#include <string>

using namespace std;

string *getString(string *);
string *translateString(string *);
void displayString(string *);

int main()
{
    string *strUserString = nullptr;
    strUserString = new string;
    
    strUserString = getString(strUserString);
    
    strUserString = translateString(strUserString);
    
    displayString(strUserString);
    
    return 0;
}

string *getString(string *strStr)
{
    cout << "Please enter a string to translate into Pig Latin:\n";
    getline(cin, *strStr);
    
    return strStr;
}

string *translateString(string *strStr)
{
    string *strTempWord = nullptr;
    strTempWord = new string;
    
    string *strTempString = nullptr;
    strTempString = new string;
    
    string *strReplacePhrase = nullptr;
    strReplacePhrase = new string;
    *strReplacePhrase = "AY";
    
    char *chrStringFull = nullptr;
    chrStringFull = new char[strStr->length()];
    
    strcpy(chrStringFull, strStr->c_str());
    
    if(!isalpha(chrStringFull[strlen(chrStringFull) - 1]))
        chrStringFull[strlen(chrStringFull) - 1] = '\0';
    
    for (int i = 0 ; i < strStr->length() ; i++)
        chrStringFull[i] = toupper(chrStringFull[i]);
    
    strStr->clear();
    strStr->assign(chrStringFull, strlen(chrStringFull));
    
    for (int i = (strlen(chrStringFull) - 1) ; i >= 0 ; i--)
    {
        if (chrStringFull[i] == ' ')
        {
            *strTempWord = strStr->substr(i + 1, strlen(chrStringFull));
            
            strTempWord->append(*strTempWord, 0, 1);
            strTempWord->append(*strReplacePhrase);
            strTempWord->erase(0, 1);
            
            strStr->resize(i);
            
            strTempString->insert(0, " " + *strTempWord);
        }
        else if (i == 0)
        {
            *strTempWord = strStr->substr(i, strlen(chrStringFull));
            
            strTempWord->append(*strTempWord, 0, 1);
            strTempWord->append(*strReplacePhrase);
            strTempWord->erase(0, 1);
            
            strTempString->insert(0, *strTempWord);
            
            strStr->resize(i);
        }
    }
    
    return strTempString;
}

void displayString(string *strStr)
{
    cout << "Your phrase translated into Pig Latin is:\n";
    cout << *strStr << endl;
}
