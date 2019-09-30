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

        static long Solve(long Q, long H, long S, long D, int N)
        {
            long s = new[] { Q * 4, H * 2, S * 1 }.Min();
            long d = new[] { s * 2, D * 1 }.Min();
            return N / 2 * d + N % 2 * s;
        }
        static void Main(string[] args)
        {
            var V = ReadLongs();
            int N = ReadInt();
            Console.WriteLine(Solve(V[0], V[1], V[2], V[3], N));
        }
    }
}