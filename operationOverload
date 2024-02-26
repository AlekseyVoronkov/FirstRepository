using System;
using System.Numerics;
using System.Xml;

namespace WindowsFormsApp3
{

  class DeepStructure
  {
    public int RandomThing { get; set; }
    public int AnotherRandomThing { get; set; }
  }
  class SquareMatrix
  {
    public int[,] matrix;
    public int size;
    public DeepStructure deepStructure;

    public SquareMatrix()
    {
      deepStructure = new DeepStructure();
      Random random = new Random();
      size = random.Next(2, 10);
      matrix = new int[size, size];

      for (int rowIndex = 0; rowIndex < size; ++rowIndex)
      {
        for (int columnIndex = 0; columnIndex < size; ++columnIndex)
        {
          matrix[rowIndex, columnIndex] = random.Next(1, 10);
        }
      }
    }
    public SquareMatrix(int size)
    {
      this.size = size;
      Random random = new Random();
      matrix = new int[size, size];

      for (int rowIndex = 0; rowIndex < size; ++rowIndex)
      {
        for (int columnIndex = 0; columnIndex < size; ++columnIndex)
        {
          matrix[rowIndex, columnIndex] = random.Next(1, 10);
        }
      }
    }
    class MatrixClone : SquareMatrix, ICloneable
    {
      public object Clone()
      {
        MatrixClone result = new MatrixClone();
        {
          result.size = this.size;
          result.matrix = this.matrix;
          result.deepStructure.RandomThing = this.deepStructure.RandomThing;
          result.deepStructure.AnotherRandomThing = this.deepStructure.AnotherRandomThing;
        };

        return result;
      }
    }

    public class InvalidDepartmentException : System.Exception
    {
      public InvalidDepartmentException()
      : base() { }
      public InvalidDepartmentException(string message)
      : base(message) { }
      public InvalidDepartmentException
      (string message, System.Exception inner)
      : base(message, inner) { }

    }

    public static SquareMatrix operator +(SquareMatrix matrix1, SquareMatrix matrix2)
    {
      SquareMatrix result = new SquareMatrix(matrix1.size);

      for (int rowIndex = 0; rowIndex < matrix1.size; ++rowIndex)
      {
        for (int columnIndex = 0; columnIndex < matrix1.size; ++columnIndex)
        {
          result.matrix[rowIndex, columnIndex] = matrix1.matrix[rowIndex, columnIndex] + matrix2.matrix[rowIndex, columnIndex];
        }
      }

      return result;
    }

    public static SquareMatrix operator *(SquareMatrix matrix1, SquareMatrix matrix2)
    {
      SquareMatrix resultMatrix = new SquareMatrix(matrix1.size);

      for (int matrix1rowIndex = 0; matrix1rowIndex < matrix1.size; ++matrix1rowIndex)
      {
        for (int matrix2columnIndex = 0; matrix2columnIndex < matrix2.size; ++matrix2columnIndex)
        {
          int currentPositionValue = 0;

          for (int partNumber = 0; partNumber < matrix1.size; ++partNumber)
          {
            currentPositionValue += matrix1.matrix[matrix1rowIndex, matrix2columnIndex];
          }

          resultMatrix.matrix[matrix1rowIndex, matrix2columnIndex] = currentPositionValue;
        }
      }

      return resultMatrix;
    }

