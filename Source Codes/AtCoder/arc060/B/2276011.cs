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

        static long Func(long b, long n)
        {
            return (n < b) ? n : Func(b, n / b) + n % b;
        }
        static long Solve(long n, long s)
        {
            if (s > n) { return -1; }
            if (s == n) { return n + 1; }
            long b;
            for (b = 2; b * b <= n; ++b)
            {
                if (Func(b, n) == s) { return b; }
            }
            long min = long.MaxValue;
            for (int i = 1; i <= b; ++i)
            {
                if ((n - s) % i == 0)
                {
                    long a = (n - s) / i + 1;
                    if (Func(a, n) == s) { min = Math.Min(a, min); }
                }
            }
            return (min < long.MaxValue) ? min : -1;
        }
        static void Main(string[] args)
        {
            long n = ReadLong();
            long s = ReadLong();
            Console.WriteLine(Solve(n, s));
        }
    }
}