/*********************************************************
* Автор:   Воронков.А.А                                  *
* Дата:    20.10.2023                                    *
* Название: Использование процедур и функций, вариант 4  * 
* https://onlinegdb.com/uKidEikvw                        *
**********************************************************/
#include <iostream>

using namespace std;

void FillArray(double array[], int sizeArray) {
  for (int index = 0; index < sizeArray; ++index) {
    cout << index + 1 << ". ";
    cin  >> array[index];
  }
}

void OutArray(double array[], int sizeArray) {
  cout << "[";
  
  for (int index = 0; index < sizeArray; ++index) {
    cout << " " << array[index];
  }
  
  cout << " ]";
}

double ArithmeticMean(double array[], int sizeArray, int index = 0) {
  double Summ;    
  for (int index = 0; index < sizeArray; ++index) {
      if (array[index] < 0) {
          Summ += array[index];
      } 
  }
  return Summ / sizeArray;
}
      

int main() {
  int k, n;
  
  cout << "Введите количество элементов массива F: ";
  cin  >> k;
  cout << "Введите количество элементов массива G: ";
  cin  >> n;
  cout << endl;
  
  double F[k], G[n];
  
  cout << "Заполните массив F: " << endl;
  FillArray(F, k);
  cout << endl;
  
  cout << "Заполните массив G: " << endl;
  FillArray(G, n);
  cout << endl;

  cout << "Массив F: " << endl;
  OutArray(F, k);
  cout << endl << "Среднее арифметическое отрицательных элементов массива F : " << ArithmeticMean(F, k) << endl << endl;
  
  cout << "Массив G: " << endl;
  OutArray(G, n);
  cout << endl << "Среднее арифметическое отрицательных элементов массива G: " << ArithmeticMean(G, n) << endl << endl;
}












