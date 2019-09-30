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

        class Sushi
        {
            public readonly long x;
            public readonly long v;
            public Sushi(long[] V)
            {
                x = V[0];
                v = V[1];
            }
        }
        static long Solve(int N, long C, Sushi[] sushis)
        {
            long[][] memo = new long[N][];
            for (int i = 0; i < N; ++i) { memo[i] = new long[2]; }
            long max = 0;
            {
                long max1 = 0;
                long max2 = 0;
                long sum1 = 0;
                long sum2 = 0;
                for (int i = 0; i < N; ++i)
                {
                    int j = N - 1 - i;
                    sum1 += sushis[i].v;
                    max1 = Math.Max(sum1 - sushis[i].x, max1);
                    memo[i][0] = max1;
                    sum2 += sushis[j].v;
                    max2 = Math.Max(sum2 - (C - sushis[j].x), max2);
                    memo[j][1] = max2;
                    max = Math.Max(max1, max);
                    max = Math.Max(max2, max);
                }
            }
            {
                long sum1 = 0;
                long sum2 = 0;
                for (int i = 0; i < N; ++i)
                {
                    int j = N - 1 - i;
                    sum1 += sushis[i].v;
                    if (i + 1 < N)
                    {
                        max = Math.Max(sum1 - sushis[i].x * 2 + memo[i + 1][1], max);
                    }
                    sum2 += sushis[j].v;
                    if (j - 1 >= 0)
                    {
                        max = Math.Max(sum2 - (C - sushis[j].x) * 2 + memo[j - 1][0], max);
                    }
                }
            }
            return max;
        }
        static void Main(string[] args)
        {
            var V = ReadLongs();
            int N = (int)V[0];
            var sushis = new Sushi[N];
            for (int i = 0; i < N; ++i) { sushis[i] = new Sushi(ReadLongs()); }
            Console.WriteLine(Solve(N, V[1], sushis));
        }
    }
}