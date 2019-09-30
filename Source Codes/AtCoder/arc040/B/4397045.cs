using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _040
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nr = ReadInts();
            int n = nr[0];
            int r = nr[1];
            bool[] colored = new bool[n];
            string s = Read();
            for (int i = 0; i < n; i++)
            {
                colored[i] = s[i] == 'o';
            }
            int res = 0;
            int now = n - 1;
            bool shot = false;
            for (; now >= 0;)
            {
                if (colored[now]) now--;
                else
                {
                    //WriteLine(now);
                    if (!shot)
                    {
                        res += Max(now - r + 1, 0);
                        shot = true;
                    }
                    res++;
                    now -= r;
                }
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