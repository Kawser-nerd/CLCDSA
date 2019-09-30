using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _008
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
            string name = Read();
            string kit = Read();
            int[] nameCnts = new int[26];
            int[] kitCnts = new int[26];
            for(int i = 0; i < n; i++)
            {
                nameCnts[name[i] - 'A']++;
            }
            for(int i = 0; i < m; i++)
            {
                kitCnts[kit[i] - 'A']++;
            }
            int res = 0;
            for(int i = 0; i < 26; i++)
            {
                if (nameCnts[i] == 0) continue;
                if (kitCnts[i] == 0)
                {
                    WriteLine(-1);
                    return;
                }
                res = Max(res, (int)Ceiling(1.0 * nameCnts[i] / kitCnts[i]));
            }
            WriteLine(res);
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