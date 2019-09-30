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
        var ab = Console.ReadLine().SplittedStringToInt64List();
        if (ab[0] == ab[1])
        {
            Console.WriteLine(ab[0]);
        }
        else
        {
            if (ab[0] % 2 == 0)
            {
                Console.WriteLine(computeXOR2(ab[0], ab[1]));

            }
            else
            {
                Console.WriteLine(computeXOR3(ab[0], ab[1]));

            }
        }
        Console.ReadLine();
    }

    static long computeXOR(long n, long k)
    {
        // If n is a multiple of 4 
        if ((k - n + 1) % 4 == 0)
            return n;

        // If n%4 gives remainder 1 
        if ((k - n + 1) % 4 == 1)
            return k ^ n;

        // If n%4 gives remainder 2 
        if ((k - n + 1) % 4 == 2)
            return n - 1;

        // If n%4 gives remainder 3 
        return (n - 1) ^ k; 
    }
    static long computeXOR3(long n, long k)
    {
        // If n is a multiple of 4 
        if ((k - n) % 4 == 1)
            return n ^ k;

        // If n%4 gives remainder 1 
        if ((k - n) % 4 == 2)
            return n - 1;

        // If n%4 gives remainder 2 
        if ((k - n) % 4 == 3)
            return (n - 1)^k;

        // If n%4 gives remainder 3 
        return n;
    }
    static long computeXOR2(long n, long k)
    {
        // If n is a multiple of 4 
        if ((k - n) % 4 == 3)
            return 0;

        // If n%4 gives remainder 1 
        if ((k - n) % 4 == 1)
            return 1;

        // If n%4 gives remainder 2 
        if ((k - n) % 4 == 2)
            return k + 1;

        // If n%4 gives remainder 3 
        return 0^ k;
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
}