using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

namespace AtCoder
{
    class Program
    {
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        static private long Solve(int N, int K)
        {
            if (K == 0)
            {
                return Math.BigMul(N, N);
            }
            else
            {
                long sum = 0;
                for (int i = 1; K + i <= N; ++i)
                {
                    int b = K + i;
                    sum += (N / b) * i;
                    sum += Math.Max(N % b - K + 1, 0);
                }
                return sum;
            }
        }
        static void Main(string[] args)
        {
            int[] values = ReadInts();
            Console.WriteLine(Solve(values[0], values[1]));
        }
    }
}