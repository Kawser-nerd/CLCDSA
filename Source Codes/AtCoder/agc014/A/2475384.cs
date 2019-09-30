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

        static int Solve(int A, int B, int C)
        {
            var s = new Tuple<int, int, int>(A, B, C);
            var set = new HashSet<Tuple<int, int, int>>();
            int i;
            for (i = 0; true; ++i)
            {
                set.Add(s);
                int a = s.Item1;
                int b = s.Item2;
                int c = s.Item3;
                if (a % 2 != 0 || b % 2 != 0 || c % 2 != 0) { break; }
                int x = b / 2 + c / 2;
                int y = c / 2 + a / 2;
                int z = a / 2 + b / 2;
                var t = new Tuple<int, int, int>(x, y, z);
                if (set.Contains(t)) { return -1; }
                s = t;
            }
            return i;
        }
        static void Main(string[] args)
        {
            var V = ReadInts();
            Console.WriteLine(Solve(V[0], V[1], V[2]));
        }
    }
}