using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
using Pair = System.Tuple<int, int>;
using Edge = System.Tuple<int, int, long>;
//using Debug;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        Solve();
        //WriteLine(Solve());
    }
    static void Solve()
    {
        var nab = Input.ar;
        var hp = Enumerable.Repeat(0, nab[0]).Select(v => Input.numL).ToArray();
        var left = 0L;
        var right = (long)int.MaxValue;
        while (right - left > 1)
        {
            var mid = (right + left) / 2;
            var ct = 0L;
            for (var i = 0; i < nab[0]; i++)
                ct += Max(0, (hp[i] - mid * nab[2] + nab[1] - nab[2] - 1) / (nab[1] - nab[2]));
            if (ct > mid) left = mid;
            else right = mid;
        }
        WriteLine(right);
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static char[][] gred(int h) 
        => Enumerable.Repeat(0, h).Select(v => read.ToCharArray()).ToArray();
    public static int[][] ar2D(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] arL2D(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public const long Inf = (long)1e18;
    public const double eps = 1e-6;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}