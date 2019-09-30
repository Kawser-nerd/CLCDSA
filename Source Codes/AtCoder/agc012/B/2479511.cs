using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        private const int MODULO = 1000000007;
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        class Solver
        {
            private readonly int[] colors;
            private readonly List<int>[] paths;
            private readonly HashSet<Tuple<int, int>> set;
            public Solver(int N, int[][] edges)
            {
                colors = new int[N];
                paths = new List<int>[N];
                for (int i = 0; i < N; ++i)
                {
                    paths[i] = new List<int>();
                }
                foreach (var edge in edges)
                {
                    int a = edge[0] - 1;
                    int b = edge[1] - 1;
                    paths[a].Add(b);
                    paths[b].Add(a);
                }
                set = new HashSet<Tuple<int, int>>();
            }
            private void Paint(int v, int d, int c)
            {
                var key = new Tuple<int, int>(v, d);
                if (!set.Contains(key))
                {
                    if (d == 0)
                    {
                        colors[v] = c;
                    }
                    else
                    {
                        Paint(v, d - 1, c);
                        foreach (int u in paths[v])
                        {
                            Paint(u, d - 1, c);
                        }
                    }
                    set.Add(key);
                }
            }
            public IEnumerable<int> Solve(int[][] queries)
            {
                foreach (var q in queries.Reverse())
                {
                    int v = q[0] - 1;
                    int d = q[1];
                    int c = q[2];
                    Paint(v, d, c);
                }
                return colors;
            }
        }
        static void Main(string[] args)
        {
            var V = ReadInts();
            var N = V[0];
            var M = V[1];
            var edges = new int[M][];
            for (int i = 0; i < M; ++i) { edges[i] = ReadInts(); }
            var Q = ReadInt();
            var queries = new int[Q][];
            for (int i = 0; i < Q; ++i) { queries[i] = ReadInts(); }
            foreach (int ans in new Solver(N, edges).Solve(queries))
            {
                Console.WriteLine(ans);
            }
        }
    }
}