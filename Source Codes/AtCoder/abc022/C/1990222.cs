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
            var g = new Graph(N);
            var f = new Graph(N);
            for (int i = 0; i < M; i++)
            {
                var u = cin.ReadInt() - 1;
                var v = cin.ReadInt() - 1;
                var l = cin.ReadInt();
                g.AddUnDirectedEdge(u, v, l);
                if (u != 0 && v != 0) f.AddUnDirectedEdge(u, v, l);
            }
            var dist = f.WarshallFloyd();

            if (g[0].Count < 2)
            {
                WriteLine(-1);
                return;
            }

            var min = long.MaxValue;
            for (int i = 0; i < g[0].Count - 1; ++i)
                for (int j = i + 1; j < g[0].Count; ++j)
                    if (i != j && dist[g[0][i].To, g[0][j].To] != long.MaxValue) min = Math.Min(dist[g[0][i].To, g[0][j].To] + g[0][i].Cost + g[0][j].Cost, min);


            if (min == long.MaxValue) WriteLine(-1);
            else WriteLine(min);
        }
    }

    public class Graph
    {
        public struct Edge
        {
            public int To { get; set; }
            public long Cost { get; set; }
            public Edge(int to, long cost = 0, long cap = -1)
            {
                this.To = to;
                this.Cost = cost;
            }
        }

        private List<List<Edge>> g;
        public int N { get; private set; }
        public Graph(int size)
        {
            N = size;
            g = new List<List<Edge>>(size);
            for (int i = 0; i < size; i++) g.Add(new List<Edge>());
        }

        public List<Edge> this[int i]
        {
            get
            {
                if (i < 0 || i >= N) throw new IndexOutOfRangeException();
                return g[i];
            }
        }

        public void AddDirectedEdge(int from, int to, long cost = 0)
        {
            g[from].Add(new Edge(to, cost));
        }

        public void AddUnDirectedEdge(int from, int to, int cost = 0)
        {
            AddDirectedEdge(from, to, cost);
            AddDirectedEdge(to, from, cost);
        }
    }

    public static class GraphUtility
    {
        public static long[,] WarshallFloyd(this Graph g)
        {
            var N = g.N;
            long INF = long.MaxValue;
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
                        if (ret[i, k] != INF && ret[j, k] != INF)
                            ret[i, j] = Math.Min(ret[i, j], ret[i, k] + ret[j, k]);
            return ret;
        }

        // dot:   ?????
        // neato: ?????
        // twopi: ?????
        // circo: ????
        // osage:
        public static void DrawGraph(this Graph g, string filename, bool drawCost = true, string layout = "dot", bool undirected = false, bool exec = true)
        {
            if (drawCost) DrawGraph(g, filename, (e) => e.Cost.ToString(), layout, undirected, exec);
            else DrawGraph(g, filename, (e) => "", layout, undirected, exec);
        }
        public static void DrawGraph(this Graph g, string filename, Func<Graph.Edge, string> Drawer, string layout = "dot", bool undirected = false, bool exec = true)
        {
            using (var sw = new System.IO.StreamWriter($"./{filename}.dot"))
            {
                if (undirected) sw.WriteLine("graph graph_name{");
                else sw.WriteLine("digraph graph_name{");
                sw.WriteLine($"    layout={layout};");
                for (int i = 0; i < g.N; ++i)
                {
                    if (g[i].Count == 0) continue;
                    for (int j = 0; j < g[i].Count; ++j)
                    {
                        if (undirected)
                        {
                            if (i >= g[i][j].To) continue;
                            sw.Write($"    {i} -- {g[i][j].To}");
                            var val = "";
                            if ((val = Drawer(g[i][j])) != "")
                                sw.Write($" [ label = \"{val}\"]");
                            sw.WriteLine();
                        }
                        else
                        {
                            sw.Write($"    {i} -> {g[i][j].To}");
                            var val = "";
                            if ((val = Drawer(g[i][j])) != "")
                                sw.Write($" [ label = \"{val}\"]");
                            sw.WriteLine();
                        }
                    }
                }
                sw.WriteLine("}");
            }
            if (exec) System.Diagnostics.Process.Start("dot", $" -T png {filename}.dot -o {filename}.png");
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