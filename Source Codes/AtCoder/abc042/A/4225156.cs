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
        var abc = Console.ReadLine().SplittedStringToInt32List();
        var a = abc[0];
        var b = abc[1];
        var c = abc[2];

        if (abc.Count(x => x == 5) == 2 && abc.Count(x => x == 7) == 1)
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
        
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

        // ?????
    public static List<long> PrimeFactorize(long n)
    {
        var bases = n;
        var num = (long)Math.Pow(n, 0.5);
        var ls = new List<long>();
        for (int i = 2; i <= num; i++)
        {
            if (n % i == 0)
            {
                n = n / i;
                ls.Add(i);
                i--;
                continue;
            }
        }
        long nnn = 1;
        foreach (var item in ls)
        {
            nnn = nnn * item;
        }
        if (nnn != bases)
            ls.Add(n);
        return ls;
    }


    public static List<long> MakeDivisors(long n)
    {
        var ls = new List<long>();
        // ls.Add(1);
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                ls.Add(i);
                if (i != 1 && i * i != n)
                {
                    ls.Add(n / i);
                }
            }
        }
        return ls;
    }

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