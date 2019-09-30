using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

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

        static int S(long n)
        {
            int sum = 0;
            while (n > 0)
            {
                sum += (int)(n % 10);
                n /= 10;
            }
            return sum;
        }
        static long Next(long n)
        {
            long n1 = n;
            int d1 = S(n);
            for (long i = 10; i <= n; i *= 10)
            {
                long n2 = n - (n % i) + (i - 1);
                int d2 = S(n2);
                if (n2 * d1 < n1 * d2)
                {
                    n1 = n2;
                    d1 = d2;
                }
            }
            return n1;
        }
        static IEnumerable<long> Solve(int K)
        {
            var list = new List<long>();
            long n = 0;
            for (int i = 0; i < K; ++i)
            {
                n = Next(n + 1);
                list.Add(n);
            }
            return list;
        }
        static void Main(string[] args)
        {
            int K = ReadInt();
            foreach (var ans in Solve(K))
            {
                Console.WriteLine(ans);
            }
        }
    }
}