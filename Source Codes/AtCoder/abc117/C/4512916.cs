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
        var nm = Console.ReadLine().SplittedStringToInt32List();
        var n = nm[0];
        var m = nm[1];
        var xm = Console.ReadLine().SplittedStringToInt32List().OrderBy(x => x).ToArray();
        var kukan = new List<int>();
        for (int i = 0; i < m - 1; i++)
        {
            kukan.Add(xm[i + 1] - xm[i]);
        }
        var sortedkukan = kukan.OrderByDescending(x => x);
        var removed = sortedkukan.Skip(n - 1);
        Console.WriteLine(removed.Sum());

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



    class PriorityQueue<T>
where T : IComparable<T>
    {
        List<T> buffer;

        public PriorityQueue() { buffer = new List<T>(); }
        public PriorityQueue(int capacity) { buffer = new List<T>(capacity); }

        static void PushHeap(List<T> array, T elem)
        {
            int n = array.Count;
            array.Add(elem);

            while (n != 0)
            {
                int i = (n - 1) / 2;
                if (array[n].CompareTo(array[i]) > 0)
                {
                    T tmp = array[n]; array[n] = array[i]; array[i] = tmp;
                }
                n = i;
            }
        }


        static void PopHeap(List<T> array)
        {
            int n = array.Count - 1;
            array[0] = array[n];
            array.RemoveAt(array.Count - 1);

            for (int i = 0, j; (j = 2 * i + 1) < n;)
            {
                if ((j != n - 1) && (array[j].CompareTo(array[j + 1]) < 0))
                    j++;
                if (array[i].CompareTo(array[j]) < 0)
                {
                    T tmp = array[j]; array[j] = array[i]; array[i] = tmp;
                }
                i = j;
            }
        }


        public void Push(T elem)
        {
            PushHeap(this.buffer, elem);
        }


        public T Pop()
        {
            var data = buffer[0];
            PopHeap(buffer);
            return data;
        }

        public int Count
        {
            get { return buffer.Count; }
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