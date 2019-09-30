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

        class Table
        {
            public readonly int s;
            public readonly int t;
            public readonly int c;
            public Table(int[] v)
            {
                s = v[0];
                t = v[1];
                c = v[2];
            }
        }
        static int Solve(int N, IEnumerable<Tuple<int, int>> tuples)
        {
            int max = 0;
            int cnt = 0;
            foreach (var tuple in tuples)
            {
                cnt += tuple.Item2;
                max = Math.Max(cnt, max);
            }
            return max;
        }
        static void Main(string[] args)
        {
            int[] v1 = ReadInts();
            int N = v1[0];
            int C = v1[1];
            var t1 = new Table[N];
            for (int i = 0; i < N; ++i)
            {
                t1[i] = new Table(ReadInts());
            }
            var t2 = t1.OrderBy(t => t.c).ThenBy(t => t.s).ToArray();
            var tuples = new List<Tuple<int, int>>();
            for (int i = 0; i < N; ++i)
            {
                if (i - 1 < 0 || t2[i - 1].t != t2[i].s || t2[i - 1].c != t2[i].c)
                {
                    tuples.Add(new Tuple<int, int>(t2[i].s, 1));
                }
                if (i + 1 >= N || t2[i + 1].s != t2[i].t || t2[i + 1].c != t2[i].c)
                {
                    tuples.Add(new Tuple<int, int>(t2[i].t, -1));
                }
            }
            Console.WriteLine(Solve(N, tuples.OrderBy(t => t.Item1).ThenByDescending(t => t.Item2)));
        }
    }
}