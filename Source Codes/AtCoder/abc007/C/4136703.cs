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
        var RC = Console.ReadLine().SplittedStringToInt32List();
        var sxsy = Console.ReadLine().SplittedStringToInt32List();
        var gxgy = Console.ReadLine().SplittedStringToInt32List();
        var R = RC[0];
        var C = RC[1];

        var start = new KeyValuePair<int, int>(sxsy[0] - 1,sxsy[1] - 1);
        var end = new KeyValuePair<int, int>(gxgy[0] - 1,gxgy[1] - 1);

        var grid = new int[R, C];
        for (int i = 0; i < R; i++)
        {
            var count = 0;

            Console.ReadLine().ToList().ForEach(x => grid[i,count++] = x == '#' ? INF : -1);
        }
        var queue = new Queue<KeyValuePair<int, int>>();

        queue.Enqueue(start);

        var dx = new int[] { 1, 0, -1, 0 };
        var dy = new int[] { 0, 1, 0, -1 };
        grid[start.Key, start.Value] = 0;

        while (queue.Count > 0)
        {
            var item = queue.Dequeue();
            for (int i = 0; i < 4; i++)
            {
                var xx = item.Key + dx[i];
                var yy = item.Value + dy[i];
                if (xx >= 0  && yy >= 0 && xx < R && yy < C)
                {
                    if (grid[xx,yy] == -1)
                    {
                        grid[xx, yy] = grid[item.Key, item.Value] + 1;
                        queue.Enqueue(new KeyValuePair<int, int>(xx, yy));
                    }
                }
            }
        }
        Console.WriteLine(grid[end.Key,end.Value]);

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