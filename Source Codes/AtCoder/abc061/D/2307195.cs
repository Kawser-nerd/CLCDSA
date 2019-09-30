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

        class Path
        {
            public readonly int a;
            public readonly int b;
            public readonly long c;
            public Path(long[] v)
            {
                a = (int)(v[0] - 1);
                b = (int)(v[1] - 1);
                c = v[2];
            }
        }
        static long? Solve(int N, int M, Path[] paths)
        {
            var d = Enumerable.Repeat(long.MinValue / 2, N).ToArray();
            d[0] = 0;
            for (int i = 0; i < N; ++i)
            {
                foreach (Path p in paths)
                {
                    d[p.b] = Math.Max(d[p.a] + p.c, d[p.b]);
                }
            }
            for (int i = 0; i < N; ++i)
            {
                foreach (Path p in paths)
                {
                    if (p.b == N - 1 && d[p.a] + p.c > d[p.b]) { return null; }
                    d[p.b] = Math.Max(d[p.a] + p.c, d[p.b]);
                }
            }
            return d[N - 1];
        }
        static void Main(string[] args)
        {
            int[] v = ReadInts();
            int N = v[0];
            int M = v[1];
            var paths = new Path[M];
            for (int i = 0; i < M; ++i) { paths[i] = new Path(ReadLongs()); }
            var ans = Solve(N, M, paths);
            Console.WriteLine((ans != null) ? ans.ToString() : "inf");
        }
    }
}