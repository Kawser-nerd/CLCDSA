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

        static int Solve(long a, long b)
        {
            if (0 < a) { return 1; }
            else if (0 <= b) { return 0; }
            else { return (((a + b) & 1) == 0) ? -1 : 1; }
        }
        static void Main(string[] args)
        {
            var V = ReadLongs();
            string s = "";
            switch (Solve(V[0], V[1]))
            {
            case -1: s = "Negative"; break;
            case 0: s = "Zero"; break;
            case 1: s = "Positive"; break;
            }
            Console.WriteLine(s);
        }
    }
}