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
        
        var N = Console.ReadLine().ToInt32();

        var edge = new List<Edge>[N];
        for (int i = 0; i < N; i++)
        {
            edge[i] = new List<Edge>();
        }
        for (int i = 0; i < N - 1; i++)
        {
            var abc = Console.ReadLine().SplittedStringToInt32List();
            var a = abc[0] - 1;
            var b = abc[1] -1 ;
            var c = abc[2];
            edge[a].Add(new Edge() { To = b, Cost = c });
            edge[b].Add(new Edge() { To = a, Cost = c });
        }
        
        var QK = Console.ReadLine().SplittedStringToInt32List();
        var Q = QK[0];
        var K = QK[1] - 1;

        var queue = new Queue<Point>();
        queue.Enqueue(new Point() { CostFromStart = 0, Number = K });
        var costs = new long[N];
        
        while (queue.Count() != 0)
        {
            var item = queue.Dequeue();
            foreach (var item2 in edge[item.Number])
            {
                if (costs[item2.To] != 0)
                    continue;
                costs[item2.To] += item2.Cost + costs[item.Number];
                var p = new Point() { Number = item2.To, CostFromStart = costs[item2.To] };
                queue.Enqueue(p);
            }
        }
        for (int i = 0; i < Q; i++)
        {
            var str = Console.ReadLine().SplittedStringToInt32List();
            var x = str[0] -1 ;
            var y = str[1] -1;
            Console.WriteLine(costs[x] + costs[y]);
        }

        Console.ReadLine();
    }

    public class Edge
    {
        public int To;
        public int Cost;
    }

    public class Point
    {
        public int Number;
        public long CostFromStart;
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