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

        static bool Solve(int N, int M, int[][] queries)
        {
            var counts = new int[N + 1];
            foreach (var q in queries)
            {
                ++counts[q[0]];
                ++counts[q[1]];
            }
            return counts.All(n => n % 2 == 0);
        }
        static void Main(string[] args)
        {
            var V = ReadInts();
            int N = V[0];
            int M = V[1];
            int[][] queries = new int[M][];
            for (int i = 0; i < M; ++i) { queries[i] = ReadInts(); }
            Console.WriteLine(Solve(N, M, queries) ? "YES" : "NO");
        }
    }
}