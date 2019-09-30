using System;
using System.Collections.Generic;

namespace AtCoder
{
  class Program
  {
    private static int n, a, b, c;
    private static int[] l;
    private static readonly char[] elements = { 'a', 'b', 'c', 'x' };
    private static int ans = -1;

    static void Main(string[] args)
    {
      n = ConsoleInput.ReadAsInt();
      a = ConsoleInput.ReadAsInt();
      b = ConsoleInput.ReadAsInt();
      c = ConsoleInput.ReadAsInt();
      l = ConsoleInput.ReadAsIntArray(n);

      DFS(new List<char>());
      Console.WriteLine(ans);
    }
    private static void DFS(List<char> pattern)
    {
      if (pattern.Count < n)
      {
        foreach (var e in elements)
        {
          var list = new List<char>(pattern);
          list.Add(e);
          DFS(list);
        }
      }
      else
      {
        Calc(pattern);
      }
    }

    private static void Calc(List<char> pattern)
    {
      var aLength = 0;
      var bLength = 0;
      var cLength = 0;
      var mp = -30;

      for (int i = 0; i < pattern.Count; i++)
      {
        switch (pattern[i])
        {
          case 'a':
            aLength += l[i];
            mp += 10;
            break;
          case 'b':
            bLength += l[i];
            mp += 10;
            break;
          case 'c':
            cLength += l[i];
            mp += 10;
            break;
          case 'x':
            break;
        }
      }

      if (aLength != 0 && bLength != 0 && cLength != 0)
      {
        mp += Math.Abs(a - aLength) + Math.Abs(b - bLength) + Math.Abs(c - cLength);

        if (ans == -1 || mp < ans)
        {
          ans = mp;
        }
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