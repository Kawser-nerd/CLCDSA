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

        var grid = new char[H + 2, W + 2];
        for (int i = 0; i < H + 2; i++)
        {
            for (int j = 0; j < W + 2; j++)
            {
                grid[i, j] = '#';
            }
        }
        for (int i = 1; i < H + 1; i++)
        {

            var str = Console.ReadLine().ToList();
            for (int j = 1; j < W + 1; j++)
            {
                grid[i, j] = str[j - 1];
            }
        }
        for (int i = 0; i < H + 2; i++)
        {
            var sb = new StringBuilder();
            for (int j = 0; j < W+ 2; j++)
            {
                sb.Append(grid[i, j]);
            }
            Console.WriteLine(sb.ToString());
        }

        Console.ReadLine();
    }

    public static void PrintArray<T>(T[,] array)
    {
        for (int i = 0; i < array.GetLength(0); i++)
        {
            for (int j = 0; j < array.GetLength(1); j++)
            {
                Console.Write(array[i, j] + " ");
            }
            Console.WriteLine();
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

    public static int Max(params int[] values)
    {
        var maxes = -1;
        for (int i = 0; i < values.Length; i++)
        {
            maxes = Math.Max(values[i], maxes);
        }
        return maxes;
    }

    #endregion
}