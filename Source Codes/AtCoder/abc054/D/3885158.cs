#pragma warning disable

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Text.RegularExpressions;
using System.Diagnostics;
using System.Numerics;
using System.Collections;
using System.Timers;

static class MainClass
{
    public static void Main(string[] args)
    {
        var NMaMb = Console.ReadLine().SplittedStringToInt32List();
        var N = NMaMb[0];
        var Ma = NMaMb[1];
        var Mb = NMaMb[2];
        var ls = new List<ABC>();
        for (int i = 0; i < N; i++)
        {
            var abc = Console.ReadLine().SplittedStringToInt32List();
            var a = abc[0];
            var b = abc[1];
            var c = abc[2];
            var abc2 = new ABC() { A = a, B = b, C = c };
            ls.Add(abc2);
        }
        var dp = new int[50, 500, 500];
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0;j < 500; j++)
            {
                for (int k = 0; k < 500; k++)
                {
                    dp[i, j, k] = INF;
                }
            }
        }
        dp[0, 0, 0] = 0;
        for (int i = 0; i < N; i++)
        {
            var item = ls[i];
            for (int ma = 0; ma < 500; ma++)
            {
                for (int mb = 0; mb < 500; mb++)
                {
                    if (ma - item.A < 0 || mb - item.B < 0)
                    {
                        dp[i + 1, ma, mb] = dp[i, ma, mb];
                    }
                    else
                    {
                        dp[i + 1, ma, mb] = Math.Min(dp[i, ma, mb],dp[i,ma - item.A,mb - item.B] + item.C);
                    }
                }
            }
        }
        var numsss = 500 / Math.Max(Ma, Mb);
        var mins = INF;
        for (int i = 1; i <= numsss; i++)
        {
            try
            {
                var num = dp[N, Ma * i, Mb * i];
                mins = Math.Min(mins, num);
            }
            catch
            {
                break;
            }

        }
        Console.WriteLine(mins == INF ? -1 : mins);

        Console.ReadLine();
    }

    class ABC
    {
        public int A;
        public int B;
        public int C;
    }


    #region ?????
    public static long ToInt64(this string str) => long.Parse(str);
    public static int ToInt32(this string str) => int.Parse(str);
    public static BigInteger ToBigInteger(this string str) => BigInteger.Parse(str);
    public static List<string> SplittedStringToList(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
    public static List<int> SplittedStringToInt32List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();
    public static List<BigInteger> SplittedStringToBigInteger(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => BigInteger.Parse(x)).ToList();

    public const int INF = int.MaxValue / 2;
    #endregion
}