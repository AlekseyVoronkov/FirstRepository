/*********************************************************
* Автор:   Воронков.А.А                                  *
* Дата:    07.02.2024                                    *
* Название: Базовые понятия языка C#                     * 
* https://onlinegdb.com/1Fh3bVESD                        *
**********************************************************/
using System;
class HelloWorld {
  static void Main() {
      // Task 1
      Console.WriteLine("1. Calculate a^n");
      Console.Write("Enter number a: ");
      int userNumberA = Convert.ToInt32(Console.ReadLine());
      Console.Write("Enter power n: ");
      int userPower = Convert.ToInt32(Console.ReadLine());
      
      int firstTaskResult = userNumberA;
      
      if (userPower == 0) {
          userNumberA = 1;
      } else {
          for (int index = 1; index < userPower; ++index) {
              firstTaskResult *= userNumberA;
          }
      }
      
      Console.WriteLine ($"{userNumberA} ^ {userPower} = {firstTaskResult}");
      
      // Task 2
      Console.WriteLine("2. Find number n from x");
      Console.Write("Enter number x (x >= 100): ");
      string userNumberX = Console.ReadLine();
      string secondTaskResult = userNumberX.Remove(1, 1) + userNumberX[1];
      Console.WriteLine($"Number n = {secondTaskResult}");
  }
}

