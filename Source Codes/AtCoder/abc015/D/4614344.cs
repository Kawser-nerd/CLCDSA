using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var wid = Input.num;
        var nk = Input.ar;
        var ab = Input.twodim(nk[0]);
        var dp = new long[nk[0] + 1, wid + 1, nk[1] + 1];
        for (var i = 1; i <= nk[0]; i++)
            for (var j = 0; j <= wid; j++)
                for (var h = 1; h <= nk[1]; h++)
                    if (j - ab[i - 1][0] >= 0)
                        dp[i, j, h] = Max(dp[i - 1, j, h], dp[i - 1, j - ab[i - 1][0], h - 1] + ab[i - 1][1]);
                    else dp[i, j, h] = dp[i - 1, j, h];
        var max = 0L;
        for (var i = 0; i <= wid; i++)
            for (var h = 0; h <= nk[1]; h++)
                max = Max(max, dp[nk[0], i, h]);
        WriteLine(max);
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}