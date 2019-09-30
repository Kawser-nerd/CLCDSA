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

        static int Cost(int[] A, int n)
        {
            return A.Sum(a => (n - a) * (n - a));
        }
        static int Solve(int[] A)
        {
            int min = int.MaxValue;
            for (int i = -100; i <= 100; ++i) { min = Math.Min(Cost(A, i), min); }
            return min;
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            int[] A = ReadInts();
            Console.WriteLine(Solve(A));
        }
    }
}