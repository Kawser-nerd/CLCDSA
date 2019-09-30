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

        static IEnumerable<string> Solve(int A, int B)
        {
            char[][] rows = new char[100][];
            for (int i =  0; i <  50; ++i) { rows[i] = Enumerable.Repeat('#', 100).ToArray(); }
            for (int i = 50; i < 100; ++i) { rows[i] = Enumerable.Repeat('.', 100).ToArray(); }
            for (int i = 0; i < A - 1; ++i)
            {
                int x = (i % 50) * 2;
                int y = (i / 50) * 2;
                rows[y][x] = '.';
            }
            for (int i = 0; i < B - 1; ++i)
            {
                int x = (i % 50) * 2;
                int y = (i / 50) * 2;
                rows[99 - y][x] = '#';
            }
            return Array.ConvertAll(rows, row => new string(row));
        }
        static void Main(string[] args)
        {
            int[] v = ReadInts();
            Console.WriteLine("100 100");
            foreach (string s in Solve(v[0], v[1])) { Console.WriteLine(s); }
        }
    }
}