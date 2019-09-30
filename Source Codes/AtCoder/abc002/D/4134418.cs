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
        var NM = Console.ReadLine().SplittedStringToInt32List();
        var N = NM[0];
        var M = NM[1];

        var connection = new bool[N, N];
        for (int i = 0; i < N; i++)
        {
            connection[i, i] = true;
        }

        for (int i = 0; i < M; i++)
        {
            var xy = Console.ReadLine().SplittedStringToInt32List();
            var x = xy[0] - 1;
            var y = xy[1] - 1;
            connection[x, y] = true;
            connection[y, x] = true;
        }
        var bits = CreateBits(N);
        var max = -1;
        foreach (var bit in bits)
        {
            var isok = true;
            var count = 0;
            var ls = new List<int>();
            
            bit.ForEach(x =>
            {
                if (x)
                    ls.Add(count);
                count++;
            });
            for (int i = 0; i < ls.Count; i++)
            {
                for (int j = 0; j < ls.Count; j++)
                {
                    if (!connection[ls[i], ls[j]])
                    {
                        isok = false;
                    }
                }
                
            }
            if (isok)
                max = Math.Max(max, ls.Count);
        }
        Console.WriteLine(max);

        Console.ReadLine();
    }


    public static List<List<bool>> CreateBits(int len)
    {
        return CreateBitsPri(new List<List<bool>>(), len, 0);
    }

    private static List<List<bool>> CreateBitsPri(List<List<bool>> bits, int len, int count)
    {
        if (count == 0)
        {
            var lss = new List<bool>();
            lss.Add(true);
            bits.Add(lss);
            var lx = new List<bool>();
            lx.Add(false);
            bits.Add(lx);
            count++;
            return CreateBitsPri(bits, len, count);
        }
        if (len - count == 0)
            return bits;
        count++;
        var ls = new List<List<bool>>();
        foreach (var item in bits)
        {
            var x = item.ToList();
            x.Add(true);
            item.Add(false);
            ls.Add(item);
            ls.Add(x);
        }
        return CreateBitsPri(ls, len, count);
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


    public static void PrintArray(int[,] array)
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