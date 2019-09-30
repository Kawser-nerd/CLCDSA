using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_B
{
    class _047
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] xs = new int[n];
            int[] ys = new int[n];
            for (int i = 0; i < n; i++)
            {
                int[] xy = ReadInts();
                xs[i] = xy[0] + xy[1];
                ys[i] = xy[0] - xy[1];
            }
            Array.Sort(xs);
            Array.Sort(ys);
            int length = Math.Max(xs[n - 1] - xs[0], ys[n - 1] - ys[0]) / 2;

            int plus, minus;
            if (n == 1)
            {
                plus = xs[0];
                minus = ys[0];
            }
            else
            {
                if (xs[n - 1] == xs[n - 2])
                {
                    plus = xs[n - 1] - length;
                }
                else
                {
                    plus = xs[0] + length;
                }
                if (ys[n - 1] == ys[n - 2])
                {
                    minus = ys[n - 1] - length;
                }
                else
                {
                    minus = ys[0] + length;
                }
            }
            //Console.WriteLine(plus + " " + minus);
            Console.WriteLine((plus + minus) / 2 + " " + (plus - minus) / 2);
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}