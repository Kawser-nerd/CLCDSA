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

        static long Solve(string s)
        {
            int N = s.Length;
            long sum = 0;
            for (int i = 0; i < N; ++i)
            {
                int j = N - i - 1;
                switch (s[i])
                {
                case 'U': sum += i * 2 + j * 1; break;
                case 'D': sum += i * 1 + j * 2; break;
                }
            }
            return sum;
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Solve(Read()));
        }
    }
}