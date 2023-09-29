/*********************************************************
* Автор:   Воронков.А.А                                  *
* Дата:    20.09.2023                                    *
* Название: Циклы с пред и пост условием, вариант 4      * 
* https://onlinegdb.com/evI0Qeyw7P                        *
**********************************************************/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float U, g, d, a, y;
    
    d = 0.1;
    cout << "Введите a = ";
    cin >> a;
    cout << "Введите g = ";
    cin >> g;
    cout << "Введите y = ";
    cin >> y;
    
    while (d < 3) {
        U = sqrt(((g * d) / 2) + ((2 * g * a) / (y * d)));
        cout << "d = " << d << " U = " << U << "     ";
        d += 0.1;
    }

    return 0;
}
