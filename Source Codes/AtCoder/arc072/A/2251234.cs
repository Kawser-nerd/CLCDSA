using System;
using System.Collections.Generic;
using System.Linq;

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

        static long Solve(int n, long[] A)
        {
            long sum1 = 0;
            long sum2 = 0;
            long res1 = 0;
            long res2 = 0;
            for (int i = 0; i < n; ++i)
            {
                sum1 += A[i];
                sum2 += A[i];
                if (i % 2 == 0)
                {
                    if (sum1 >= 0)
                    {
                        res1 += sum1 + 1;
                        sum1 = -1;
                    }
                    if (sum2 <= 0)
                    {
                        res2 += -sum2 + 1;
                        sum2 = 1;
                    }
                }
                else
                {
                    if (sum1 <= 0)
                    {
                        res1 += -sum1 + 1;
                        sum1 = 1;
                    }
                    if (sum2 >= 0)
                    {
                        res2 += sum2 + 1;
                        sum2 = -1;
                    }
                }
            }
            return Math.Min(res1, res2);
        }
        static void Main(string[] args)
        {
            int n = ReadInt();
            long[] A = ReadLongs();
            Console.WriteLine(Solve(n, A));
        }
    }
}