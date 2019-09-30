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
            Array.Sort(A, (a, b) => b - a);
            long sum = 0;
            for (int i = 0; i < N; ++i) { sum += A[i * 2 + 1]; }
            return sum;
        }
        static void Main(string[] args)
        {
            var N = ReadInt();
            var A = ReadInts();
            Console.WriteLine(Solve(N, A));
        }
    }
}