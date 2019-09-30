using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

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

        static long Cost(int N, int X, int[] x, int n)
        {
            long cost = 0;
            for (int i = 0; i < n; ++i)
            {
                cost += x[i];
                for (int j = 0; true; ++j)
                {
                    if ((j + 1) * n + i < N)
                    {
                        cost += Math.BigMul(j + 2, j + 2) * (x[j * n + i] - x[(j + 1) * n + i]);
                    }
                    else
                    {
                        cost += Math.BigMul(j + 2, j + 2) * x[j * n + i];
                        break;
                    }
                }
            }
            return cost + Math.BigMul(N + n, X);
        }
        static long Solve(int N, int X, int[] x)
        {
            Array.Sort(x, (a, b) => b.CompareTo(a));
            int x0 = 1;
            int x3 = N;
            long y0 = Cost(N, X, x, x0);
            long y1;
            long y2;
            long y3 = Cost(N, X, x, x3);
            while (true)
            {
                int x1 = (x3 - x0) * 1 / 3 + x0;
                int x2 = (x3 - x0) * 2 / 3 + x0;
                y1 = Cost(N, X, x, x1);
                y2 = Cost(N, X, x, x2);
                if (x3 - x0 <= 3) { break; }
                if (y1 < y2)
                {
                    x3 = x2;
                    y3 = y2;
                }
                else
                {
                    x0 = x1;
                    y0 = y1;
                }
            }
            return new[] { y0, y1, y2, y3 }.Min();
        }
        static void Main(string[] args)
        {
            int[] V1 = ReadInts();
            int[] x = ReadInts();
            Console.WriteLine(Solve(V1[0], V1[1], x));
        }
    }
}