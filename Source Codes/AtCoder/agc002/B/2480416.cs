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

        static int Solve(int N, int[][] queries)
        {
            var reds = new bool[N];
            var counts = Enumerable.Repeat(1, N).ToArray();
            reds[0] = true;
            foreach (var query in queries)
            {
                int a = query[0] - 1;
                int b = query[1] - 1;
                if (reds[a]) { reds[b] = true; }
                if (--counts[a] == 0) { reds[a] = false; }
                ++counts[b];
            }
            return reds.Count(red => red);
        }
        static void Main(string[] args)
        {
            var V = ReadInts();
            int N = V[0];
            int M = V[1];
            var queries = new int[M][];
            for (int i = 0; i < M; ++i) { queries[i] = ReadInts(); }
            Console.WriteLine(Solve(N, queries));
        }
    }
}