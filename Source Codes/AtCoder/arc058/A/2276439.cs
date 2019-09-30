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

        static IEnumerable<int> Decompose(int n)
        {
            var list = new List<int>();
            while (n > 0)
            {
                list.Add(n % 10);
                n /= 10;
            }
            return list;
        }
        static int Solve(int N, int[] D)
        {
            for (int i = N; true; ++i)
            {
                if (Decompose(i).All(n => !D.Contains(n))) { return i; }
            }
        }
        static void Main(string[] args)
        {
            int[] v = ReadInts();
            int[] D = ReadInts();
            Console.WriteLine(Solve(v[0], D));
        }
    }
}