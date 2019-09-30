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
        var HW = Console.ReadLine().SplittedStringToInt32List();
        var H = HW[0];
        var W = HW[1];

        var grid = new bool[H, W];
        for (int i = 0; i < H; i++)
        {
            var count = 0;
            Console.ReadLine().ToList().ForEach(x => grid[i,count++] = x == '#');
        }
        var iscan = true;
        var dx = new int[] { 1, 0, 0, -1 };
        var dy = new int[] { 0, 1, -1, 0 };
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (grid[i, j])
                {
                    var check = false;
                    for (int k = 0; k < 4; k++)
                    {
                        var xx = i + dx[k];
                        var yy = j + dy[k];
                        if (xx < 0 || xx >= H || yy < 0 || yy >= W)
                            continue;
                        if (grid[xx, yy])
                            check = true;
                    }
                    if (!check)
                        iscan = false;
                }
            }
        }
        Console.WriteLine(iscan ? "Yes" : "No");

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
    public const long LONGINF = long.MaxValue / 2;
    #endregion
}