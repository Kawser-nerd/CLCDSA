using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_A
{
    class _042
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
            int[] array = new int[m];
            for(int i = m - 1; i >= 0; i--)
            {
                int val = ReadInt();
                array[i] = val;
            }
            var dict = new Dictionary<int, bool>();
            for(int i = 0; i < m; i++)
            {
                if (dict.ContainsKey(array[i])) continue;

                WriteLine(array[i]);
                dict.Add(array[i], true);
            }

            for(int i = 1; i <= n; i++)
            {
                if (dict.ContainsKey(i)) continue;

                WriteLine(i);
                dict.Add(i, true);
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