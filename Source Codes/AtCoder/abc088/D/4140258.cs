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
        var HW = Console.ReadLine().SplittedStringToInt32List();
        var H = HW[0];
        var W = HW[1];
        var dx = new int[] { -1, 1, 0, 0 };
        var dy = new int[] { 0, 0, 1, -1 };
        var grid = new int[H, W];
        var blackcounts = 0;

        for (int i = 0; i < H; i++)
        {
            var count = 0;
            Console.ReadLine().ToList().ForEach(x => 
            {
                var num = x == '#' ? INF : -1;
                if (num == INF)
                {
                    blackcounts++;
                }
                grid[i, count++] = num;
            });
        }
        var maxcost = -1;
        var cloned = (int[,])grid;
        cloned[0, 0] = 0;
        var queue = new Queue<KeyValuePair<int, int>>();
        queue.Enqueue(new KeyValuePair<int, int>(0, 0));
        while (queue.Count > 0)
        {
            var item = queue.Dequeue();
            for (int k = 0; k < 4; k++)
            {
                var xx = item.Key + dx[k];
                var yy = item.Value + dy[k];
                if (xx >= 0 && yy >= 0 && xx < H && yy < W && cloned[xx, yy] == -1)
                {
                    cloned[xx, yy] = cloned[item.Key, item.Value] + 1;
                    queue.Enqueue(new KeyValuePair<int, int>(xx, yy));
                }
            }
        }
        var value = cloned[H - 1, W - 1];
        if (value != -1)
        {
            maxcost = H * W - blackcounts - value - 1;
        }


        Console.WriteLine(maxcost);
        Console.ReadLine();
    }
    
    

    #region ?????
    public static long ToInt64(this string str) => long.Parse(str);
    public static int ToInt32(this string str) => int.Parse(str);
    public static BigInteger ToBigInteger(this string str) => BigInteger.Parse(str);
    public static List<string> SplittedStringToList(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
    public static List<int> SplittedStringToInt32List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();
    public static List<long> SplittedStringToInt64List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => long.Parse(x)).ToList();
    public static List<BigInteger> SplittedStringToBigInteger(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => BigInteger.Parse(x)).ToList();
    public const int INF = int.MaxValue / 2;
    public const long LONGINF = long.MaxValue / 2;


    public static void PrintArray(bool[,] array)
    {
        for (int i = 0; i < array.GetLength(0); i++)
        {
            var sb = new StringBuilder();
            for (int j = 0; j < array.GetLength(1); j++)
            {
                sb.Append(array[i, j] ? "#" : ".").Append("");
            }
            Console.WriteLine(sb.ToString());
        }
    }

    #endregion
}