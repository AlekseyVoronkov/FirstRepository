/***********************************************
* Автор:   Воронков.А.А                        *
* Дата:    20.09.2023                          *
* Название: Линейные алгоритмы, вариант 4      * 
* https://onlinegdb.com/yCSE3rwdp             *
************************************************/

#include <iostream>

#include <cmath>

using namespace std;

int main() {
    double K, b, n1, n2, n3, y, a, T1, T2;
    
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите y: ";
    cin >> y;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите T1: ";
    cin >> T1;
    cout << "Введите T2: ";
    cin >> T2;
    
    K = (y-1)/y;
    n1 = 1 / b;
    n2 = ( (T2 - T1) / (T2 + ( (T2 - T1) / ( (y - 1) * log(a) ) ) ) ) ;
    n3 = 1 - K * ((log(b)) / (pow(b, K) -1));
    
    
    cout << " a) - " << 1 - pow(n1, K) 
         << " b) - " << n2 
         << " в) - " << n3;

    return 0;
}



