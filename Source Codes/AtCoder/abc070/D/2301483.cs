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
            private readonly long[] costs;
            public Solver(int N, int K, List<Tuple<int, int>>[] paths)
            {
                var q = new Queue<int>();
                costs = Enumerable.Repeat(long.MaxValue, N).ToArray();
                costs[K] = 0;
                q.Enqueue(K);
                while (q.Count > 0)
                {
                    int i = q.Dequeue();
                    foreach (var path in paths[i])
                    {
                        int j = path.Item1;
                        int cost = path.Item2;
                        if (costs[j] > costs[i] + cost)
                        {
                            costs[j] = costs[i] + cost;
                            q.Enqueue(j);
                        }
                    }
                }
            }
            public IEnumerable<long> Solve(int Q, Tuple<int, int>[] queries)
            {
                var answers = new long[Q];
                for (int i = 0; i < Q; ++i)
                {
                    int x = queries[i].Item1;
                    int y = queries[i].Item2;
                    answers[i] = costs[x] + costs[y];
                }
                return answers;
            }
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            var paths = new List<Tuple<int, int>>[N];
            for (int i = 0; i < N; ++i) { paths[i] = new List<Tuple<int, int>>(); }
            for (int i = 0; i < N - 1; ++i)
            {
                int[] v2 = ReadInts();
                int a = v2[0] - 1;
                int b = v2[1] - 1;
                int c = v2[2];
                paths[a].Add(new Tuple<int, int>(b, c));
                paths[b].Add(new Tuple<int, int>(a, c));
            }
            int[] v1 = ReadInts();
            int Q = v1[0];
            int K = v1[1] - 1;
            var queries = new Tuple<int, int>[Q];
            for (int i = 0; i < Q; ++i)
            {
                int[] v2 = ReadInts();
                queries[i] = new Tuple<int, int>(v2[0] - 1, v2[1] - 1);
            }
            foreach (var ans in new Solver(N, K, paths).Solve(Q, queries))
            {
                Console.WriteLine(ans);
            }
        }
    }
}