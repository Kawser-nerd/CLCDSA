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

        struct Set
        {
            public int val;
            public int pos;
            public int rank;
        }
        static int Solve(int N, int[] P)
        {
            var set1 = new Set[N];
            for (int i = 0; i < N; ++i)
            {
                set1[i].val = P[i];
                set1[i].pos = i;
            }
            var set2 = set1.OrderBy(set => set.val).ThenBy(set => set.pos).ToArray();
            for (int i = 0; i < N; ++i)
            {
                set2[i].rank = i;
            }
            var set3 = set2.OrderByDescending(set => set.rank).ToArray();
            int cnt = 1;
            int max = 1;
            for (int i = 1; i < N; ++i)
            {
                if (set3[i].pos < set3[i - 1].pos)
                {
                    max = Math.Max(++cnt, max);
                }
                else
                {
                    cnt = 1;
                }
            }
            return N - max;
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            int[] P = new int[N];
            for (int i = 0; i < N; ++i) { P[i] = ReadInt(); }
            Console.WriteLine(Solve(N, P));
        }
    }
}