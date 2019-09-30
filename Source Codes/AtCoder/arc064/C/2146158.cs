using System;
using System.IO;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;

namespace ARC064E_2
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

            public double GetDistanceTo(Circle other)
            {
                return Math.Max(0, Math.Sqrt((X - other.X) * (X - other.X) + (Y - other.Y) * (Y - other.Y)) - (R + other.R));
            }
        }

        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            var Xs = ss.Next(int.Parse);
            var Ys = ss.Next(int.Parse);
            var Xt = ss.Next(int.Parse);
            var Yt = ss.Next(int.Parse);

            var N = ss.Next(int.Parse);
            var O = ss.Next(int.Parse, 3, N)
                .Select(a => new Circle(a[0], a[1], a[2]))
                .Concat(new[] {new Circle(Xs, Ys, 0), new Circle(Xt, Yt, 0),})
                .ToArray();

            var dijk = new DijkstraUsedMatrix(N + 2);

            for (var i = 0; i < N + 2; i++)
            {
                for (var j = i + 1; j < N + 2; j++)
                {
                    dijk.AddUndirectedEdge(i, j, O[i].GetDistanceTo(O[j]));
                }
            }

            sw.WriteLine(dijk.GetDistances(N)[N + 1]);
            //---------------------------------
        }

        static void Main()
        {
            var ss = new StreamScanner(new StreamReader(Console.OpenStandardInput()));
            var sw = new StreamWriter(Console.OpenStandardOutput()) {AutoFlush = false};
            new Program().Solve(ss, sw);
            sw.Flush();
        }

        static readonly Func<string, string> Str = s => s;
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

    public class StreamScanner
    {
        static readonly char[] Sep = {' '};
        readonly Queue<string> buffer = new Queue<string>();
        readonly TextReader textReader;

        public StreamScanner(TextReader textReader)
        {
            this.textReader = textReader;
        }

        [SuppressMessage("ReSharper", "PossibleNullReferenceException")]
        public T Next<T>(Func<string, T> parser)
        {
            if (buffer.Count != 0) return parser(buffer.Dequeue());
            var nextStrings = textReader.ReadLine().Split(Sep, StringSplitOptions.RemoveEmptyEntries);
            foreach (var nextString in nextStrings) buffer.Enqueue(nextString);
            return Next(parser);
        }

        public T[] Next<T>(Func<string, T> parser, int x)
        {
            var ret = new T[x];
            for (var i = 0; i < x; ++i) ret[i] = Next(parser);
            return ret;
        }

        public T[][] Next<T>(Func<string, T> parser, int x, int y)
        {
            var ret = new T[y][];
            for (var i = 0; i < y; ++i) ret[i] = Next(parser, x);
            return ret;
        }
    }
}