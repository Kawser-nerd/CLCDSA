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
        var hwk = Input.ar;
        var dp = new long[hwk[0]+1, hwk[1]];
        dp[0, 0] = 1;
        for(var i=1;i<=hwk[0];i++)
            for(var j = 0; j < hwk[1]; j++)
            {
                var ct = new[] { 0, 0, 0 };
                for(var k = 0; k < (1 << hwk[1]-1); k++)
                {
                    var bo = new bool[hwk[1]-1];
                    for (var h = 0; h < hwk[1]-1; h++)
                        if ((1 & k >> h) == 1)
                            bo[h] = true;
                    var b = false;
                    for (var q = 0; q < hwk[1] - 2; q++)
                        if (!b) b = bo[q] && bo[q + 1];
                        else break;
                    if (b) continue;
                    if ((j == 0 || !bo[j - 1]) && (j == hwk[1] - 1 || !bo[j])) ct[1]++;
                    if (j != 0 && bo[j - 1]) ct[0]++;
                    if (j != hwk[1] - 1 && bo[j]) ct[2]++;
                }
                if (j != 0)
                    dp[i, j - 1] = (dp[i, j - 1] + dp[i - 1, j] * ct[0]) % Input.MOD;
                if (j != hwk[1] - 1)
                    dp[i, j + 1] = (dp[i, j + 1] + dp[i - 1, j] * ct[2]) % Input.MOD;
                dp[i, j] = (dp[i, j] + dp[i - 1, j] * ct[1]) % Input.MOD;
            }
        WriteLine(dp[hwk[0], hwk[2] - 1]);
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
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public const long Inf = (long)1e18;
    public const double eps = 1e-6;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}