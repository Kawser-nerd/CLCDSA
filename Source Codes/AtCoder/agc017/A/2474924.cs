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

        static long Solve(int N, int P, int[] A)
        {
            var dp = new long[] { 1, 0 };
            for (int i = 0; i < N; ++i)
            {
                if (A[i] % 2 == 0)
                {
                    dp[0] *= 2;
                    dp[1] *= 2;
                }
                else
                {
                    long sum = dp.Sum();
                    dp[0] = sum;
                    dp[1] = sum;
                }
            }
            return dp[P];
        }
        static void Main(string[] args)
        {
            var V = ReadInts();
            var A = ReadInts();
            Console.WriteLine(Solve(V[0], V[1], A));
        }
    }
}