    public static bool operator <(SquareMatrix matrix1, SquareMatrix matrix2)
    {
      if (matrix1.size < matrix2.size)
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    public static bool operator >(SquareMatrix matrix1, SquareMatrix matrix2)
    {
      if (matrix1.size > matrix2.size)
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    public static bool operator <=(SquareMatrix matrix1, SquareMatrix matrix2)
    {
      if (matrix1.size <= matrix2.size)
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    public static bool operator >=(SquareMatrix matrix1, SquareMatrix matrix2)
    {
      if (matrix1.size >= matrix2.size)
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    public static bool operator ==(SquareMatrix matrix1, SquareMatrix matrix2)
    {
      if (matrix1.size == matrix2.size)
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    public static bool operator !=(SquareMatrix matrix1, SquareMatrix matrix2)
    {
      if (matrix1.size != matrix2.size)
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    public static implicit operator int[,](SquareMatrix matrix1)
    {
      return matrix1.matrix;
    }

    public static explicit operator int(SquareMatrix matrix1)
    {
      return matrix1.matrix.GetLength(0);
    }

    public static bool operator true(SquareMatrix matrix1)
    {
      return matrix1.size != 1;
    }

    public static bool operator false(SquareMatrix matrix1)
    {
      return matrix1.size == 1;
    }

    public SquareMatrix GetStepaMatrix(int row, int column)
    {
      SquareMatrix result = new SquareMatrix(size - 1);

      for (int columnIndex = 0; columnIndex < size - 1; ++columnIndex)
      {
        for (int rowIndex = 0; rowIndex < size - 1; ++rowIndex)
        {
          result.matrix[rowIndex, columnIndex] = columnIndex < column ?
              rowIndex < row ?
              matrix[rowIndex, columnIndex] :
              matrix[rowIndex + 1, columnIndex] :
              rowIndex < row ?
              matrix[rowIndex, columnIndex + 1] :
              matrix[rowIndex + 1, columnIndex + 1];

        }
      }

      return result;
    }

    public int FindDeterminant()
    {
      if (size == 2)
      {
        int determinant = matrix[0, 0] * matrix[1, 1] - matrix[1, 0] * matrix[0, 1];

        return determinant;
      }

      int result = 0;

      for (int columnIndex = 0; columnIndex < size; ++columnIndex)
      {
        result += (columnIndex % 2 == 1 ? 1 : -1) * matrix[1, columnIndex] * GetStepaMatrix(1, columnIndex).FindDeterminant();
      }

      return result;
    }

    public SquareMatrix FindTransposed()
    {
      var result = new SquareMatrix(size);

      for (int rowIndex = 0; rowIndex < size; ++rowIndex)
      {
        for (int columnIndex = 0; columnIndex < size; ++columnIndex)
        {
          result.matrix[rowIndex, columnIndex] = matrix[columnIndex, rowIndex];
        }
      }

      return result;
    }

    public SquareMatrix FindInversedMatrix()
    {
      var result = new SquareMatrix(size);

      if (size == 2)
      {
        result.matrix[0, 0] = -matrix[1, 1];
        result.matrix[0, 1] = matrix[1, 0];
        result.matrix[1, 0] = matrix[0, 1];
        result.matrix[1, 1] = -matrix[0, 0];

        Console.WriteLine(FindDeterminant());

        return result.FindTransposed();
      }

      for (int rowIndex = 0; rowIndex < size; ++rowIndex)
      {
        for (int collumnIndex = 0; collumnIndex < size; ++collumnIndex)
        {
          result.matrix[rowIndex, collumnIndex] = ((collumnIndex + rowIndex) % 2 == 0 ? 1 : -1) * GetStepaMatrix(rowIndex, collumnIndex).FindDeterminant();
        }
      }

      return result.FindTransposed();
    }

    public override string ToString()
    {
      string result = "";

      for (int rowIndex = 0; rowIndex < matrix.GetLength(0); rowIndex++)
      {
        for (int columnIndex = 0; columnIndex < matrix.GetLength(1); columnIndex++)
        {
          result += $" {matrix[rowIndex, columnIndex]}  ";
        }
        result += "\n";
      }

      return result;
    }

    public override bool Equals(object otherObject)
    {
      bool result = false;

      if (otherObject is MatrixClone)
      {
        var currentObject = otherObject as MatrixClone;

        if (currentObject.ToString() == this.ToString())
        {
          result = true;
        }
      }

      return result;
    }

    public int CompareTo(SquareMatrix other)
    {
      if (other == null)
      {
        return 1;
      }

      for (int rowIndex = 0; rowIndex < matrix.GetLength(0); ++rowIndex)
      {
        for (int columnIndex = 0; columnIndex < matrix.GetLength(1); ++columnIndex)
        {
          if (matrix[rowIndex, columnIndex] != other.matrix[rowIndex, columnIndex])
          {
            return matrix[rowIndex, columnIndex].CompareTo(other.matrix[rowIndex, columnIndex]);
          }
        }
      }

      return 0;
    }

    public override int GetHashCode()
    {
      Random random = new Random();
      int degree = random.Next(2, 10);
      int result = 1;

      for (int currentDegree = 1; currentDegree <= degree; ++currentDegree)
      {
        result *= size;
      }

      return random.Next(2, result);
    }

    public void PrintMatrix()
    {
      for (int rowIndex = 0; rowIndex < matrix.GetLength(0); ++rowIndex)
      {
        for (int columnIndex = 0; columnIndex < matrix.GetLength(1); ++columnIndex)
        {
          Console.Write(matrix[rowIndex, columnIndex] + " ");
        }
        Console.WriteLine();
      }
    }

  }


  static class Program
  {
    static void Main()
    {
      SquareMatrix matrix = new SquareMatrix(3);
      SquareMatrix matrix1 = new SquareMatrix(3);
      SquareMatrix matrix2 = new SquareMatrix(3);
      bool neverEndingSuffering = true;
      int userChoice;

      Console.WriteLine("First matrix");
      matrix1.PrintMatrix();
      Console.WriteLine("Second matrix");
      matrix2.PrintMatrix();
      Console.WriteLine();
      Console.WriteLine("There is no such thing as free will, user: ");
      Console.WriteLine("Make a choice, user: ");
      Console.WriteLine("1. +; 2. *; 3. <; 4. >; 5. <=; 6. >=; \n" +
                       "7. ==; 8. !=; 9.FindDeterminant; \n" +
                       "10. FindTransposed; 11. FindInversedMatrix; 12. Let me be free pls");

      while (neverEndingSuffering == true)
      {
        userChoice = int.Parse(Console.ReadLine());

        switch (userChoice)
        {
          case 1:
            Console.WriteLine(matrix1 + matrix2);
            break;

          case 2:
            Console.WriteLine(matrix1 * matrix2);
            break;

          case 3:
            Console.WriteLine(matrix1 < matrix2);
            break;

          case 4:
            Console.WriteLine(matrix1 > matrix2);
            break;

          case 5:
            Console.WriteLine(matrix1 <= matrix2);
            break;

          case 6:
            Console.WriteLine(matrix1 >= matrix2);
            break;

          case 7:
            Console.WriteLine(matrix1 == matrix2);
            break;

          case 8:
            Console.WriteLine(matrix1 != matrix2);
            break;

          case 9:
            var determinant = matrix1.FindDeterminant();
            Console.WriteLine(determinant);
            break;

          case 10:
            var transposedMatrix = matrix1.FindTransposed();
            transposedMatrix.PrintMatrix();
            break;

          case 11:
            var InvertedMatrix = matrix1.FindInversedMatrix();
            InvertedMatrix.PrintMatrix();
            break;

          case 12:
            Environment.Exit(0);
            break;
        }
      }

    }
  }
}
