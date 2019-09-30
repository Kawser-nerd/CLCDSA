using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

namespace AtCoder
{
    class Program
    {
        private const int M = 1000000007;
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        private static long Solve(int N, long[] A)
        {
            long[] sums = new long[N];
            sums[0] = A[0];
            for (int i = 1; i < N; ++i) { sums[i] = sums[i - 1] + A[i]; }
            long min = long.MaxValue;
            for (int i = 0; i < N - 1; ++i)
            {
                min = Math.Min(Math.Abs(sums[N - 1] - sums[i] * 2), min);
            }
            return min;
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            long[] A = ReadLongs();
            Console.WriteLine(Solve(N, A));
        }
    }
}