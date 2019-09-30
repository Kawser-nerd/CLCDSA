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
        var nc = Console.ReadLine().SplittedStringToInt32List();
        var n = nc[0];
        var c = nc[1];
        var channels = new int[c, 200010];

        for (int i = 0; i < n; i++)
        {
            var stc = Console.ReadLine().SplittedStringToInt32List();
            var ch = stc[2];
            var s = stc[0] - 1;
            var t = stc[1] - 1;
            channels[ch - 1, s*2 - 1 + 3] = 1;
            channels[ch - 1, t*2 + 3] = -1;
        }
        var treatedchs = new int[c, 200010];
        for (int i = 0; i < c; i++)
        {
            treatedchs[i, 0] = channels[i,0];
            for (int j = 0; j < 200010 - 1; j++)
            {
                treatedchs[i,j + 1] = treatedchs[i,j] + channels[i,j + 1];
            }
        }
        var maxcount = 0;

        for (int i = 0; i < 200010; i++)
        {
            var count = 0;

            for (int j = 0; j < c; j++)
            {
                if (treatedchs[j, i] > 0)
                    count++;
            }
            maxcount = Math.Max(maxcount, count);
        }
        Console.WriteLine(maxcount);
        Console.ReadLine();
        



        //var nm = Console.ReadLine().SplittedStringToInt32List();
        //var n = nm[0];
        //var m = nm[1];
        //InitializeUnionFind(n);
        //var abs = new List<KeyValuePair<int,int>>();
        //for (int i = 0; i < m; i++)
        //{
        //    var ab = Console.ReadLine().SplittedStringToInt32List();
        //    abs.Add(new KeyValuePair<int, int>(ab[0] - 1, ab[1] - 1));
        //}
        //abs.Reverse();
        //var ls = new List<int>();
        //foreach (var item in abs)
        //{
        //    Unite(item.Key, item.Value);
        //    ls.Add(ParentCount);
        //}
        //ls.Reverse();
        //var before = -1;
        //var befores = 0;
        //for (int i = 0; i < m; i++)
        //{
        //    if (before != -1)
        //    {
        //        var num = ls[i] - befores;
        //        Console.WriteLine((num * (num - 1))/2 + before);
        //        before = (num * (num - 1)) / 2 + before;
        //    }
        //    else
        //    {
        //        var num = ls[i] - befores;
        //        Console.WriteLine((num * ( num - 1)) / 2);
        //        before = (num * (num - 1)) / 2;
        //    }
        //    befores = ls[i];
        //}

        //Console.ReadLine();
    }


    public static List<List<int>> NBasedSearch(int n, int length)
    {
        if (length == 1)
        {
            var ls = new List<List<int>>();
            for (int i = 0; i < n; i++)
            {
                var lss = new List<int>();
                lss.Add(i);
                ls.Add(lss);
            }
            return ls;
        }
        else
        {
            var ans = NBasedSearch(n, length - 1);
            var news = new List<List<int>>();
            foreach (var item in ans)
            {
                for (int i = 0; i < n; i++)
                {
                    var based = item.ToList();
                    based.Add(i);
                    news.Add(based);
                }
            }
            return news;

        }
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



    public static int Manhattan(int x1, int x2, int y1, int y2)
    {
        return Math.Abs(x1 - x2) + Math.Abs(y1 - y2);
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


    public static IEnumerable<T> Before<T>(this IEnumerable<T> items, T first)
    {
        yield return first;

        foreach (var i in items)
            yield return i;
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
    }

    public static long f(long n, long b)
    {
        if (n < b)
        {
            return n;
        }
        else
        {
            return f((long)Math.Floor((double)n / b), b) + n % b;
        }
    }

    public static string N(long n, long b)
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
        return new string(sb.ToString().Reverse().ToArray());
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

    #endregion
}