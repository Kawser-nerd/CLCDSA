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
        var nw = Input.arL;
        var vw = new int[nw[0]][];
        for (var i = 0; i < nw[0]; i++)
            vw[i] = Input.ar;
        if (vw.Max(v => v[1]) <= 1000)
        {
            var dp = new long[nw[0] + 1, nw[1] + 1];
            for (var i = 1; i <= nw[1]; i++)
                dp[0, i] = int.MinValue;
            for (var i = 1; i <= nw[0]; i++)
                for (var j = 0; j <= nw[1]; j++)
                    if (j - vw[i - 1][1] >= 0)
                        dp[i, j] = Max(dp[i - 1, j], dp[i - 1, j - vw[i - 1][1]] + vw[i - 1][0]);
                    else dp[i, j] = dp[i - 1, j];
            var max = 0L;
            for (var i = 0; i <= nw[1]; i++)
                max = Max(max, dp[nw[0], i]);
            WriteLine(max);
        }
        else if (nw[0] <= 30)
        {
            var dic = new[] {
                new Dictionary<long,long>(),
                new Dictionary<long, long>(),
            };
            var ar = new[] {
                vw.Take((int)nw[0] / 2).ToArray(),
                vw.Skip((int)nw[0] / 2).ToArray(),
            };

            for (var i = 0; i < 2; i++)
                for (var j = 0; j < (1 << ar[i].Length); j++)
                {
                    var sum = 0L;
                    var val = 0L;
                    for (var h = 0; h < ar[i].Length; h++)
                        if ((1 & j >> h) == 1)
                        {
                            sum += ar[i][h][1];
                            val += ar[i][h][0];
                        }
                    if (sum <= nw[1])
                    {
                        if (!dic[i].ContainsKey(sum))
                            dic[i][sum] = 0;
                        dic[i][sum] = Max(dic[i][sum], val);
                    }
                }
            var pair1 = dic[0].OrderBy(v => v.Key).ToList();
            var pair2 = dic[1].OrderBy(v => v.Key).ToList();
            var max = 0L;
            var submax = 0L;
            var ct = 0;
            for(var i = pair2.Count - 1; i >= 0; i--)
            {
                while (ct < pair1.Count && pair2[i].Key + pair1[ct].Key <= nw[1])
                {
                    submax = Max(submax, pair1[ct].Value);
                    ct++;
                }
                max = Max(max, submax + pair2[i].Value);
            }
            WriteLine(max);
        }
        else
        {
            var maxValue = vw.Max(v => v[0]) * nw[0];
            var dp = new long[nw[0] + 1, maxValue + 1];
            for (var i = 1; i <= maxValue; i++)
                dp[0, i] = int.MaxValue;
            for (var i = 1; i <= nw[0]; i++)
                for (var j = 0; j <= maxValue; j++)
                    if (j - vw[i - 1][0] >= 0)
                        dp[i, j] = Min(dp[i - 1, j], dp[i - 1, j - vw[i - 1][0]] + vw[i - 1][1]);
                    else dp[i, j] = dp[i - 1, j];
            for (var i = maxValue; i >= 0; i--)
                if (dp[nw[0], i] <= nw[1])
                {
                    WriteLine(i);
                    return;
                }
                    
        }
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public  static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}