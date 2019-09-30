using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Solver
    {
        private readonly long[] L;
        private Dictionary<Tuple<int, long>, long> memo;
        public Solver()
        {
            L = new long[51];
            L[0] = 1;
            for (int i = 1; i <= 50; ++i) { L[i] = L[i - 1] * 2 + 3; }
            memo = new Dictionary<Tuple<int, long>, long>();
        }
        public long Solve(int N, long X)
        {
            if (X <= 0) { return 0; }
            if (N == 0) { return 1; }
            var key = new Tuple<int, long>(N, X);
            if (!memo.ContainsKey(key))
            {
                long sum = 0;
                long M = L[N - 1];
                if (X - 1 > 0)     { sum += Solve(N - 1, Math.Min(X - 1, M)); }
                if (X - M - 1 > 0) { sum += 1; }
                if (X - M - 2 > 0) { sum += Solve(N - 1, Math.Min(X - M - 2, M)); }
                memo[key] = sum;
            }
            return memo[key];
        }
    }
    class Program
    {
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }

        static void Main(string[] args)
        {
            long[] V = ReadLongs();
            Console.WriteLine(new Solver().Solve((int)V[0], V[1]));
        }
    }
}