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
    static int[] u = new[] { 2, 5, 5, 4, 5, 6, 3, 7, 6 };
    static int[] dp;
    static void Solve()
    {
        var nm = Input.ar;
        var ar = Input.ar.OrderByDescending(v=>v).ToArray();
        dp = Enumerable.Repeat(int.MinValue, nm[0] + 1).ToArray();
        dp[0] = 0;
        for (var i = 2; i <= nm[0]; i++)
            for (var j = 0; j < nm[1]; j++)
                if (i - u[ar[j] - 1] >= 0)
                    dp[i] = Max(dp[i], dp[i - u[ar[j] - 1]] + 1);
        WriteLine(dfs(nm[0], ar));
    }
    static string dfs(int num,int[] ar)
    {
        for (var i = 0; i < ar.Length; i++)
            if (num >= u[ar[i] - 1] && dp[num] - 1 == dp[num - u[ar[i] - 1]])
                return ar[i].ToString() + dfs(num - u[ar[i] - 1], ar);
        return "";
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