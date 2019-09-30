using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.AGC_Challenge
{
    class _014_B
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nm = ReadInts();
            int n = nm[0];
            int m = nm[1];
            int[] cnts = new int[n];
            for(int i = 0; i < m; i++)
            {
                int[] ab = ReadInts();
                cnts[ab[0] - 1]++;
                cnts[ab[1] - 1]++;
            };
            for(int i = 0; i < n; i++)
            {
                if (cnts[i] % 2 > 0)
                {
                    WriteLine("NO");
                    return;
                }
            }
            WriteLine("YES");
        }

        private static string Read() { return ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}