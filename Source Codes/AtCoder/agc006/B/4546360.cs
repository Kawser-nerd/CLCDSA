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
        var nx = Console.ReadLine().SplittedStringToInt32List();
        var n = nx[0];
        var x = nx[1];

        if (x == 1 || x == n* 2- 1)
        {
            Console.WriteLine("No");
        }
        else
        {
            Console.WriteLine("Yes");
            if (x == n)
            {
                for (int i = 0; i < 2*n - 1; i++)
                {
                    Console.WriteLine(i + 1);
                }
            }
            else if ( x < n)
            {
                var zure = n - x;
                for (int i = 0; i < zure; i++)
                {
                    Console.WriteLine(2 * n - 1 - i);
                }
                for (int i = 0; i < 2 * n - 1 - zure; i++)
                {
                    Console.WriteLine(i + 1);
                }

            }
            else // x > n
            {
                var zure = x - n;
                for (int i = zure; i < 2 * n - 1; i++)
                {
                    Console.WriteLine(i + 1);
                }
                for (int i = 0; i < zure; i++)
                {
                    Console.WriteLine(i + 1);
                }
            }
        }

        Console.ReadLine();
        //var ls = new List<int>();
        
        //var perm = new List<int>() { 1, 2, 3, 4, 5, 6, 7,8,9 }.Perm().ToList();
        //for (int i = 0; i < perm.Count; i++)
        //{
        //    var item = perm[i].ToList();
        //    var grid1 = new int[7];
        //    for (int j = 0; j < 5; j++)
        //    {
        //        grid1[j] = new List<int>() { item[j], item[j + 1], item[j + 2] }.GetMedian();
        //    }
        //    var grid2 = new int[5];
        //    for (int j = 0; j < 3; j++)
        //    {
        //        grid2[j] = new List<int>() { grid1[j], grid1[j + 1], grid1[j + 2] }.GetMedian();
        //    }
        //    var grid3 = new int[3];
        //    for (int j = 0; j < 3; j++)
        //    {
        //        grid3[j] = new List<int>() { grid2[j], grid2[j + 1], grid2[j + 2] }.GetMedian();
        //    }
        //    var ans = new List<int>() { grid3[0], grid3[1], grid3[2] }.GetMedian();
        //    ls.Add(ans); ;

        //}
        //var anss = ls.Distinct();
        //Console.WriteLine(ls.Distinct().Count());
        //foreach (var item in anss)
        //{
        //    Console.WriteLine(item);
        //}
    }


    public static IEnumerable<IEnumerable<T>> Perm<T>(this IEnumerable<T> items, int? k = null)
    {
        if (k == null)
            k = items.Count();

        if (k == 0)
        {
            yield return Enumerable.Empty<T>();
        }
        else
        {
            var i = 0;
            foreach (var x in items)
            {
                var xs = items.Where((_, index) => i != index);
                foreach (var c in Perm(xs, k - 1))
                    yield return c.Before(x);

                i++;
            }
        }
    }

    // ????????????????????
    public static IEnumerable<T> Before<T>(this IEnumerable<T> items, T first)
    {
        yield return first;

        foreach (var i in items)
            yield return i;
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
    public static int GetMedian(this IEnumerable<int> source)
    {
        if (source.Count() == 0)
        {
            throw new InvalidOperationException("Cannot compute median for an empty set.");
        }

        var sortedList = source.OrderBy(x => x);

        int itemIndex = (int)sortedList.Count() / 2;

        
            // Odd number of items.  
         return sortedList.ElementAt(itemIndex);
        
    }

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