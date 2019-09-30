using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics; 

class _Class
{
  void _Do()
  {
    var NK = Split.ints();
    var N = NK[0];
    var K = NK[1];
    var Ai = Split.ints();

    //
    int mini = 0;
    {
      for (int j = 0; j < N; j++)
      {
        if (Ai[j] < Ai[mini])
          mini = j;
      }
    }

    //
    int ret = int.MaxValue;

    //
    for (int scan=mini-K+1;scan<mini+K-2 ;scan++ )
    {
      int z = 1;

      //
      for (int kk=0;;kk-=K-1)
      {
        var left = mini-scan + kk;
        if (left<=0)
          break;

        z++;
      }

      //
      for (int kk=0;;kk+=K-1)
      {
        var right = mini-scan + kk;
        if (right+K>= Ai.Length)
          break;

        z++;
      }
      ret = Math.Min(z,ret);

    }

    Console.WriteLine(ret);

  }


  //
  static void Main(string[] args)
  {
    _(args);
    new _Class()._Do();
  }

  [Conditional("DEBUG")]
  static void _(string[] args)
  {
    if (args.Length != 0 && File.Exists(args[0]))
      Console.SetIn(new StreamReader(args[0]));
    else
      Console.Error.WriteLine("in");
  }
}

static class Split
{


  // 1
  public static string[] strings()
  {
    return Console.ReadLine().Split();
  }


  // [2.1] -2,147,483,648 ~ +2,147,483,647
  public static int[] ints()
  {
    var _s = Console.ReadLine().Split();

    var x = new int[_s.Length];
    for (var i = 0; i < _s.Length; i++)
      x[i] = int.Parse(_s[i]);

    return x;
  }

  // [2.2] 
  // -9,223,372,036,854,775,808 ~ 
  // +9,223,372,036,854,775,807
  public static long[] longs()
  {
    var _s = Console.ReadLine().Split();

    var x = new long[_s.Length];
    for (var i = 0; i < _s.Length; i++)
      x[i] = long.Parse(_s[i]);

    return x;
  }

  public static double[] doubles()
  {
    var _s = Console.ReadLine().Split();

    var x = new double[_s.Length];
    for (var i = 0; i < _s.Length; i++)
      x[i] = double.Parse(_s[i]);

    return x;
  }

  public static BigInteger[] bigs()
  {
    var _s = Console.ReadLine().Split();

    var x = new BigInteger[_s.Length];
    for (var i = 0; i < _s.Length; i++)
      x[i] = BigInteger.Parse(_s[i]);

    return x;
  }
}