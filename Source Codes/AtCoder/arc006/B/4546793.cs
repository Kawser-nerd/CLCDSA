using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _006
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nl = ReadInts();
            int n = nl[0];
            int l = nl[1];
            string[] amida=new string[l];
            for (int i = 0; i < l; i++) amida[i] = Read();
            string last = Read();
            int now = 0;
            for (int i = 0; i < n * 2 - 1; i++) if (last[i] == 'o') now = i;
            //WriteLine(l);
            for (int i = l - 1; i >= 0; i--)
            {
                if (now > 0 && amida[i][now - 1] == '-')now -= 2;
                else if (now + 2 < n * 2 - 1 && amida[i][now + 1] == '-') now += 2;
                //WriteLine(now);
            }
            WriteLine(now / 2 + 1);
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