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
        var KS = Console.ReadLine().SplittedStringToInt32List();
        var K = KS[0];
        var S = KS[1];
        var count = 0;
        for (int i = 0; i <= K; i++)
        {
            for (int j = 0; j <= K; j++)
            {
                var rem = S - i - j;
                if (rem >= 0 && rem <= K)
                {
                    count++;
                }
            }
        }
        Console.WriteLine(count);

        Console.ReadLine();
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