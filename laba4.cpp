/*********************************************************
* Автор:   Воронков.А.А                                  *
* Дата:    11.10.2023                                    *
* Название: Обработка массивов, вариант 4                * 
* https://onlinegdb.com/3Nm4xCrkS                        *
**********************************************************/
#include <iostream>
using namespace std;

int main() {
    
    int n, Summa, elm, i, j;

    cout << "Введите колличество строк и столбцов = ";
    cin >> n;
    cout << "Введите элементы матрицы = " << endl;
    
    int matrix [n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "i=" << i << " j=" << j << "  ";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << " " << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (Summa = i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (i < j and matrix [i][j] > 0) {
                Summa += matrix [i][j];
                elm += 1;
            }
        }
    }

    cout << "Кол-во элементов над главной диагональю = " << elm << endl;
    cout << "Сумма положительных элементов матрицы над главной диагональю = " << Summa << endl;

    return 0;
}
