using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

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

        static int Solve(int N, int C, int[][] D, int[][] c)
        {
            var memo = new int[3][];
            for (int i = 0; i < 3; ++i) { memo[i] = new int[C]; }
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    int p = (i + j) % 3;
                    int c1 = c[i][j] - 1;
                    for (int c2 = 0; c2 < C; ++c2)
                    {
                        memo[p][c2] += D[c1][c2];
                    }
                }
            }
            int min = int.MaxValue;
            for (int i = 0; i < C; ++i)
            {
                for (int j = 0; j < C; ++j)
                {
                    if (j == i) { continue; }
                    for (int k = 0; k < C; ++k)
                    {
                        if (k == i || k == j) { continue; }
                        min = Math.Min(memo[0][i] + memo[1][j] + memo[2][k], min);
                    }
                }
            }
            return min;
        }
        static void Main(string[] args)
        {
            int[] V = ReadInts();
            int N = V[0];
            int C = V[1];
            var D = new int[C][];
            for (int i = 0; i < C; ++i) { D[i] = ReadInts(); }
            var c = new int[N][];
            for (int i = 0; i < N; ++i) { c[i] = ReadInts(); }
            Console.WriteLine(Solve(N, C, D, c));
        }
    }
}