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
        var str = ReadLine();
        var dp = new long[str.Length + 1, 4];
        var al = new[] { 'A', 'B', 'C' };
        dp[0, 0] = 1;
        for (var i = 1; i <= str.Length; i++)
        {
            for (var j = 0; j < 4; j++)
                dp[i, j] = (dp[i - 1, j] * (str[i-1] != '?' ? 1 : 3)) % Input.MOD;
            for (var j = 0; j < 3; j++)
                if (str[i-1] == '?' || str[i-1] == al[j])
                {
                    dp[i, j + 1] += dp[i - 1, j];
                    dp[i, j + 1] %= Input.MOD;
                }
        }
        WriteLine(dp[str.Length, 3]);
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
    public const double eps = 1e-11;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}