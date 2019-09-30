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

        static bool Solve(int N, int A, int B, int C, int D)
        {
            for (int i = 0; i < N - 1; ++i)
            {
                int j = N - 1 - i;
                long p1 = Math.BigMul(C, i);
                long p2 = Math.BigMul(D, i);
                long n1 = Math.BigMul(-D, j);
                long n2 = Math.BigMul(-C, j);
                if (A + p1 + n1 <= B && B <= A + p2 + n2) { return true; }
            }
            return false;
        }
        static void Main(string[] args)
        {
            var V = ReadInts();
            Console.WriteLine(Solve(V[0], V[1], V[2], V[3], V[4]) ? "YES" : "NO");
        }
    }
}