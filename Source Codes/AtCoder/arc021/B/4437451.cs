using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _021
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int l = ReadInt();
            int[] bs = new int[l];
            for (int i = 0; i < l; i++) bs[i] = ReadInt();
            int[] res = new int[l];
            for (int i = 1; i < l; i++)
            {
                res[i] = bs[i - 1] ^ res[i - 1];
            }
            if ((res[0] ^ res[l - 1]) == bs[l - 1])
            {
                for (int i = 0; i < l; i++) WriteLine(res[i]);
            }
            else
            {
                WriteLine(-1);
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