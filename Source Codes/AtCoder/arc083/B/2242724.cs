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
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        private static long Solve(int N, long[][] A)
        {
            if (N == 1) { return 0; }
            long sum = A.Sum(a => a.Sum()) / 2;
            if (N == 2) { return sum; }
            for (int i = 0; i < N; ++i)
            {
                for (int j = i + 1; j < N; ++j)
                {
                    long min = Enumerable.Range(0, N).Where(k => k != i && k != j).Min(k => A[i][k] + A[k][j]);
                    if (min < A[i][j]) { return -1; }
                    if (min == A[i][j]) { sum -= A[i][j]; }
                }
            }
            return sum;
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            long[][] A = new long[N][];
            for (int i = 0; i < N; ++i) { A[i] = ReadLongs(); }
            Console.WriteLine(Solve(N, A));
        }
    }
}