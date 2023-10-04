/*********************************************************
* Автор:   Воронков.А.А                                  *
* Дата:    20.09.2023                                    *
* Название: Циклы с пред и пост условием, вариант 4      * 
* https://onlinegdb.com/hdqSemKILC                        *
**********************************************************/
#include <iostream>

#include <cmath>

using namespace std;

int main() {
    float U, g, d, a, y;
    
    cout << "Введите g = ";
    cin >> g;
    cout << "Введите y = ";
    cin >> y;
    cout << "Введите a = ";
    cin >> a;
    
    while (d < 0.5) {
        d += 0.1;
        U = sqrt( ( (g * d) / 2) + ( (2 * g * a) / (y * d) ) );
        cout << "d = " << d << " U = " << U << endl;
    }
    
    do {
        d += 0.5;
        U = sqrt( ( (g * d) / 2) + ( (2 * g * a) / (y * d) ) );
        cout << "d = " << d << " U = " << U << endl;
    }while (d < 3);

    return 0;
}


