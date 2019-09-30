using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _013
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int c = ReadInt();
            int[] mins = new int[c];
            int[] mids = new int[c];
            int[] maxs = new int[c];
            for(int i = 0; i < c; i++)
            {
                int[] nml = ReadInts();
                Array.Sort(nml);
                mins[i] = nml[0];
                mids[i] = nml[1];
                maxs[i] = nml[2];
            }
            Array.Sort(mins);
            Array.Sort(mids);
            Array.Sort(maxs);
            WriteLine(mins[c - 1] * mids[c - 1] * maxs[c - 1]);
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