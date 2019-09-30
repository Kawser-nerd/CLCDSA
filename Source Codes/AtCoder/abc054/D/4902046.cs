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
        var abc = Input.ar2D(nab[0]);
        const int NUM = 401;
        var dp = new int[nab[0] + 1, NUM, NUM];
        for (var i = 0; i <= nab[0]; i++)
            for (var j = 0; j <NUM; j++)
                for (var k = 0; k < NUM; k++)
                    dp[i, j, k] = int.MaxValue / 2;
        dp[0, 0, 0] = 0;
        for (var i = 1; i <= nab[0]; i++)
            for (var j = 0; j < NUM; j++)
                for (var k = 0; k < NUM; k++)
                    if (j - abc[i - 1][0] >= 0 && k - abc[i - 1][1] >= 0)
                        dp[i, j, k] = Min(dp[i - 1, j, k], dp[i - 1, j - abc[i - 1][0], k - abc[i - 1][1]] + abc[i - 1][2]);
                    else dp[i, j, k] = dp[i - 1, j, k];
        var min = int.MaxValue;
        for (var i = 0; i < NUM; i++)
            for (var j = 0; j < NUM; j++)
                if (i!=0&&j!=0&&i * nab[2] == j * nab[1])
                    min = Min(min, dp[nab[0], i, j]);
        WriteLine(min > 4000 ? -1 : min);
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