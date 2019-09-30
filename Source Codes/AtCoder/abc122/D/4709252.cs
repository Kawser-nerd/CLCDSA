using System;
using System.Collections.Generic;

namespace abc122_d
{
  class Program
  {
    static void Main(string[] args)
    {
      var n = CIn.ReadInt();
      var mod = (int)Math.Pow(10, 9) + 7;

      var dp = new int[n + 1, 4, 4, 4];

      dp[0, 3, 3, 3] = 1;

      for (var len = 0; len < n; len++)
      {
        for (var c1 = 0; c1 < 4; c1++)
        {
          for (var c2 = 0; c2 < 4; c2++)
          {
            for (var c3 = 0; c3 < 4; c3++)
            {
              if (dp[len, c1, c2, c3] == 0)
              {
                continue;
              }

              for (var c4 = 0; c4 < 4; c4++)
              {
                if ((c2 == 0 && c3 == 1 && c4 == 2) || (c2 == 1 && c3 == 0 && c4 == 2) || (c2 == 0 && c3 == 2 && c4 == 1) || (c1 == 0 && (c2 == 1 || c3 == 1) && c4 == 2))
                {
                  continue;
                }

                dp[len + 1, c2, c3, c4] += dp[len, c1, c2, c3];
                dp[len + 1, c2, c3, c4] %= mod;
              }
            }
          }
        }
      }

      var ans = 0;

      for (var c1 = 0; c1 < 4; c1++)
      {
        for (var c2 = 0; c2 < 4; c2++)
        {
          for (var c3 = 0; c3 < 4; c3++)
          {
            ans += dp[n, c1, c2, c3];
            ans %= mod;
          }
        }
      }

      Console.WriteLine(ans);
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