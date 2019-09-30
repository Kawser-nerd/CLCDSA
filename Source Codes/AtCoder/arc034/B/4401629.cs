using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _034
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            long n = ReadLong();
            List<long> res = new List<long>();
            for (long val = Max(n - 200, 1); val <= n; val++)
            {
                long digitSum = 0;
                long vv = val;
                while (vv > 0)
                {
                    digitSum += vv % 10;
                    vv /= 10;
                }
                if (val + digitSum == n) res.Add(val);
            }
            WriteLine(res.Count);
            for (int i = 0; i < res.Count; i++)
            {
                WriteLine(res[i]);
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