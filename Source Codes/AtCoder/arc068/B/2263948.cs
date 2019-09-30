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

        static int Solve(int N, int[] A)
        {
            var dict = new Dictionary<int, int>();
            foreach (int a in A)
            {
                if (!dict.ContainsKey(a)) { dict[a] = 0; }
                ++dict[a];
            }
            var values = dict.Values;
            int count = values.Count(value => value % 2 == 0);
            return (count % 2 == 0) ? values.Count : values.Count - 1;
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            int[] A = ReadInts();
            Console.WriteLine(Solve(N, A));
        }
    }
}