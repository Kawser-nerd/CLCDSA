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

        static IEnumerable<int> Solve(int N, int[] X)
        {
            var Y = X.OrderBy(x => x);
            int a = Y.ElementAt(N / 2 - 1);
            int b = Y.ElementAt(N / 2);
            return X.Select(x => (x < b) ? b : a);
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            int[] X = ReadInts();
            foreach (int ans in Solve(N, X))
            {
                Console.WriteLine(ans);
            }
        }
    }
}