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
        var nab = Console.ReadLine().SplittedStringToInt32List();
        var n = nab[0];
        var a = nab[1];
        var b = nab[2];
        var now = 0;
        for (int i = 0; i < n; i++)
        {
            var sd = Console.ReadLine().SplittedStringToList();
            var d = sd[1].ToInt32();
            var plmn = 1;
            if (sd[0] == "West")
            {
                plmn = -1;
            }
            if (d < a)
            {
                now += (plmn * a);
            }
            else if (b < d)
            {
                now += (plmn * b);
            }
            else
            {
                now += (plmn * d);
            }
        }
        if (now < 0)
            Console.WriteLine("West " + (now*-1));
        else if (now > 0)
            Console.WriteLine("East " + (now));
        else
            Console.WriteLine("0");

        Console.ReadLine();
    }
    
    


    public static int ParentCount;

    public static int[] Parents;
    public static int[] IfParentsChildrenCount;

    public static int[] Ranks;

    public static void InitializeUnionFind(int N)
    {
        Parents = new int[N];
        Ranks = new int[N];
        IfParentsChildrenCount = new int[N];
        for (int i = 0; i < N; i++)
        {
            Parents[i] = i;
            Ranks[i] = 0;
            IfParentsChildrenCount[i] = 1;
        }
        ParentCount = N + 1;
    }

    public static int Root(int a)
    {
        if (Parents[a] == a)
        {
            return a;
        }
        else
        {
            Parents[a] = Root(Parents[a]);
            return Parents[a];
        }
    }

    public static bool Same(int a, int b)
    {
        return Root(a) == Root(b);
    }

    public static void Unite(int a, int b)
    {
        var parentA = Root(a);
        var parentB = Root(b);
        if (parentA == parentB)
            return;
        if (Ranks[parentA] < Ranks[parentB])
        {
            Parents[parentA] = parentB;
            IfParentsChildrenCount[parentB] += IfParentsChildrenCount[parentA];
            ParentCount -= IfParentsChildrenCount[parentA];

            IfParentsChildrenCount[parentA] = 0;
        }
        else
        {
            Parents[parentB] = parentA;
            if (Ranks[parentA] == Ranks[parentB])
            {
                Ranks[parentA]++;
            }
            IfParentsChildrenCount[parentA] += IfParentsChildrenCount[parentB];
            ParentCount -= IfParentsChildrenCount[parentB];
            IfParentsChildrenCount[parentB] = 0;
        }
    }

    #region ?????

    public static long ToInt64(this string str) => long.Parse(str);
    public static int ToInt32(this string str) => str == "" ? 0 : int.Parse(str);
    public static BigInteger ToBigInteger(this string str) => BigInteger.Parse(str);
    public static List<string> SplittedStringToList(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
    public static List<int> SplittedStringToInt32List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();
    public static List<long> SplittedStringToInt64List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => long.Parse(x)).ToList();
    public static List<BigInteger> SplittedStringToBigInteger(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => BigInteger.Parse(x)).ToList();
    public const int INF = int.MaxValue / 4;
    public const long LONGINF = long.MaxValue / 2;
    public const int Mod1e9 = 1000000007;

    public static void PrintArray(char[,] array)
    {
        for (int i = 0; i < array.GetLength(0); i++)
        {
            var sb = new StringBuilder();
            for (int j = 0; j < array.GetLength(1); j++)
            {
                sb.Append(array[i, j]);
            }
            Console.WriteLine(sb.ToString());
        }
    }
    public static int Manhattan(int x1, int x2, int y1, int y2)
    {
        return Math.Abs(x1 - x2) + Math.Abs(y1 - y2);
    }

    public static Dictionary<T, int> ToCountedDictionary<T>(this IEnumerable<T> items)
    {
        var dic = new Dictionary<T, int>();
        foreach (var item in items)
        {
            if (dic.ContainsKey(item))
                dic[item]++;
            else
                dic.Add(item, 1);
        }
        return dic;
    }

    public static long Sums(IEnumerable<int> list)
    {
        var sum = 0l;
        foreach (var item in list)
        {
            sum += item;
        }
        return sum;
        #endregion
    }

    public static int[] dx = new int[] { -1, 1, 0, 0 };
    public static int[] dy = new int[] { 0, 0, 1, -1 };
}