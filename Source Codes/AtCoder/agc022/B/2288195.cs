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

        static IEnumerable<int> Make(int s, int N)
        {
            int sum = 0;
            var list = new List<int>();
            for (int i = s; i <= 30000 && list.Count < N; ++i)
            {
                if (i % 2 == 0 || i % 3 == 0)
                {
                    if (list.Count < N - 1 || (sum + i) % 6 == 0)
                    {
                        list.Add(i);
                        sum += i;
                    }
                }
            }
            return (list.Count == N) ? list : null;
        }
        static IEnumerable<int> Solve(int N)
        {
            if (N == 3)
            {
                return new[] { 2, 5, 63 };
            }
            else
            {
                return Make(2, N) ?? Make(3, N) ?? Make(4, N);
            }
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            Console.WriteLine(string.Join(" ", Solve(N)));
        }
    }
}