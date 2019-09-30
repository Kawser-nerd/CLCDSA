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
        var iii = ReadLine().Split(' ');
        var num = int.Parse(iii[0]);
        var k = long.Parse(iii[1]);
        var ar = Input.arL;
        var dp = new long[55, 2];
        for (var i = 0; i < 55; i++)
            for (var j = 0; j < 2; j++)
                dp[i, j] = -1;
        dp[50, 0] = 0;
        for (var i = 50; i >= 0; i--)
        {
            var ct = 0;
            var mask = 1L << i;
            for (var j = 0; j < num; j++)
                if ((1&ar[j]>>i) == 1) ct++;
            if (dp[i + 1, 1] != -1)
                dp[i, 1] = dp[i + 1, 1] + mask * Max(num - ct, ct);
            if (dp[i + 1, 0] != -1)
            {
                if ((1 & k >> i) == 1)
                {
                    dp[i, 0] = dp[i + 1, 0] + (num - ct) * mask;
                    dp[i, 1] = Max(dp[i, 1], dp[i + 1, 0] + ct * mask);
                }
                else
                    dp[i, 0] = dp[i + 1, 0] + ct * mask;

            }
        }
        WriteLine(Max(dp[0, 0], dp[0, 1]));
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