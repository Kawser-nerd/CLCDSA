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
using System.Timers;

static class MainClass
{
    public static void Main(string[] args)
    {
        var NM = Console.ReadLine().SplittedStringToInt32List();
        var N = NM[0];
        var M = NM[1];
        var d = new int[N + 1, N + 1];
        var Mcount = 0;
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                if (i != j)
                    d[i, j] = INF;
                else
                    d[i, j] = 0;
            }
        }
        for (int i = 0; i < M; i++)
        {
            var str = Console.ReadLine().SplittedStringToInt32List();
            d[str[0], str[1]] = str[2];
            d[str[1], str[0]] = str[2];
            Mcount++;
        }
        InitializeWarshallFloyd(N, d);

        var dic = new List<Edge>();

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                var paths = SearchPaths(i + 1, j + 1);
                for (int k = 0; k < paths.Length - 1; k++)
                {
                    dic.Add(new Edge() { From = paths[k], To = paths[k + 1] });
                }
            }
        }
        var count = dic.Distinct(new Edge()).Where(x => x.To != 0 && x.From != 0).Where(x => x.From != x.To).ToList();
        Console.WriteLine(Mcount - count.Count);

        Console.ReadLine();
    }

    public class Edge : IEqualityComparer<Edge>
    {
        public int From;
        public int To;

        public bool Equals(Edge x, Edge y)
        {
            if (x.From == y.From && x.To == y.To)
                return true;
            if (x.To == y.From && x.From == y.To)
            {
                return true;
            }
            
            return false;

        }

        public int GetHashCode(Edge obj)
        {
            return ((obj.From + obj.To)*(obj.From * obj.To)).GetHashCode();
        }
    }

    public static int[,] ShortestPaths;
    public static int[,] LastPath;

    public static int V;

    // n = vertex
    public static void InitializeWarshallFloyd(int n,int[,] edges)
    {
        LastPath = new int[n + 1,n + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                LastPath[i, j] = i;
            }
        }

        if (edges != null)
        {
            ShortestPaths = edges;
        }
        else
        {
            throw new ArgumentNullException();
        }

        V = n;
        for (int i = 0; i <= V; i++)
        {
            for (int j = 0; j <= V; j++)
            {
                for (int k = 0; k <= V; k++)
                {
                    var before = ShortestPaths[j, k];
                    ShortestPaths[j, k] = Math.Min(ShortestPaths[j, k], ShortestPaths[j, i] + ShortestPaths[i, k]);
                    if (ShortestPaths[j,k] != before)
                    {
                        LastPath[j, k] = LastPath[i, k];
                    }
                }
            }
        }
    }


    public static int sp;
    public static int[] SearchPaths(int start, int dest)
    {
        var stack = new int[V];
        var current = dest;
        sp = 0;
        while (current != start)
        {
            if (sp++ == 0)
                stack[0] = current;
            else
                stack[sp - 1] = current = LastPath[start, current];
        }
        // stack[sp++] = start;
        return stack;
    }


    #region ?????
    public static long ToInt64(this string str) => long.Parse(str);
    public static int ToInt32(this string str) => int.Parse(str);
    public static BigInteger ToBigInteger(this string str) => BigInteger.Parse(str);
    public static List<string> SplittedStringToList(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
    public static List<int> SplittedStringToInt32List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();
    public static List<BigInteger> SplittedStringToBigInteger(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => BigInteger.Parse(x)).ToList();

    public const int INF = int.MaxValue / 2;
    #endregion
}