using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

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

        private static long Solve(int N, long[] A)
        {
            var dict = new Dictionary<long, int>();
            foreach (long a in A)
            {
                if (!dict.ContainsKey(a)) { dict[a] = 0; }
                ++dict[a];
            }
            var X = dict.Where(pair => pair.Value >= 2).OrderByDescending(pair => pair.Key);
            if (X.Count() == 0) { return 0; }
            var x = X.First();
            dict[x.Key] -= 2;
            var Y = dict.Where(pair => pair.Value >= 2).OrderByDescending(pair => pair.Key);
            if (Y.Count() == 0) { return 0; }
            var y = Y.First();
            return x.Key * y.Key;
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            long[] A = ReadLongs();
            Console.WriteLine(Solve(N, A));
        }
    }
}