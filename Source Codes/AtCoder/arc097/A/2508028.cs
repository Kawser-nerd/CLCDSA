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

        static string Solve(string s, int K)
        {
            int N = s.Length;
            var set = new HashSet<string>();
            for (int i = 0; i < N; ++i)
            {
                for (int j = 1; j <= K && i + j <= N; ++j)
                {
                    set.Add(s.Substring(i, j));
                }
            }
            return set.OrderBy(t => t).ElementAt(K - 1);
        }
        static void Main(string[] args)
        {
            var s = Read();
            var K = ReadInt();
            Console.WriteLine(Solve(s, K));
        }
    }
}