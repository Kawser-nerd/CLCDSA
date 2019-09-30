using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.AGC_032
{
    class B
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var groups = new List<List<int>>();
            int val;
            if (n % 2 == 0)
            {
                val = n + 1;
                WriteLine(n * (n - 2) / 2);
            }
            else
            {
                val = n;
                WriteLine((n - 1) * (n - 1) / 2);
            }
            for(int i = 1; i <= n; i++)
            {
                for(int j = i + 1; j <= n; j++)
                {
                    if (i + j == val) continue;

                    WriteLine(i + " " + j);
                }
            }
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