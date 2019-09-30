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
    static long Solve()
    {
        var nw = Input.ar;
        var vw = Input.ar2D(nw[0]);
        if (vw.Max(ar => ar[1]) <= 1000)
        {
            var kk = 1000 * nw[0] + 1;
            var dp = new long[nw[0] + 1, kk];
            for (var i = 1; i <= nw[0]; i++)
                for (var j = 0; j < kk; j++)
                {
                    if (j > nw[1]) break;
                    if (j - vw[i - 1][1] >= 0)
                        dp[i, j] = Max(dp[i - 1, j], dp[i - 1, j - vw[i - 1][1]] + vw[i - 1][0]);
                    else dp[i, j] = dp[i - 1, j];
                }
            var res = 0L;
            for (var i = 0; i < kk; i++)
                res = Max(res, dp[nw[0], i]);
            return res;
        }
        else if (vw.Max(v => v[0]) <= 1000)
        {
            var kk = 1000 * nw[0] + 1;
            var dp = new long[nw[0] + 1, kk];
            for (var i = 0; i <= nw[0]; i++)
                for (var j = 0; j < kk; j++)
                    dp[i, j] = long.MaxValue / 2;
            dp[0, 0] = 0;
            for (var i = 1; i <= nw[0]; i++)
                for (var j = 0; j < kk; j++)
                    if (j - vw[i - 1][0] >= 0)
                        dp[i, j] = Min(dp[i - 1, j], dp[i - 1, j - vw[i - 1][0]] + vw[i - 1][1]);
                    else dp[i, j] = dp[i - 1, j];
            for (var i = kk - 1; i >= 0; i--)
                if (dp[nw[0], i] <= nw[1])
                    return i;
            return 0;
        }
        else
        {
            var sel = new[] { vw.Take(nw[0] / 2).ToArray(), vw.Skip(nw[0] / 2).ToArray() };
            var dic = new[] { new Dictionary<long, long>(), new Dictionary<long, long>() };

            for (var i = 0; i < 2; i++)
                for (var j = 0; j < (1L << sel[i].Length); j++)
                {
                    var w = 0L;
                    var v = 0L;
                    for (var k = 0; k < sel[i].Length; k++)
                        if ((1 & j >> k) == 1)
                        {
                            v += sel[i][k][0];
                            w += sel[i][k][1];
                        }
                    if (w > nw[1]) continue;
                    if (dic[i].ContainsKey(w))
                        dic[i][w] = Max(dic[i][w], v);
                    else dic[i][w] = v;
                }
            var pair1 = dic[0].OrderBy(v => v.Key).ToArray();
            var pair2 = dic[1].OrderBy(v => v.Key).ToArray();
            var res = 0L;
            var submax = 0L;
            var ct = 0;
            for (var i = pair2.Length - 1; i >= 0; i--)
            {
                while (ct < pair1.Length && pair1[ct].Key + pair2[i].Key <= nw[1])
                {
                    submax = Max(submax, pair1[ct].Value);
                    ct++;
                }
                res = Max(res, submax + pair2[i].Value);
            }
            return res;
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