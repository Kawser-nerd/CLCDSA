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

        static long Solve(int N, int A, int B)
        {
            return Math.Max((Math.BigMul(B, N - 1) + A) - (Math.BigMul(A, N - 1) + B) + 1, 0);
        }
        static void Main(string[] args)
        {
            var V = ReadInts();
            Console.WriteLine(Solve(V[0], V[1], V[2]));
        }
    }
}