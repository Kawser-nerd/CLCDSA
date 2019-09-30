using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;
using System.Threading.Tasks;

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

        private static int Solve(int N, int W, int[] A)
        {
            int x = Math.Abs(A[N - 1] - W);
            int y = (N == 1) ? 0 : Math.Abs(A[N - 1] - A[N - 2]);
            return Math.Max(x, y);
        }
        static void Main(string[] args)
        {
            int[] values = ReadInts();
            int[] A = ReadInts();
            Console.WriteLine(Solve(values[0], values[2], A));
        }
    }
}