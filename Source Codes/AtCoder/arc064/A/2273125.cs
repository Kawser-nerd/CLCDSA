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

        static long Solve(int N, int x, long[] A)
        {
            long sum = 0;
            for (int i = 0; i + 1 < N; ++i)
            {
                if (A[i] + A[i + 1] > x)
                {
                    long a = Math.Min(A[i] + A[i + 1] - x, A[i + 1]);
                    A[i + 1] -= a;
                    sum += a;
                }
                if (A[i] > x)
                {
                    long a = A[i] - x;
                    A[i] -= a;
                    sum += a;
                }
            }
            return sum;
        }
        static void Main(string[] args)
        {
            int[] v = ReadInts();
            long[] A = ReadLongs();
            Console.WriteLine(Solve(v[0], v[1], A));
        }
    }
}