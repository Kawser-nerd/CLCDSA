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

        static IEnumerable<int> Count(IEnumerable<char> S)
        {
            int N = S.Count();
            var counts = new int[N];
            for (int i = 0; i < N; ++i)
            {
                int prev = (i == 0) ? 0 : counts[i - 1];
                switch (S.ElementAt(i))
                {
                case '(': counts[i] = prev + 1; break;
                case ')': counts[i] = prev - 1; break;
                }
            }
            return counts;
        }
        static string Solve(string S)
        {
            int min = Math.Min(Count(S).Min(), 0);
            int max = Math.Max(Count(S.Reverse()).Max(), 0);
            return new string('(', -min) + S + new string(')', max);
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            string S = Read();
            Console.WriteLine(Solve(S));
        }
    }
}