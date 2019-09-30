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
        // dijkstra?r_1,r_2,...,r_n???????????????????????????next_permutation?????????????
        // ???????
        var nmr = Console.ReadLine().SplittedStringToInt32List();
        var n = nmr[0];
        var m = nmr[1];
        var r = nmr[2];
        var dijk = new Dijkstra(n, true);

        var rn = Console.ReadLine().SplittedStringToInt32List();
        for (int i = 0; i < m; i++)
        {
            var abc = Console.ReadLine().SplittedStringToInt32List();
            var a = abc[0] - 1;
            var b = abc[1] - 1;
            var c = abc[2];
            dijk.AddPath(a, b, c);
            dijk.AddPath(b, a, c); ;
        }
        var mincosts = new int[r][];
        
        for (int i = 0; i < r; i++)
        {
            mincosts[i] = dijk.GetMinCost(rn[i] - 1);
        }
        var permuse = Perm(Enumerable.Range(0, r));
        var mincost = INF;
        foreach (var item in permuse)
        {
            var ls = item.ToArray();
            var cost = 0;
            for (int i = 0; i < r - 1; i++)
            {
                cost += mincosts[ls[i]][rn[ls[i + 1]] - 1];
            }
            
            mincost = Math.Min(mincost, cost);
        }
        Console.WriteLine(mincost);

        Console.ReadLine();
    }

    

    public static int Manhattan(int x1,int x2,int y1,int y2)
    {
        return Math.Abs(x1 - x2) + Math.Abs(y1 - y2);
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
    public static bool IsOk = true;
    
    public class Dijkstra
    {

        public class Edge
        {
            public int To;
            public int Cost;
        }

        private int maxIndex = -1;
        private const int INF = Int32.MaxValue;
        public readonly bool IsConnectedList;
        private int[,] _edgeArray;
        private List<Edge>[] _edges;

        public Dijkstra(int size, bool islist)
        {
            maxIndex = size + 1;

            if (!islist)
            {
                _edgeArray = new int[maxIndex, maxIndex];

                for (int i = 0; i < _edgeArray.GetLength(0); i++)
                {
                    for (int j = 0; j < _edgeArray.GetLength(1); j++)
                    {
                        _edgeArray[i, j] = INF;
                        if (i == j) _edgeArray[i, j] = 0;
                    }
                }
            }
            else
            {
                _edges = new List<Edge>[maxIndex];
                for (int i = 0; i < maxIndex; i++)
                {
                    _edges[i] = new List<Edge>();
                }
            }
            IsConnectedList = islist;

        }

        public void AddPath(int s, int t, int cost)
        {
            if (!IsConnectedList)
                _edgeArray[s, t] = Math.Min(_edgeArray[s, t], cost);
            else
                _edges[s].Add(new Edge() { Cost = cost, To = t });

        }

        public int[] GetMinCost(int s)
        {
            int[] cost = new int[maxIndex];
            for (int i = 0; i < cost.Length; i++) cost[i] = INF;
            cost[s] = 0;

            var priorityQueue = new PriorityQueue<ComparablePair<int, int>>(maxIndex);
            priorityQueue.Push(new ComparablePair<int, int>(0, s));
            if (!IsConnectedList)
            {
                while (priorityQueue.Count > 0)
                {
                    var costDestinationPair = priorityQueue.Pop();
                    if (cost[costDestinationPair.Item2] < costDestinationPair.Item1) continue;

                    for (int i = 0; i < maxIndex; i++)
                    {
                        int newCostToi = _edgeArray[costDestinationPair.Item2, i] == INF ? INF :
                            costDestinationPair.Item1 + _edgeArray[costDestinationPair.Item2, i];
                        if (newCostToi < cost[i])
                        {
                            cost[i] = newCostToi;

                            priorityQueue.Push(new ComparablePair<int, int>(newCostToi, i));
                        }
                        
                    }
                }
            }
            else
            {
                while (priorityQueue.Count > 0)
                {
                    var costDestinationPair = priorityQueue.Pop();
                    if (cost[costDestinationPair.Item2] < costDestinationPair.Item1) continue;

                    var ls = _edges[costDestinationPair.Item2];
                    foreach (var item in ls)
                    {
                        var newCostToi = item.Cost + costDestinationPair.Item1;
                        if (newCostToi < cost[item.To])
                        {
                            cost[item.To] = newCostToi;

                            priorityQueue.Push(new ComparablePair<int, int>(newCostToi, item.To));
                        }
                    }
                }
            }


            return cost;
        }

        public int GetMinCost(int s, int t)
        {
            return GetMinCost(s)[t];
        }
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


    public class ComparablePair<T, U> : IComparable, IComparable<ComparablePair<T, U>> where T : IComparable<T>
    {
        public readonly T Item1;
        public readonly U Item2;

        public int CompareTo(object obj)
        {
            ComparablePair<T, U> castedObj = (ComparablePair<T, U>)obj;
            return this.Item1.CompareTo(castedObj.Item1);
        }

        public int CompareTo(ComparablePair<T, U> other)
        {
            return Item1.CompareTo(other.Item1);
        }

        public ComparablePair(T t, U u)
        {
            Item1 = t;
            Item2 = u;
        }
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