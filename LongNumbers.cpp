/*********************************************************
* Автор:   Воронков.А.А                                  *
* Дата:    29.11.2023                                    *
* Название: Длинные числа                                * 
* https://onlinegdb.com/rrmRB3LAh7                       *
**********************************************************/
#include <iostream>
#include <iomanip>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;

int main() {
    int choice = 0;
    boost::multiprecision::cpp_int firstNumber;
    boost::multiprecision::cpp_int secondNumber;
    
    cout << "Выберите действие: "
    << endl << "1) - Сложение"
    << endl << "2) - Вычитание"
    << endl << "3) - Целочисленное деление"
    << endl << "4) - Умножение"
    << endl << "5) - Сравнение" << endl;
    cin >> choice;
    
    if (choice > 5 || choice < 1) {
        cout << "Такого действия нет в списке";
    }
    
    cout << "Введите два целочисленных числа: " << endl << "Первое число - ";
    cin >> firstNumber;
    cout << endl << "Второе число - ";
    cin >> secondNumber;
    
    cout << fixed;
    
    if (choice == 1) {
        cout << (firstNumber + secondNumber);
    }
    
    if (choice == 2) {
        cout << (firstNumber - secondNumber);
    }
    
    if (choice == 3) {
        cout << (firstNumber / secondNumber);
    }
    
    if (choice == 4) {
        cout << (firstNumber * secondNumber);
    }
    
    if (choice == 5) {
        if (firstNumber < secondNumber) {
            cout << firstNumber << " < " << secondNumber;  
        }
        
        if (firstNumber > secondNumber) {
            cout << firstNumber << " > " << secondNumber;
        }
        
        if (firstNumber == secondNumber) {
            cout << firstNumber << " = " << secondNumber;
        }
    }
    

    return 0;
}
