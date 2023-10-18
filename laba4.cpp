/*********************************************************
* Автор:   Воронков.А.А                                  *
* Дата:    11.10.2023                                    *
* Название: Обработка массивов, вариант 4                * 
* https://onlinegdb.com/joLJS2YYo                        *
**********************************************************/
#include <iostream>
using namespace std;

int main() {
    
    int rows_colums, Summa, elm, row, column;

    cout << "Введите колличество строк и столбцов = ";
    cin >> rows_colums;
    cout << "Введите элементы матрицы = " << endl;
    
    int matrix [rows_colums][rows_colums];

    for (int row = 0; row < rows_colums; ++row) {
        for (int column = 0; column < rows_colums; ++column) {
            cout << "i=" << row << " j=" << column << "  ";
            cin >> matrix[row][column];
        }
    }

    for (int row = 0; row < rows_colums; ++row) {
        for (int column = 0; column < rows_colums; ++column) {
            cout << " " << matrix[row][column] << " ";
        }
        cout << endl;
    }

    for (Summa = row = 0; row < rows_colums; ++row) {
        for (column = 0; column < rows_colums; ++column) {
            if (row < column and matrix [row][column] > 0) {
                Summa += matrix [row][column];
                elm += 1;
            }
        }
    }

    cout << "Кол-во элементов над главной диагональю = " << elm << endl;
    cout << "Сумма положительных элементов матрицы над главной диагональю = " << Summa << endl;

    return 0;
}


