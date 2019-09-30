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

        static int Solve(int N, int[] S)
        {
            var T = S.Where(s => s % 10 != 0);
            int sum = S.Sum();
            return (sum % 10 != 0) ? sum
                 : (T.Count() > 0) ? sum - T.Min()
                                   : 0;
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            int[] S = new int[N];
            for (int i = 0; i < N; ++i) { S[i] = ReadInt(); }
            Console.WriteLine(Solve(N, S));
        }
    }
}