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

        var edge = new int[10, 10];

        for (int i = 0; i < 10; i++)
        {

            var count = 0;

            Console.ReadLine().SplittedStringToInt32List().ForEach(x => edge[i,count++] = x);
        }

        var dist = (int[,])edge.Clone();
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int k = 0; k < 10; k++)
                {
                    dist[j, k] = Math.Min(dist[j, k], dist[j, i] + dist[i, k]);
                }
            }
        }
        var grid = new int[H, W];
        var sum = 0l;
        for (int i = 0; i < H; i++)
        {
            var count = 0;

            Console.ReadLine().SplittedStringToInt32List().ForEach(x => grid[i,count++] = x);
        }
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                var num = grid[i, j];
                if (num != -1 && num != 1)
                {
                    sum += dist[ grid[i, j],1];
                }
            }
        }
        Console.WriteLine(sum);

        Console.ReadLine();
    }




    public static long f(long n,long b)
    {
        if (n < b)
        {
            return n;
        }
        else
        {
            return f((long)Math.Floor((double)n/b),b) + n % b;
        }
    }

    public static string N(long n,long b)
    {
        var sb = new StringBuilder();
        while (true)
        {
            sb.Append((n % b).ToString());
            n /= b;
            if (n < b)
            {
                sb.Append(n.ToString());
                break;
            }
        }
        return new string( sb.ToString().Reverse().ToArray() );
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
    public const int Mod1e9 = 1000000007;



    public static void PrintArray(bool[,] array)
    {
        for (int i = 0; i < array.GetLength(0); i++)
        {
            var sb = new StringBuilder();
            for (int j = 0; j < array.GetLength(1); j++)
            {
                sb.Append(array[i, j]).Append(" ");
            }
            Console.WriteLine(sb.ToString());
        }
    }

    #endregion
}