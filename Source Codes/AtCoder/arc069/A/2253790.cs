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

        static long Solve(long N, long M)
        {
            long n = Math.Min(N, M / 2);
            return n + (M - n * 2) / 4;
        }
        static void Main(string[] args)
        {
            long[] v1 = ReadLongs();
            Console.WriteLine(Solve(v1[0], v1[1]));
        }
    }
}