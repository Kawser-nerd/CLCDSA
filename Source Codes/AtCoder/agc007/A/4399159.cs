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
        var hw = Console.ReadLine().SplittedStringToInt32List();
        var h = hw[0];
        var w = hw[1];
        var grid = new bool[h, w];
        for (int i = 0; i < h; i++)
        {
            var count = 0;
            Console.ReadLine().ToList().ForEach(x => grid[i,count++] = x == '#');
        }
        var stk = new Stack<KeyValuePair<int, int>>();
        stk.Push(new KeyValuePair<int, int>(0, 0));
        var dx = new int[] { 0, 1 };
        var dy = new int[] { 1, 0 };
        while (stk.Count > 0)
        {
            var item = stk.Pop();
            for (int ji = 0; ji < 2; ji++)
            {
                var xx = item.Key + dx[ji];
                var yy = item.Value + dy[ji];
                if (xx >= h || yy >= w || xx < 0 || yy < 0)
                {
                    continue;
                }
                if (grid[xx, yy])
                {
                    stk.Push(new KeyValuePair<int, int>(xx, yy));
                    break;
                }
            }
            grid[item.Key, item.Value] = false;
        }
        var isok = true;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (grid[i, j])
                    isok = false;
            }
        }
        Console.WriteLine(isok ? "Possible" : "Impossible");

        Console.ReadLine();
    }

    public static int Manhattan(int x1,int x2,int y1,int y2)
    {
        return Math.Abs(x1 - x2) + Math.Abs(y1 - y2);
    }
    

    public static long Sums(IEnumerable<int> list)
    {
        var sum = 0l;
        foreach (var item in list)
        {
            sum += item;
        }
        return sum;
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