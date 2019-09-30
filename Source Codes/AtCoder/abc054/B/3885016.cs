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
        var NM = Console.ReadLine().SplittedStringToInt32List();
        var N = NM[0];
        var M = NM[1];
        var basegrid = new bool[N, N];
        var grid = new bool[M, M];
        for (int i = 0; i < N; i++)
        {
            var count = 0;
            Console.ReadLine().Select(x => x == '#').ToList()
                .ForEach(x =>
                {
                    basegrid[i, count++] = x;

                });
        }
        for (int i = 0; i < M; i++)
        {
            var count = 0;
            Console.ReadLine().Select(x => x == '#').ToList()
                .ForEach(x =>
                {
                    grid[i, count++] = x;
                });
        }
        var repeatecount = N - M + 1;
        for (int i = 0; i < repeatecount; i++)
        {
            for (int j = 0; j < repeatecount; j++)
            {
                var isok = true;
                for (int k = 0; k < M; k++)
                {
                    for (int l = 0; l < M; l++)
                    {
                        if (basegrid[i + k, j + l] != grid[k, l])
                        {
                            isok = false;
                            break;
                        }
                    }
                }

                if (isok)
                {
                    Console.WriteLine("Yes");
                    Console.ReadLine();
                    return;
                }
            }
        }
        Console.WriteLine("No");

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