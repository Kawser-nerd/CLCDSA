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
        var DG = Console.ReadLine().SplittedStringToInt32List();
        var D = DG[0];
        var G = DG[1];

        var problems = new List<KeyValuePair<int, int>>();

        for (int i = 0; i < D; i++)
        {
            var pc = Console.ReadLine().SplittedStringToInt32List();
            var p = pc[0];
            var c = pc[1];
            problems.Add(new KeyValuePair<int, int>(p, c));
        }
        
        var bits = CreateBits(D).Where(x => x.Count(_ => _ == null) == 1);
        var mincount = INF;
        foreach (var item in bits)
        {
            var count = 0;
            var sum = 0;
            var nullind = -1;
            for (int i = 0; i < D; i++)
            {
                if (item[i] == null)
                {
                    nullind = i;
                }
                else if (item[i] == true)
                {
                    count += problems[i].Key;
                    sum += problems[i].Value + (i + 1) * 100 * problems[i].Key;
                }
            }
            if (sum >= G)
            {
                mincount = Math.Min(count, mincount);
            }
            else
            {
                var rem = G - sum;
                if (G - sum > (nullind + 1) * 100 * problems[nullind].Key + problems[nullind].Value)
                {
                    continue;
                }
                else
                {
                    if (G - sum <= (nullind + 1) * 100 *(problems[nullind].Key - 1))
                    {
                        count += (G - sum) / (100 * (nullind + 1)) + (((G - sum) % (100 * (nullind + 1)) == 0) ? 0:1);
                    }
                    else
                    {
                        count += problems[nullind].Key;
                    }
                }
                mincount = Math.Min(mincount, count);
            }
        }
        Console.WriteLine(mincount);

        Console.ReadLine();
    }


    public static List<List<bool?>> CreateBits(int len)
    {
        return CreateBitsPri(new List<List<bool?>>(), len, 0);
    }

    private static List<List<bool?>> CreateBitsPri(List<List<bool?>> bits, int len, int count)
    {
        if (count == 0)
        {
            var lss = new List<bool?>();
            lss.Add(true);
            bits.Add(lss);
            var lx = new List<bool?>();
            lx.Add(false);
            bits.Add(lx);
            var lxx = new List<bool?>();
            lxx.Add(null);
            bits.Add(lxx);
            count++;
            return CreateBitsPri(bits, len, count);
        }
        if (len - count == 0)
            return bits;
        count++;
        var ls = new List<List<bool?>>();
        foreach (var item in bits)
        {
            var x = item.ToList();
            var y = item.ToList();
            x.Add(true);
            item.Add(false);
            y.Add(null);
            ls.Add(item);
            ls.Add(x);
            ls.Add(y);
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