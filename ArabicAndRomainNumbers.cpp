/*********************************************************
* Автор:   Воронков.А.А                                  *
* Дата:    15.11.2023                                    *
* Название: Арабские числа                               * 
* https://onlinegdb.com/Ymgn-Mrf_                        *
**********************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int romanToArabic(const string romanNumeral) {
    map<char, int>
    romanNumerals = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
        {'V̄', 5000},
        {'X̄', 10000}
    };

    int result = 0;
    int prevValue = 0;

    for (int index = romanNumeral.length() - 1; index >= 0; --index) {
        int currentValue = romanNumerals[romanNumeral[index]];

        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }

        prevValue = currentValue;
    }

    return result;
}

string arabicToRoman(int num) {
    vector<pair<int, string>>
    romanNumerals = {
        {10000, "X̄"},
        {5000, "V̄"},
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

    string result = "";
    int index = 0;

    for (auto numeral : romanNumerals) {
        while (num >= numeral.first) {
            result += numeral.second;
            num -= numeral.first;
        }
    }
 

    return result;
}

int main() {
    
    int num, choise;
    string romanNumeral;
    
    cout << "Pick a option: " << endl;
    cout << "1) From Romain to Arabic" << endl << "2) From Arabic to Romain" << endl << ">>> ";
    cin >> choise;
    
    if (choise == 1) {
        cout << "Enter a Romain number: ";
        cin >> romanNumeral;
        
        int arabicNum = romanToArabic(romanNumeral);
        
        cout << "Arabic numeral: " << arabicNum << endl;
    }
    
    if (choise == 2) {
        cout << "Enter a Arabic number: ";
        cin >> num;

        string romanNumeral = arabicToRoman(num);
        
        cout << "Roman numeral: " << romanNumeral << endl;
    }
    
    if (choise < 1 || choise > 3) {
        cout << "Введите либо 1 либо 2";
    }
    
    return 0;
}
