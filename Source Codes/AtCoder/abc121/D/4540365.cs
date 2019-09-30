using System;
using System.Collections.Generic;

namespace abc121_d
{
  class Program
  {
    static void Main(string[] args)
    {
      var a = CIn.ReadLong();
      var b = CIn.ReadLong();

      Console.WriteLine(Calc(a - 1) ^ Calc(b));
    }

    static long Calc(long a)
    {
      if (a % 2 == 0)
      {
        return a ^ (a / 2 % 2);
      }
      else
      {
        return (a + 1) / 2 % 2;
      }
    }
  }

  class CIn
  {
    private static readonly Queue<string> fieldBuffer = new Queue<string>();

    public static string Read()
    {
      if (fieldBuffer.Count == 0)
      {
        foreach (var field in Console.ReadLine().Split())
        {
          fieldBuffer.Enqueue(field);
        }
      }

      return fieldBuffer.Dequeue();
    }

    public static int ReadInt() => int.Parse(Read());
    public static long ReadLong() => long.Parse(Read());
    public static double ReadDouble() => double.Parse(Read());

    public static string[] ReadStringArray(long n)
    {
      var array = new string[n];

      for (var i = 0; i < n; i++)
      {
        array[i] = Read();
      }

      return array;
    }

    public static int[] ReadIntArray(long n)
    {
      var array = new int[n];

      for (var i = 0; i < n; i++)
      {
        array[i] = ReadInt();
      }

      return array;
    }

    public static long[] ReadLongArray(long n)
    {
      var array = new long[n];

      for (var i = 0; i < n; i++)
      {
        array[i] = ReadLong();
      }

      return array;
    }
    public static double[] ReadDoubleArray(long n)
    {
      var array = new double[n];

      for (var i = 0; i < n; i++)
      {
        array[i] = ReadDouble();
      }

      return array;
    }
  }
}