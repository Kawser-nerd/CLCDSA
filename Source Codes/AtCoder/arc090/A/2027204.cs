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

        private static int Solve(int N, int[][] A)
        {
            int max = 0;
            for (int i = 0; i < N; ++i)
            {
                max = Math.Max(A[0].Take(i + 1).Sum() + A[1].Skip(i).Sum(), max);
            }
            return max;
        }

        static void Main(string[] args)
        {
            int N = ReadInt();
            int[][] A = new int[2][];
            for (int i = 0; i < 2; ++i) { A[i] = ReadInts(); }
            Console.WriteLine(Solve(N, A));
        }
    }
}