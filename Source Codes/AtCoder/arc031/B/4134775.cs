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
        var grid = new bool?[10, 10];
        for (int i = 0; i < 10; i++)
        {
            var count = 0;
            Console.ReadLine().ToList().ForEach(x => grid[i,count++] = x == 'o');
        }
        var isok = false;

        var dx = new int[] { -1, 1, 0, 0 };
        var dy = new int[] { 0, 0, 1, -1 };


        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                var cloned = (bool?[,])grid.Clone();
                cloned[i, j] = true;
                var stk = new Stack<KeyValuePair<int, int>>();
                stk.Push(new KeyValuePair<int, int>(i, j));
                while (stk.Count > 0)
                {
                    var item = stk.Pop();
                    for (int k = 0; k < 4; k++)
                    {
                        var xx = item.Key + dx[k];
                        var yy = item.Value + dy[k];
                        if (xx >= 0 && yy >= 0 && xx < 10 && yy < 10)
                        {
                            if (cloned[xx, yy] == true)
                            {
                                stk.Push(new KeyValuePair<int, int>(xx, yy));
                            }
                        }
                    }
                    cloned[item.Key, item.Value] = null;
                }
                var isok2 = true;
                for (int k = 0; k < 10; k++)
                {
                    for (int l = 0; l < 10; l++)
                    {
                        if (cloned[k, l] == true)
                        {
                            isok2 = false;
                        }
                    }
                }
                if (isok2)
                    isok = true;
            }

        }

        Console.WriteLine(isok ? "YES" : "NO");
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


    public static void PrintArray(char[,] array)
    {
        for (int i = 0; i < array.GetLength(0); i++)
        {
            var sb = new StringBuilder();
            for (int j = 0; j < array.GetLength(1); j++)
            {
                sb.Append(array[i, j]).Append("");
            }
            Console.WriteLine(sb.ToString());
        }
    }

    #endregion
}