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
        var nk = Input.ar;
        var ar = Enumerable.Repeat(0, nk[0]).Select(v => Input.num).ToArray();
        if (ar.Sum() == nk[1])
        {
            WriteLine(1);
            return;
        }
        var dp = new long[nk[0] + 1, nk[0] + 1];
        for (var i = 0; i <= nk[0]; i++)
            for (var j = 1; j <= nk[0]; j++)
                dp[i, j] = int.MaxValue;
        var sum = ar[0];
        dp[1, 1] = 1;
        for (var i = 2; i <= nk[0]; i++)
        {
            for (var j = 1; j <= i; j++)
            {
                var p = dp[i - 1, j - 1] * ar[i - 1] / sum + 1;
                dp[i, j] = dp[i - 1, j];
                if (p <= ar[i - 1]) dp[i, j] = Min(dp[i - 1, j], dp[i - 1, j - 1] + p);

            }
            sum += ar[i - 1];
        }
        for(var i=nk[0];i>=0;i--)
            if (dp[nk[0], i] <= nk[1])
            {
                WriteLine(i);
                return;
            }
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