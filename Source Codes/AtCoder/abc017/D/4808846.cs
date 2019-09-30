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
        var nm = Input.ar;
        var fs = Enumerable.Repeat(0, nm[0]).Select(v => Input.num).ToArray();
        var dp = new long[nm[0] + 1];
        var th = new bool[nm[1] + 1];
        var same = Enumerable.Repeat(-1, nm[1]+1).ToArray();
        var then = new int[nm[0]];
        for(var i = 0; i < nm[0]; i++)
        {
            if (same[fs[i] - 1] == -1)
            {
                same[fs[i] - 1] = i + 1;
                continue;
            }
            then[i] = same[fs[i] - 1];
            same[fs[i] - 1] = i + 1;
        }
        for (var i = 1; i < nm[0]; i++)
            then[i] = Max(then[i - 1], then[i]);
        for (var i = 1; i <= nm[0]; i++)
            if (then[i - 1] == 0)
                dp[i] = (2 * dp[i - 1] + 1) % Input.MOD;
            else
                dp[i] = (2 * dp[i - 1] - dp[then[i - 1]-1] + Input.MOD) % Input.MOD;
        WriteLine((dp[nm[0]] - dp[nm[0] - 1] + Input.MOD) % Input.MOD);
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
    public const long Inf = (long)1e18/2;
    public const double eps = 1e-6;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}