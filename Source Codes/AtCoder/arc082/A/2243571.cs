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

        static int Solve(int[] A)
        {
            int[] counts = new int[100002];
            foreach (int a in A)
            {
                ++counts[a + 0];
                ++counts[a + 1];
                ++counts[a + 2];
            }
            return counts.Max();
        }

        static void Main(string[] args)
        {
            int N = ReadInt();
            Console.WriteLine(Solve(ReadInts()));
        }
    }
}