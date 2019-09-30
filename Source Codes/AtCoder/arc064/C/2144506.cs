using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace ARC064E
{
    public class Program
    {
        public struct Circle
        {
            public long X;
            public long Y;
            public long R;

            public Circle(long x, long y, long r)
            {
                X = x;
                Y = y;
                R = r;
            }

            public double DistanceTo(Circle other)
            {
                return Math.Max(0, Math.Sqrt((X - other.X) * (X - other.X) + (Y - other.Y) * (Y - other.Y)) - (R + other.R));
            }
        }

        public static void Main(string[] args)
        {
            var sr = new StreamReader();
            //---------------------------------
            var Xs = sr.Next<long>();
            var Ys = sr.Next<long>();
            var Xt = sr.Next<long>();
            var Yt = sr.Next<long>();

            var N = sr.Next<int>();
            var O = sr.Next<long>(N, 3).Select(a => new Circle(a[0], a[1], a[2]));

            var circles = O.Concat(new[] {new Circle(Xs, Ys, 0), new Circle(Xt, Yt, 0),}).ToArray();

            var dij = new DijkstraUsedMatrix(N + 2);

            for (var i = 0; i < N + 2; i++)
            {
                for (var j = i + 1; j < N + 2; j++)
                {
                    dij.AddUndirectedEdge(i, j, circles[i].DistanceTo(circles[j]));
                }
            }

            Console.WriteLine(dij.GetDistances(N)[N + 1]);
            //---------------------------------
        }
    }

    public class DijkstraUsedMatrix
    {
        readonly double[,] costMatrix;

        public DijkstraUsedMatrix(int v)
        {
            costMatrix = new double[v, v];

            for (var i = 0; i < v; i++)
            {
                for (var j = 0; j < v; j++)
                {
                    costMatrix[i, j] = double.MaxValue;
                }
            }
        }

        public void AddDirectedEdge(int from, int to, double cost)
        {
            costMatrix[from, to] = cost;
        }

        public void AddUndirectedEdge(int v1, int v2, double cost)
        {
            AddDirectedEdge(v1, v2, cost);
            AddDirectedEdge(v2, v1, cost);
        }

        public double[] GetDistances(int start)
        {
            var v = costMatrix.GetLength(0);
            var willUse = new HashSet<int>(Enumerable.Range(0, v));
            var dist = new double[v];

            for (var i = 0; i < v; i++) dist[i] = double.MaxValue;
            dist[start] = 0;

            while (willUse.Count > 0)
            {
                var min = willUse.Min(wu => dist[wu]);
                var from = willUse.First(wu => dist[wu] == min);
                willUse.Remove(from);

                for (var to = 0; to < v; to++)
                {
                    if (costMatrix[from, to] == double.MaxValue) continue;
                    dist[to] = Math.Min(dist[to], dist[from] + costMatrix[from, to]);
                }
            }

            return dist;
        }
    }

    public class StreamReader
    {
        private readonly char[] _c = {' '};
        private int _index = -1;
        private string[] _input = new string[0];
        private readonly System.IO.StreamReader _sr = new System.IO.StreamReader(Console.OpenStandardInput());

        public T Next<T>()
        {
            if (_index == _input.Length - 1)
            {
                _index = -1;
                while (true)
                {
                    string rl = _sr.ReadLine();
                    if (rl == null)
                    {
                        if (typeof(T).IsClass) return default(T);
                        return (T)typeof(T).GetField("MinValue").GetValue(null);
                    }
                    if (rl != "")
                    {
                        _input = rl.Split(_c, StringSplitOptions.RemoveEmptyEntries);
                        break;
                    }
                }
            }
            return (T)Convert.ChangeType(_input[++_index], typeof(T), System.Globalization.CultureInfo.InvariantCulture);
        }

        public T[] Next<T>(int x)
        {
            var ret = new T[x];
            for (var i = 0; i < x; ++i) ret[i] = Next<T>();
            return ret;
        }

        public T[][] Next<T>(int y, int x)
        {
            var ret = new T[y][];
            for (var i = 0; i < y; ++i) ret[i] = Next<T>(x);
            return ret;
        }
    }
}