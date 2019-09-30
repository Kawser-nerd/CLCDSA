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

        static long Solve(string A)
        {
            var memo = new long[26];
            foreach (char a in A) { ++memo[a - 'a']; }
            int len = A.Length;
            long sum = 1;
            foreach (char a in A)
            {
                --len;
                --memo[a - 'a'];
                sum += len - memo[a - 'a'];
            }
            return sum;
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Solve(Read()));
        }
    }
}