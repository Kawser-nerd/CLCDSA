using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
 
namespace AtCoder
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var sw = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
            Console.SetOut(sw);
            new Program().Solve(new MyInputStream(Console.In, ' '));
            Console.Out.Flush();
        }
 
        public void Solve(MyInputStream cin)
        {
            var N = cin.ReadInt();
            var M = cin.ReadInt();
            var g = new AdjacencyListGraph(N);
            for (int i = 0; i < M; ++i)
            {
                var a = cin.ReadInt() - 1;
                var b = cin.ReadInt() - 1;
                g.AddUnDirectedEdge(a, b, 1);
            }
 
            var dist = g.WarshallFloyd();
            for (int i = 0; i < N; ++i)
            {
                if (g[i].Count == 0) WriteLine(0);
                else
                {
                    var cnt = 0;
                    for (int j = 0; j < N; ++j)
                        if (dist[i, j] == 2) cnt++;
                    WriteLine(cnt - 1);
                }
            }
        }
    }
 
    public class AdjacencyListGraph
    {
        public struct Edge
        {
            public int To { get; set; }
            public long Cap { get; set; }
            public long Cost { get; set; }
            public long Flow { get; set; }
            public long Rev { get; set; }
            public Edge(int to, long cost = 0, long cap = -1)
            {
                this.To = to;
                this.Cost = cost;
                this.Cap = cap;
                this.Rev = cap;
                this.Flow = 0;
            }
        }
 
        private List<List<Edge>> g;
        public int N { get; private set; }
        public AdjacencyListGraph(int size)
        {
            N = size;
            g = new List<List<Edge>>(size);
            for (int i = 0; i < size; i++) g.Add(new List<Edge>());
        }
 
        public List<Edge> this[int idx]
        {
            get { return g[idx]; }
        }
 
        public void AddDirectedEdge(int from, int to, long cost = 0, long cap = -1)
        {
            g[from].Add(new Edge(to, cost, cap));
        }
 
        public void AddUnDirectedEdge(int from, int to, int cost = 0, long cap = -1)
        {
            AddDirectedEdge(from, to, cost, cap);
            AddDirectedEdge(to, from, cost, cap);
        }
 
        public long[,] WarshallFloyd()
        {
            long INF = long.MaxValue >> 1;
            var ret = new long[N, N];
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    ret[i, j] = INF;
 
            for (int i = 0; i < N; ++i)
                foreach (var v in g[i])
                    ret[i, v.To] = v.Cost;
 
            for (int k = 0; k < N; ++k)
                for (int i = 0; i < N; ++i)
                    for (int j = 0; j < N; ++j)
                        ret[i, j] = Math.Min(ret[i, j], ret[i, k] + ret[j, k]);
            return ret;
        }
    }
 
    public class MyInputStream
    {
        private readonly System.IO.TextReader _stream;
        private char separator = ' ';
        private Queue<string> inputStream;
        public MyInputStream(System.IO.TextReader s, char separator = ' ')
        {
            this.separator = separator;
            this._stream = s;
            inputStream = new Queue<string>();
        }
        public string Read()
        {
            if (inputStream.Count != 0) return inputStream.Dequeue();
            string[] tmp = _stream.ReadLine().Split(separator);
            for (int i = 0; i < tmp.Length; ++i)
                inputStream.Enqueue(tmp[i]);
            return inputStream.Dequeue();
        }
        public string ReadLine() { return _stream.ReadLine(); }
        public int ReadInt() { return int.Parse(Read()); }
        public long ReadLong() { return long.Parse(Read()); }
        public double ReadDouble() { return double.Parse(Read()); }
        public string[] ReadStrArray(long N) { var ret = new string[N]; for (long i = 0; i < N; ++i) ret[i] = Read(); return ret;}
        public int[] ReadIntArray(long N) { var ret = new int[N]; for (long i = 0; i < N; ++i) ret[i] = ReadInt(); return ret;}
        public long[] ReadLongArray(long N) { var ret = new long[N]; for (long i = 0; i < N; ++i) ret[i] = ReadLong(); return ret;}
    }
}