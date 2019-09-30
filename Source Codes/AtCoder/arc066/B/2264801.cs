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

        class Solver
        {
            private Dictionary<Tuple<long, long>, long> m_dict = new Dictionary<Tuple<long, long>, long>();
            public long Solve(long S, long X)
            {
                if (S == 0) { return 1; }
                if (X == 0) { return (S / 2) + 1; }
                if (S == 1) { return 2; }
                var key = new Tuple<long, long>(S, X);
                if (!m_dict.ContainsKey(key))
                {
                    long sum = 0;
                    sum = (sum + Solve((S - 0) / 2, (X - 0) / 2)) % MODULO;
                    sum = (sum + Solve((S - 1) / 2, (X - 1) / 2)) % MODULO;
                    sum = (sum + Solve((S - 2) / 2, (X - 0) / 2)) % MODULO;
                    m_dict[key] = sum;
                }
                return m_dict[key];
            }
        }

        static void Main(string[] args)
        {
            long N = ReadLong();
            Console.WriteLine(new Solver().Solve(N, N));
        }
    }
}