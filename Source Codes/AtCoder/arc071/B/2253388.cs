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

        static long Solve(int n, int m, long[] X, long[] Y)
        {
            long x = 0;
            long y = 0;
            for (int i = 0, k = -n + 1; i < n; ++i, k += 2)
            {
                x += X[i] * k;
                x %= MODULO;
            }
            for (int i = 0, k = -m + 1; i < m; ++i, k += 2)
            {
                y += Y[i] * k;
                y %= MODULO;
            }
            return ((x * y) % MODULO + MODULO) % MODULO;
        }
        static void Main(string[] args)
        {
            int[] values = ReadInts();
            long[] X = ReadLongs();
            long[] Y = ReadLongs();
            Console.WriteLine(Solve(values[0], values[1], X, Y));
        }
    }
}