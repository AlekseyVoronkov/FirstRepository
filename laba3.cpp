/*********************************************************
* Автор:   Воронков.А.А                                  *
* Дата:    06.10.2023                                    *
* Название: Циклы с ветвлением, вариант 4                * 
* https://onlinegdb.com/QplR4Gi_I                        *
**********************************************************/
#include <iostream>

#include <cmath>

using namespace std;

int main() {
    
    float W, Pe, Re, Ga, A;
    Re = 6.1 * pow(10, 4);
    Ga = 0.9 * pow(10, 5);
    W = 0.1;
    
    while (W < 0.9) {
        A = W * pow(Re, 0.11);
        if (A < 1) {
            Pe = 4.75 * pow(A, 1.4) * pow(Ga, -0.17);
            cout << "1<A| A = " << A 
                 << " Pe = " << Pe 
                 << " W = " << W << endl;
            W += 0.05;
        }

        if (A > 1) {
            Pe = 2.25 * pow(10, -3) * pow(A, -3.3) * pow(Ga, 0.29);
            cout << "1>A| A = " << A 
                 << " Pe = " << Pe 
                 << " W = " << W << endl;
            W += 0.05;
        }
    }
    return 0;
}
