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
    var N = Split.ints()[0];
    var Xs = Split.ints();

    //
    var X2 = new int[N];
    for (int i = 0; i < N; i++)
      X2[i] = Xs[i];

    Array.Sort(X2);
    int m1 = X2[N / 2-1];
    int m2 = X2[N / 2 ];

    //
    for (int i = 0; i < N; i++)
    {
      if (Xs[i] <= m1)
        Console.WriteLine(m2);
      else
        Console.WriteLine(m1);
    }
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