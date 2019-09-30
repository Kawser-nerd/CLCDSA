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

        static long Calculate(long a, long b, long c)
        {
            var s = new[] { a, b, c };
            long min = s.Min();
            long max = s.Max();
            return (min > 0) ? max - min : long.MaxValue;
        }
        static long Solve(long H, long W)
        {
            long min = long.MaxValue;
            long h1 = (H + 0) / 3;
            long h2 = (H + 1) / 3;
            long h3 = (H + 2) / 3;
            long ha = (H + 0) / 2;
            long hb = (H + 1) / 2;
            long w1 = (W + 0) / 3;
            long w2 = (W + 1) / 3;
            long w3 = (W + 2) / 3;
            long wa = (W + 0) / 2;
            long wb = (W + 1) / 2;
            min = Math.Min(Calculate(h1 * W, h2 * W, h3 * W), min);
            min = Math.Min(Calculate(w1 * H, w2 * H, w3 * H), min);
            min = Math.Min(Calculate(h1 * W, (H - h1) * wa, (H - h1) * wb), min);
            min = Math.Min(Calculate(h3 * W, (H - h3) * wa, (H - h3) * wb), min);
            min = Math.Min(Calculate(w1 * H, (W - w1) * ha, (W - w1) * hb), min);
            min = Math.Min(Calculate(w3 * H, (W - w3) * ha, (W - w3) * hb), min);
            return min;
        }
        static void Main(string[] args)
        {
            long[] values = ReadLongs();
            Console.WriteLine(Solve(values[0], values[1]));
        }
    }
}