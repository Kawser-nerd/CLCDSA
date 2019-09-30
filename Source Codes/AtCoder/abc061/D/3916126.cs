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
        #region
        //var NAB = Console.ReadLine();
        //var N = NAB[0];
        //var B = NAB[2];
        //var A = NAB[1];

        //var vn = Console.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => decimal.Parse(x)).ToList();
        //vn.Sort();
        //vn.Reverse();

        //decimal maxave = -1;
        //decimal before = -1;
        //decimal count = 0;
        //for (int i = 0; i < N; i++)
        //{
        //    if (before == vn[i])
        //    {

        //    }
        //    else
        //    {
        //        decimal num = 0;
        //        for (int j = 0; j <= i; j++)
        //        {
        //            num += vn[j];
        //        }
        //        if (maxave < num/(i + 1))
        //        {
        //            maxave = num / (i + 1);
        //            count = 1;
        //        }
        //        else if (maxave == num/(i + 1))
        //        {
        //            count++;
        //        }
        //    }


        //    before = vn[i];
        // 1
        //}
        #endregion



        var NM = Console.ReadLine().SplittedStringToInt32List();
        var N = NM[0];
        var M = NM[1];

        var edges = new List<Edge>();


        for (int i = 0; i < M; i++)
        {
            var abc = Console.ReadLine().SplittedStringToInt32List();
            var a = abc[0];
            var b = abc[1];
            var c = abc[2];

            edges.Add(new Edge() { Cost = -c, To = b - 1, From = a - 1 });
        }
        InitializeBellmanFord(N, M, edges);

        SearchShortestPath(0);
        var ans = ShortestDistances[N - 1];
        // InitializeBellmanFord(N, M, edges);

        SearchShortestPath2(0);
        if (Negatives[N - 1])
        {
            Console.WriteLine("inf");
        }
        else
        {
            Console.WriteLine(-ans);
        }

        Console.ReadLine();
        return;
        if (HasNegativeLoopFromSToG(0, N-1))
        {
            Console.WriteLine("inf");
        }
        else
        {
            SearchShortestPath(0);
            if (isfalse)
                Console.WriteLine("inf");
            else
                Console.WriteLine(-ShortestDistances[N-1]);
        }

        Console.ReadLine();
    }

    // s??????????????????????Bellman-Ford

    public static void InitializeBellmanFord(int v, int e, IEnumerable<Edge> edges)
    {
        V = v;
        Edges = edges.ToArray();
        ShortestDistances = new long[V];
        E = e;
    }

    public class Edge
    {
        public int From;
        public int To;
        public int Cost;
    }

    public static Edge[] Edges;

    public static long[] ShortestDistances;

    public static int V;

    public static int E;

    public static bool isfalse = false;

    public static void SearchShortestPath(int s)
    {
        for (int i = 0; i < V; i++)
        {
            ShortestDistances[i] = LONGINF;
        }
        ShortestDistances[s] = 0;
        var vcount = 0;
        while (vcount != V - 1)
        {
            vcount++;
            var update = false;
            for (int i = 0; i < E; i++)
            {
                var e = Edges[i];
                if (ShortestDistances[e.From] != LONGINF && ShortestDistances[e.To] > ShortestDistances[e.From] + e.Cost)
                {
                    ShortestDistances[e.To] = ShortestDistances[e.From] + e.Cost;
                    update = true;
                }
            }
            //if (!update)
              //  break;
        }
    }
    public static bool[] Negatives;
    public static void SearchShortestPath2(int s)
    {

        Negatives = new bool[V];
        ShortestDistances[s] = 0;
        var vcount = 0;
        while (vcount != V)
        {
            vcount++;
            var update = false;
            for (int i = 0; i < E; i++)
            {
                var e = Edges[i];
                if (ShortestDistances[e.From] != LONGINF && ShortestDistances[e.To] > ShortestDistances[e.From] + e.Cost)
                {
                    ShortestDistances[e.To] = ShortestDistances[e.From] + e.Cost;
                    update = true;
                    Negatives[e.To] = true;
                }
            }
           // if (!update)
             //   break;
        }
    }

    // ????????
    public static bool HasNegativeLoopAllgraph()
    {
        var d = new int[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < E; j++)
            {
                var e = Edges[j];
                if (d[e.To] > d[e.From] + e.Cost)
                {
                    d[e.To] = d[e.From] + e.Cost;
                    if (i == V - 1)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    // ?????????start???
    public static bool HasNegativeLoopFromS(int s)
    {
        var d = new int[V];
        for (int i = 0; i < V; i++)
        {
            d[i] = INF;
        }
        d[s] = 0;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < E; j++)
            {
                var e = Edges[j];
                if (d[e.From] != INF && d[e.To] > d[e.From] + e.Cost)
                {
                    d[e.To] = d[e.From] + e.Cost;
                    if (i == V - 1)
                        return true;
                }
            }
        }
        return false;
    }
    // ????????(start,destination??)
    public static bool HasNegativeLoopFromSToG(int s, int g)
    {
        var d = new long[V];
        for (int i = 0; i < V; i++)
        {
            d[i] = LONGINF;
        }
        d[s] = 0;
        for (int i = 0; i < 2 * V; i++)
        {
            for (int j = 0; j < E; j++)
            {
                var e = Edges[j];
                if (d[e.From] != LONGINF && d[e.To] > d[e.From] + e.Cost)
                {
                    d[e.To] = d[e.From] + e.Cost;
                    if (i >= V - 1 && e.To == g)
                        return true;
                }
            }
        }
        return false;
    }

    #region ?????
    public static long ToInt64(this string str) => long.Parse(str);
    public static int ToInt32(this string str) => int.Parse(str);
    public static BigInteger ToBigInteger(this string str) => BigInteger.Parse(str);
    public static List<string> SplittedStringToList(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
    public static List<int> SplittedStringToInt32List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();
    public static List<BigInteger> SplittedStringToBigInteger(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => BigInteger.Parse(x)).ToList();

    public const int INF = int.MaxValue / 2;

    public const long LONGINF = long.MaxValue / 2;
    #endregion
}