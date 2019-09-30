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
            const int N = 100000;
            private int[] sums = new int[N + 1];
            public Solver()
            {
                var p1 = new HashSet<int>() { 2 };
                var p2 = new HashSet<int>();
                for (int i = 3; i <= N; ++i)
                {
                    if (p1.All(j => i % j != 0))
                    {
                        if (i * i <= N) { p1.Add(i); } else { p2.Add(i); }
                    }
                }
                Predicate<int> prime = n => (n * n <= N) ? p1.Contains(n) : p2.Contains(n);
                for (int i = 3; i < N; ++i)
                {
                    sums[i] = (i % 2 != 0 && prime(i) && prime((i + 1) / 2)) ? 1 + sums[i - 1] : sums[i - 1];
                    sums[i + 1] = sums[i];
                }
            }
            public int Solve(int l, int r)
            {
                return sums[r] - sums[l - 1];
            }
        }
        static void Main(string[] args)
        {
            int Q = ReadInt();
            var solver = new Solver();
            for (int i = 0; i < Q; ++i)
            {
                int[] v = ReadInts();
                Console.WriteLine(solver.Solve(v[0], v[1]));
            }
        }
    }
}