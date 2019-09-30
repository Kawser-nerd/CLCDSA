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

        static IEnumerable<int> Solve(int H, int W, int D, Tuple<int, int>[] points, Tuple<int, int>[] queries)
        {
            int[] memo = new int[H * W + 1];
            for (int i = D + 1; i <= H * W; ++i)
            {
                var a = points[i - D];
                var b = points[i];
                memo[i] = memo[i - D] + Math.Abs(b.Item1 - a.Item1) + Math.Abs(b.Item2 - a.Item2);
            }
            return queries.Select(q => memo[q.Item2] - memo[q.Item1]);
        }
        static void Main(string[] args)
        {
            int[] v1 = ReadInts();
            int H = v1[0];
            int W = v1[1];
            int D = v1[2];
            var points = new Tuple<int, int>[H * W + 1];
            for (int i = 0; i < H; ++i)
            {
                int[] v2 = ReadInts();
                for (int j = 0; j < W; ++j)
                {
                    points[v2[j]] = new Tuple<int, int>(i, j);
                }
            }
            int Q = ReadInt();
            var queries = new Tuple<int, int>[Q];
            for (int i = 0; i < Q; ++i)
            {
                int[] v2 = ReadInts();
                queries[i] = new Tuple<int, int>(v2[0], v2[1]);
            }
            foreach (int sum in Solve(H, W, D, points, queries))
            {
                Console.WriteLine(sum);
            }
        }
    }
}