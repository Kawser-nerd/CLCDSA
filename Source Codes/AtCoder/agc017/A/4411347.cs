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
        SetFactor(60);
        var np = Console.ReadLine().SplittedStringToInt32List();
        var n = np[0];
        var p = np[1];
        var an = Console.ReadLine().SplittedStringToInt32List().Select(x => x % 2).ToList();
        var oddscount = an.Count(x => x % 2 == 1);
        var evescount = an.Count(x => x % 2 == 0);
        BigInteger counts = 0;

        if ( p == 0)
        {
            for (int i = 0; i <= oddscount; i+=2)
            {
                counts += GetCombination(oddscount, i) * BigInteger.Pow(2, evescount);
            }
        }
        else
        {
            for (int i = 1; i <= oddscount; i += 2)
            {
                counts += GetCombination(oddscount, i) * BigInteger.Pow(2, evescount);
            }
        }
        Console.WriteLine(counts);
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


    public static BigInteger[] factors;
    public static BigInteger[] revFactors;
    public static void SetFactor(int N)
    {
        factors = new BigInteger[N];
        factors[0] = 1;
        revFactors = new BigInteger[N];
        for (int i = 1; i < N; i++)
        {
            factors[i] = factors[i - 1] * i;
            factors[i] %= Mod1e9;
        }
        revFactors[N - 1] = BigInteger.ModPow(factors[N - 1], Mod1e9 - 2, Mod1e9);
        for (int i = N - 2; i >= 0; i--)
        {
            revFactors[i] = revFactors[i + 1] * (i + 1);
            revFactors[i] %= Mod1e9;
        }
    }
    public static BigInteger GetCombination(int a, int b)
    {
        return (((factors[a] * revFactors[b]) % Mod1e9) * revFactors[a - b]) % Mod1e9;
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