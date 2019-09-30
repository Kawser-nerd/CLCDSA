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

        static double Solve1(int A, long[] V)
        {
            return (double)V.Take(A).Sum() / A;
        }
        static long Solve2(int N, int A, int B, long[] V)
        {
            long[][] C = new long[N + 1][];
            C[0] = new long[N + 1];
            C[0][0] = 1;
            for (int i = 1; i <= N; ++i)
            {
                C[i] = new long[N + 1];
                C[i][0] = 1;
                for (int j = 1; j <= N; ++j)
                {
                    C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                }
            }
            long sum = 0;
            for (int i = A; i <= B; ++i)
            {
                if (i > A && V[0] > V[i - 1]) { break; }
                int n = V.Count(v => v == V[i - 1]);
                int r = V.Take(i).Count(v => v == V[i - 1]);
                sum += C[n][r];
            }
            return sum;
        }
        static void Main(string[] args)
        {
            int[] U = ReadInts();
            long[] V = ReadLongs().OrderByDescending(v => v).ToArray();
            Console.WriteLine(Solve1(U[1], V).ToString("F"));
            Console.WriteLine(Solve2(U[0], U[1], U[2], V));
        }
    }
}