using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        private const int K = 1000000007;
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        static int Fac(int n)
        {
            long fac = 1;
            for (int i = 2; i <= n; ++i)
            {
                fac *= i;
                fac %= K;
            }
            return (int)fac;
        }
        static int Solve(int N, int M)
        {
            if (Math.Abs(N - M) > 1) { return 0; }
            long p = Math.BigMul(Fac(N), Fac(M));
            return (N != M) ? (int)(p * 1 % K)
                            : (int)(p * 2 % K);
        }
        static void Main(string[] args)
        {
            int[] values = ReadInts();
            Console.WriteLine(Solve(values[0], values[1]));
        }
    }
}