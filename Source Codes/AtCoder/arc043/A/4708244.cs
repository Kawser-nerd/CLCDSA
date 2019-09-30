using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_A
{
    class _043
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nab = ReadInts();
            int n = nab[0];
            int a = nab[1];
            int b = nab[2];
            int[] ss = new int[n];
            long sum = 0;
            for(int i = 0; i < n; i++)
            {
                ss[i] = ReadInt();
                sum += ss[i];
            }
            Array.Sort(ss);
            if (ss[n - 1] == ss[0])
            {
                WriteLine(-1);
                return;
            }
            double p = 1.0 * b / (ss[n - 1] - ss[0]);
            double q = a - p * sum / n;
            WriteLine(p + " " + q);
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