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

        static IEnumerable<int> Solve(int N, int[] A)
        {
            int cost = 0;
            int[] B = new int[N + 1];
            Array.Copy(A, 0, B, 1, N);
            for (int i = 0; i <= N; ++i) { cost += Math.Abs(B[(i + 1) % (N + 1)] - B[i]); }
            int[] costs = new int[N];
            for (int i = 0; i < N; ++i)
            {
                int i0 = i;
                int i1 = (i + 1) % (N + 1);
                int i2 = (i + 2) % (N + 1);
                costs[i0] = cost
                          - Math.Abs(B[i2] - B[i1])
                          - Math.Abs(B[i1] - B[i0])
                          + Math.Abs(B[i2] - B[i0]);
            }
            return costs;
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            int[] A = ReadInts();
            foreach (int cost in Solve(N, A))
            {
                Console.WriteLine(cost);
            }
        }
    }
}