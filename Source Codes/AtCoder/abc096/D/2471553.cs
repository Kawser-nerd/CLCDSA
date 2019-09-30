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

        static IEnumerable<int> Solve(int N)
        {
            var primes = new List<int> { 2 };
            var ans = new List<int>();
            for (int i = 3; ans.Count < N; ++i)
            {
                if (primes.All(prime => i % prime != 0))
                {
                    primes.Add(i);
                    if (i % 10 == 3) { ans.Add(i); }
                }
            }
            return ans;
        }
        static void Main(string[] args)
        {
            int N = ReadInt();
            Console.WriteLine(string.Join(" ", Solve(N)));
        }
    }
}