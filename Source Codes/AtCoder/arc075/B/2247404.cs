using System;
using System.Collections.Generic;
using System.Linq;

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

        static long Div(long a, long b)
        {
            return (a + b - 1) / b;
        }
        static bool CanBeat(int N, long A, long B, int[] H, long bombs)
        {
            long rest = bombs;
            foreach (int h in H)
            {
                long n = Div(h - B * bombs, A - B);
                if (n == 0) { return true; }
                if (n > rest) { return false; }
                rest -= n;
            }
            return true;
        }
        static int Solve(int N, long A, long B, int[] H)
        {
            Array.Sort(H, (a, b) => b - a);
            long min = 0;
            long max = Div(H[0], B);
            while (max - min > 1)
            {
                long med = (min + max) / 2;
                if (CanBeat(N, A, B, H, med))
                {
                    max = med;
                }
                else
                {
                    min = med;
                }
            }
            return (int)max;
        }
        static void Main(string[] args)
        {
            long[] values1 = ReadLongs();
            int N = (int)values1[0];
            int[] H = new int[N];
            for (int i = 0; i < N; ++i) { H[i] = ReadInt(); }
            Console.WriteLine(Solve(N, values1[1], values1[2], H));
        }
    }
}