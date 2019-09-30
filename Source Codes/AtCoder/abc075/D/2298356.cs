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

        class Point
        {
            public readonly long x;
            public readonly long y;
            public Point(long[] v)
            {
                x = v[0];
                y = v[1];
            }
        }
        static long Solve(int N, int K, Point[] points)
        {
            var set1 = new HashSet<long>();
            var set2 = new HashSet<long>();
            foreach (var point in points)
            {
                set1.Add(point.x);
                set2.Add(point.y);
            }
            long min = long.MaxValue;
            var X = set1.OrderBy(x => x).ToArray();
            var Y = set2.OrderBy(y => y).ToArray();
            for (int i = 0; i < X.Length; ++i)
            {
                long x1 = X[i];
                for (int j = i + 1; j < X.Length; ++j)
                {
                    long x2 = X[j];
                    for (int k = 0; k < Y.Length; ++k)
                    {
                        long y1 = Y[k];
                        for (int l = k + 1; l < Y.Length; ++l)
                        {
                            long y2 = Y[l];
                            int count = 0;
                            foreach (var p in points)
                            {
                                if (x1 <= p.x && p.x <= x2 && y1 <= p.y && p.y <= y2)
                                {
                                    if (++count > K) { break; }
                                }
                            }
                            if (count == K) { min = Math.Min((x2 - x1) * (y2 - y1), min); }
                        }
                    }
                }
            }
            return min;
        }
        static void Main(string[] args)
        {
            int[] v = ReadInts();
            int N = v[0];
            int K = v[1];
            var points = new Point[N];
            for (int i = 0; i < N; ++i) { points[i] = new Point(ReadLongs()); }
            Console.WriteLine(Solve(N, K, points));
        }
    }
}