using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.AGC_Challenge
{
    class _022_B
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] res = new int[n];
            res[0] = 2;
            res[1] = 3;
            res[2] = 25;
            int i = 3;
            if (n % 2 == 0)
            {
                res[i] = 30;
                i++;
            }
            int now = 32;
            for (; i < n; i += 2)
            {
                while ((now % 2 > 0) && (now % 3 > 0) && (now % 5 > 0)) now++;
                res[i] = now;
                res[i + 1] = 30000 - now;
                now++;
            }
            for(int j = 0; j < n; j++)
            {
                WriteLine(res[j]);
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