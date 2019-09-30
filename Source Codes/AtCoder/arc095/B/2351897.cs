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

        static IEnumerable<long> Solve(int N, long[] A)
        {
            Array.Sort(A);
            if (N == 2)
            {
                return new[] { A[1], A[0] };
            }
            else
            {
                long n = A.Last();
                Array.Sort(A, (a, b) => Math.Abs(n - a * 2).CompareTo(Math.Abs(n - b * 2)));
                long r = A.First();
                return new[] { n, r };
            }
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            long[] A = ReadLongs();
            Console.WriteLine(string.Join(" ", Solve(N, A)));
        }
    }
}