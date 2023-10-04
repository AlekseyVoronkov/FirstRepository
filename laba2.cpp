/*********************************************************
* Автор:   Воронков.А.А                                  *
* Дата:    20.09.2023                                    *
* Название: Циклы с пред и пост условием, вариант 4      * 
* https://onlinegdb.com/monmmwULe                        *
**********************************************************/
#include <iostream>

#include <cmath>

using namespace std;

int main() {
    float U, g, d, a, y;
    
    g = 9.80665;
    a = 0.074;
    y = 1;
    
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


