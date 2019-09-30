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
            public int[] counts = new int[1025];
            private int Count(int n)
            {
                int count = 0;
                while (n > 0)
                {
                    if ((n & 1) != 0) { ++count; }
                    n >>= 1;
                }
                return count;
            }
            public Solver()
            {
                for (int i = 1; i <= 1024; ++i) { counts[i] = Count(i); }
            }
            public int Solve(int N, int[] F, int[][] P)
            {
                int max = int.MinValue;
                for (int i = 1; i < 1024; ++i)
                {
                    int p = 0;
                    for (int j = 0; j < N; ++j)
                    {
                        p += P[j][Count(i & F[j])];
                    }
                    max = Math.Max(p, max);
                }
                return max;
            }
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            var F = new int[N];
            for (int i = 0; i < N; ++i)
            {
                int[] v = ReadInts();
                for (int j = 0; j < 10; ++j)
                {
                    F[i] <<= 1;
                    F[i] |= v[j];
                }
            }
            var P = new int[N][];
            for (int i = 0; i < N; ++i) { P[i] = ReadInts(); }
            Console.WriteLine(new Solver().Solve(N, F, P));
        }
    }
}