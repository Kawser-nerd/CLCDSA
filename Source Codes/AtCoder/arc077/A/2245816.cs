using System;
using System.Collections.Generic;
using System.Linq;

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

        static IEnumerable<int> Solve(int n, int[] a)
        {
            int[] b = new int[n];
            for (int i = 0; i < n; ++i)
            {
                int j = (i % 2 == 0) ? i / 2 : n - 1 - i / 2;
                b[j] = a[n - 1 - i];
            }
            return b;
        }
        static void Main(string[] args)
        {
            int n = ReadInt();
            int[] a = ReadInts();
            Console.WriteLine(string.Join(" ", Solve(n, a)));
        }
    }
}