/*********************************************************
* Автор:   Воронков.А.А                                  *
* Дата:    27.11.2023                                    *
* Название: Календарь числа                              * 
* https://onlinegdb.com/UXSB9J3yK                        *
**********************************************************/
#include <iostream>

using namespace std;

int main() {
    
    int year;
    
    cout << "Enter the year: ";
    cin >> year;
    cout << endl << " //" << "Calendar for " << year << " year//" << endl << endl;
    
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string monthNames[] = {"January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December"};
    int startingDay = 0;
    
    if (year % 4 == 0) {
        daysInMonth[1] = 29;
    }
    
    for (int month = 0; month < 12; ++month) {
        cout << "         " << monthNames[month] << endl;
        cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;
        
        for (int day = 1; day < daysInMonth[month] + 1; ++day) {
            if (day < 10) {
                cout << " " << day << "  ";
            }
            
            else {
                cout << " " << day << " ";
            }
            
            if (day % 7 == 0) {
            cout << endl;
            }
        }
        cout << endl << endl;
    }

    

    return 0;
}
