using System;
using System.Collections.Generic;

namespace abc119_d
{
  class Program
  {
    private static int a, b, q;
    private static long[] s, t, x;

    static void Main(string[] args)
    {
      a = ConsoleInput.ReadAsInt();
      b = ConsoleInput.ReadAsInt();
      q = ConsoleInput.ReadAsInt();

      s = ConsoleInput.ReadAsLongArray(a);
      t = ConsoleInput.ReadAsLongArray(b);
      x = ConsoleInput.ReadAsLongArray(q);

      for (int i = 0; i < q; i++)
      {
        long ans = -1;

        var sEast = ~Array.BinarySearch<long>(s, x[i]);
        var tEast = ~Array.BinarySearch<long>(t, x[i]);

        foreach (int sIndex in new int[] { sEast - 1, sEast })
        {
          foreach (int tIndex in new int[] { tEast - 1, tEast })
          {
            if (sIndex >= 0 && sIndex < a && tIndex >= 0 && tIndex < b)
            {
              var distance = Math.Min(Math.Abs(s[sIndex] - x[i]) + Math.Abs(t[tIndex] - s[sIndex]), Math.Abs(t[tIndex] - x[i]) + Math.Abs(s[sIndex] - t[tIndex]));

              if (ans == -1 || distance < ans)
              {
                ans = distance;
              }
            }
          }
        }

        Console.WriteLine(ans);
      }
    }
  }

  class ConsoleInput
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

    public static int ReadAsInt() => int.Parse(Read());
    public static long ReadAsLong() => long.Parse(Read());
    public static double ReadAsDouble() => double.Parse(Read());

    public static string[] ReadAsStringArray(long n)
    {
      var array = new string[n];

      for (var i = 0; i < n; i++)
      {
        array[i] = Read();
      }

      return array;
    }

    public static int[] ReadAsIntArray(long n)
    {
      var array = new int[n];

      for (var i = 0; i < n; i++)
      {
        array[i] = ReadAsInt();
      }

      return array;
    }

    public static long[] ReadAsLongArray(long n)
    {
      var array = new long[n];

      for (var i = 0; i < n; i++)
      {
        array[i] = ReadAsLong();
      }

      return array;
    }
    public static double[] ReadAsDoubleArray(long n)
    {
      var array = new double[n];

      for (var i = 0; i < n; i++)
      {
        array[i] = ReadAsDouble();
      }

      return array;
    }
  }
}