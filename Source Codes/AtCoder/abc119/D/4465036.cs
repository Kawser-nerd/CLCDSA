using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace AtCoder
{
    class Map
    {
        private readonly long[] values;

        public Map(long[] values)
        {
            this.values = values;
            Array.Sort(values);
        }

        public long[] Search(long value)
        {
            int a = 0;
            int b = values.Length - 1;
            if (value < values[a]) { return new[] { 0, values[a] }; }
            if (value > values[b]) { return new[] { values[b], long.MaxValue }; }
            while (b - a >= 2)
            {
                int m = (a + b) / 2;
                if (values[m] < value) { a = m; } else { b = m; }
            }
            return new[] { values[a], values[b] };
        }
    }

    class Program
    {
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        static IEnumerable<long> Solve(int A, int B, int Q, long[] S, long[] T, long[] X)
        {
            const long INF = long.MaxValue >> 2;
            var ans = new long[Q];
            var shrines = new Map(S);
            var temples = new Map(T);
            for (int q = 0; q < Q; ++q)
            {
                long x = X[q];
                var s = shrines.Search(x);
                var t = temples.Search(x);
                long min = long.MaxValue;
                long s0 = (s[0] > 0) ? x - s[0] : INF;
                long t0 = (t[0] > 0) ? x - t[0] : INF;
                long s1 = (s[1] < INF) ? s[1] - x : INF;
                long t1 = (t[1] < INF) ? t[1] - x : INF;
                min = Math.Min(Math.Max(s0, t0), min);
                min = Math.Min(Math.Max(s1, t1), min);
                min = Math.Min(Math.Min(s0, t1) * 2 + Math.Max(s0, t1), min);
                min = Math.Min(Math.Min(s1, t0) * 2 + Math.Max(s1, t0), min);
                ans[q] = min;
            }
            return ans;
        }
        static void Main(string[] args)
        {
            int[] V = ReadInts();
            int A = V[0], B = V[1], Q = V[2];
            long[] S = new long[A];
            for (int a = 0; a < A; ++a) { S[a] = ReadLong(); }
            long[] T = new long[B];
            for (int b = 0; b < B; ++b) { T[b] = ReadLong(); }
            long[] X = new long[Q];
            for (int q = 0; q < Q; ++q) { X[q] = ReadLong(); }
            foreach (long ans in Solve(A, B, Q, S, T, X))
            {
                Console.WriteLine(ans);
            }
        }
    }
}