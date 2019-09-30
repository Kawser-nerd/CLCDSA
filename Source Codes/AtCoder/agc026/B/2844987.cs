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

        static long Gcd(long a, long b)
        {
            return (a < b) ? Gcd(b, a)
                 : (b > 0) ? Gcd(b, a % b)
                           : a;
        }
        static bool Solve(long A, long B, long C, long D)
        {
            if (A < B) { return false; }
            if (D < B) { return false; }
            if (C >= B - 1) { return true; }
            if (B == 1) { return true; }
            long gcd = Gcd(B, D % B);
            long a = A % B;
            long b = (B - a - 1) / gcd;
            long c = a + b * gcd;
            return c <= C;
        }
        static void Main(string[] args)
        {
            int T = ReadInt();
            long[][] V = new long[T][];
            for (int i = 0; i < T; ++i) { V[i] = ReadLongs(); }
            foreach (var v in V) { Console.WriteLine(Solve(v[0], v[1], v[2], v[3]) ? "Yes" : "No"); }
        }
    }
}