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

static class MainClass
{
    public static void Main(string[] args)
    {
        #region
        //var NAB = Console.ReadLine();
        //var N = NAB[0];
        //var B = NAB[2];
        //var A = NAB[1];

        //var vn = Console.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => decimal.Parse(x)).ToList();
        //vn.Sort();
        //vn.Reverse();

        //decimal maxave = -1;
        //decimal before = -1;
        //decimal count = 0;
        //for (int i = 0; i < N; i++)
        //{
        //    if (before == vn[i])
        //    {

        //    }
        //    else
        //    {
        //        decimal num = 0;
        //        for (int j = 0; j <= i; j++)
        //        {
        //            num += vn[j];
        //        }
        //        if (maxave < num/(i + 1))
        //        {
        //            maxave = num / (i + 1);
        //            count = 1;
        //        }
        //        else if (maxave == num/(i + 1))
        //        {
        //            count++;
        //        }
        //    }


        //    before = vn[i];
        // 1
        //}
        #endregion
        //var HWD = Console.ReadLine().SplittedStringToInt32List();
        //var H = HWD[0];
        //var W = HWD[1];
        //var D = HWD[2];

        //var grid = new int[H, W];

        //for (int i = 0; i < H; i++)
        //{
        //    var count = 0;
        //    Console.ReadLine().SplittedStringToInt32List().ForEach(x => grid[i,count++] = x);

        //}

        //var newgrid = new List<KeyValuePair<int, int>>[H,W];

        //for (int i = 0; i < H; i++)
        //{
        //    for (int j = 0; j < W; j++)
        //    {
        //        var ls = new List<KeyValuePair<int, int>>();
        //        var item = grid[i, j];
        //        if (item < H * W - D)
        //        {
        //            var count = (H * W - item) / D;

        //        }
        //        else
        //        {
        //            ls.Add(new KeyValuePair<int, int>(item, item));
        //        }
        //        newgrid[i, j] = ls;
        //    }
        //}



        //var Q = Console.ReadLine().ToInt32();

        //for (int i = 0; i < Q; i++)
        //{
        //    var LR = Console.ReadLine().SplittedStringToInt32List();
        //    var L = LR[0];
        //    var R = LR[1];
        //}

        var N = Console.ReadLine().ToInt32();
        var ls = new List<int>();
        for (int i = 0; i < N; i++)
        {
            var str = Console.ReadLine().ToInt32();
            ls.Add(str);
        }
        Console.WriteLine(ls.Distinct().OrderByDescending(x => x).ToArray()[1]);
    }



    public static IEnumerable<T[]> Enumerate<T>(IEnumerable<T> items, int k, bool withRepetition)
    {
        if (k == 1)
        {
            foreach (var item in items)
                yield return new T[] { item };
            yield break;
        }
        foreach (var item in items)
        {
            var leftside = new T[] { item };

            var unused = withRepetition ? items : items.SkipWhile(e => !e.Equals(item)).Skip(1).ToList();

            foreach (var rightside in Enumerate(unused, k - 1, withRepetition))
            {
                yield return leftside.Concat(rightside).ToArray();
            }
        }
    }
    

    #region ?????
    public static long ToInt64(this string str) => long.Parse(str);
    public static int ToInt32(this string str) => int.Parse(str);
    public static BigInteger ToBigInteger(this string str) => BigInteger.Parse(str);
    public static List<string> SplittedStringToList(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
    public static List<int> SplittedStringToInt32List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();
    public static List<BigInteger> SplittedStringToBigInteger(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => BigInteger.Parse(x)).ToList();
    public const int INF = int.MaxValue / 2;
    public const long LONGINF = long.MaxValue / 2;
    #endregion
}