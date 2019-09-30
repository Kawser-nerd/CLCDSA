using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _004
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] ds = new int[n];
            for(int i = 0; i < n; i++)
            {
                ds[i] = ReadInt();
            }

            Array.Sort(ds);
            int sum = 0;
            for(int i = 0; i < n - 1; i++)
            {
                sum += ds[i];
            }
            WriteLine(sum + ds[n - 1]);
            WriteLine(ds[n - 1] - sum <= 0 ? 0 : ds[n - 1] - sum);
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