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
        //Solve();
        WriteLine(Solve());
    }
    static string Solve()
    {
        var k = Input.num;
        var ar = Input.arL.Reverse().ToArray();
        if (ar[0] != 2) return "-1";
        var min = 2L;
        var max = 2L;
        for(var i = 0; i < k; i++)
        {
            var le = (min + ar[i] - 1) / ar[i]*ar[i];
            var ri = max / ar[i] * ar[i];
            if (le<min||max<le||ri<min||max<ri) return "-1";
            min = le;
            max = ri + ar[i] - 1;
        }
        return $"{min} {max}";
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