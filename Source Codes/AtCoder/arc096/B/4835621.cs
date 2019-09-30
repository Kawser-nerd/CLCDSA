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
        var input = ReadLine().Split(' ');
        var num = int.Parse(input[0]);
        var c = long.Parse(input[1]);
        var xv = new long[num + 2][];
        xv[0] = new[] { 0L, 0 };
        for (var i = 1; i <= num; i++)
            xv[i] = Input.arL;
        xv[num + 1] = new[] { c, 0 };
        var sum = new long[num + 2];
        var calc = 0L;
        for (var i = 1; i <= num; i++)
        {
            calc += xv[i][1];
            calc -= xv[i][0] - xv[i - 1][0];
            sum[i] = Max(calc, sum[i - 1]);
        }
        var sumr = new long[num + 2];
        calc = 0;
        for (var i = num; i > 0; i--)
        {
            calc += xv[i][1];
            calc -= xv[i + 1][0] - xv[i][0];
            sumr[i] = Max(calc, sumr[i + 1]);
        }
        var res = 0L;
        for (var j = num; j >= 0; j--)
        { 
            res = Max(res, sum[j] + sumr[j+1] -(c - xv[j+1][0]));
            res = Max(res, sum[j] + sumr[j+1] - xv[j][0]);
        }
        WriteLine(res);
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