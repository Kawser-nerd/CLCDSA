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

        static long Solve(int N, int[] A)
        {
            int x = 0;
            long sum = 0;
            for (int i = N - 1; i >= 0; --i)
            {
                if (A[i] > i) { return -1; }
                if (A[i] < x) { return -1; }
                if (A[i] > x)
                {
                    x = A[i];
                    sum += A[i];
                }
                x = Math.Max(x - 1, 0);
            }
            return sum;
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            int[] A = new int[N];
            for (int i = 0; i < N; ++i) { A[i] = ReadInt(); }
            Console.WriteLine(Solve(N, A));
        }
    }
}