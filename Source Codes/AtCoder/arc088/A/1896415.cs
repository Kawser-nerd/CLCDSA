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

        private static int Solve(long X, long Y)
        {
            for (int i = 0; true; ++i)
            {
                if (X > Y) { return i; }
                X *= 2;
            }
        }

        static void Main(string[] args)
        {
            long[] values = ReadLongs();
            Console.WriteLine(Solve(values[0], values[1]));
        }
    }
}