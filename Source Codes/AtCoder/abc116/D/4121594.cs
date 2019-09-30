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

        struct Sushi
        {
            public readonly int t;
            public readonly long d;

            public Sushi(long[] V)
            {
                t = (int)V[0];
                d = V[1];
            }
        }

        static long Solve(int N, int K, Sushi[] sushis)
        {
            long sum = 0;
            var dic = new Dictionary<int, int>();
            Array.Sort(sushis, (a, b) => b.d.CompareTo(a.d));
            for (int i = 0; i < K; ++i)
            {
                if (!dic.ContainsKey(sushis[i].t)) { dic[sushis[i].t] = 0; }
                ++dic[sushis[i].t];
                sum += sushis[i].d;
            }
            long max = sum + Math.BigMul(dic.Count, dic.Count);
            int p = K - 1, q = K;
            while (true)
            {
                while (p >= 0 && dic[sushis[p].t] < 2) { --p; }
                if (p < 0) { break; }
                sum -= sushis[p].d;
                --dic[sushis[p].t];
                --p;

                while (q < N && dic.ContainsKey(sushis[q].t)) { ++q; }
                if (q >= N) { break; }
                sum += sushis[q].d;
                dic[sushis[q].t] = 1;
                ++q;

                max = Math.Max(sum + Math.BigMul(dic.Count, dic.Count), max);
            }
            return max;
        }

        static void Main(string[] args)
        {
            int[] V = ReadInts();
            int N = V[0], K = V[1];
            var sushis = new Sushi[N];
            for (int i = 0; i < N; ++i) { sushis[i] = new Sushi(ReadLongs()); }
            Console.WriteLine(Solve(N, K, sushis));
        }
    }
}