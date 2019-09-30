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

        static Tuple<int, int> Solve(string s)
        {
            int N = s.Length;
            for (int i = 0; i + 1 < N; ++i)
            {
                if (s[i] == s[i + 1]) { return new Tuple<int, int>(i + 1, i + 2); }
            }
            for (int i = 0; i + 2 < N; ++i)
            {
                if (s[i] == s[i + 2]) { return new Tuple<int, int>(i + 1, i + 3); }
            }
            return new Tuple<int, int>(-1, -1);
        }
        static void Main(string[] args)
        {
            string s = Read();
            var ans = Solve(s);
            Console.WriteLine("{0} {1}", ans.Item1, ans.Item2);
        }
    }
}