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

        class Item
        {
            public readonly int a;
            public readonly int b;
            public readonly int c;
            public Item(int[] V)
            {
                a = V[0];
                b = V[1];
                c = V[2];
            }
        }
        static int Solve(int N, int Ma, int Mb, Item[] items)
        {
            const int INF = 1 << 15;
            int[][][] dp = new int[N][][];
            for (int i = 0; i < N; ++i)
            {
                dp[i] = new int[401][];
                for (int a = 0; a <= 400; ++a)
                {
                    dp[i][a] = Enumerable.Repeat(INF, 401).ToArray();
                }
            }
            dp[0][0][0] = 0;
            dp[0][items[0].a][items[0].b] = items[0].c;
            for (int i = 1; i < N; ++i)
            {
                for (int a = 0; a <= 400; ++a)
                {
                    for (int b = 0; b <= 400; ++b)
                    {
                        int c = (a >= items[i].a && b >= items[i].b) ? dp[i - 1][a - items[i].a][b - items[i].b] : INF;
                        dp[i][a][b] = Math.Min(dp[i - 1][a][b], c + items[i].c);
                    }
                }
            }
            int min = INF;
            for (int a = 1; a <= 400; ++a)
            {
                for (int b = 1; b <= 400; ++b)
                {
                    if (a * Mb == Ma * b)
                    {
                        min = Math.Min(dp[N - 1][a][b], min);
                    }
                }
            }
            return (min < INF) ? min : -1;
        }
        static void Main(string[] args)
        {
            int[] V = ReadInts();
            int N = V[0];
            var items = new Item[N];
            for (int i = 0; i < N; ++i) { items[i] = new Item(ReadInts()); }
            Console.WriteLine(Solve(N, V[1], V[2], items));
        }
    }
}