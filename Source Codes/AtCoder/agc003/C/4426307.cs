using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.AGC_C
{
    class _003
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[][] array = new int[n][];
            for(int i = 0; i < n; i++)
            {
                array[i] = new int[2] { ReadInt(), i };
            }
            Array.Sort(array, (a, b) => a[0] - b[0]);
            int cnt = 0;
            for(int i = 0; i < n; i += 2)
            {
                if (array[i][1] % 2 == 1) cnt++;
            }
            WriteLine(cnt);
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