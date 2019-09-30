using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _019
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            string a = Read();
            if (a.Length == 1)
            {
                WriteLine(0);
                return;
            }
            int length = a.Length;
            int maxI = (length - 1) / 2;
            int rCnt = 0;
            for(int i = 0;i<=maxI;i++)
            {
                if (a[i] == a[length - 1 - i]) rCnt++;
            }
            long res = 0;
            for(int i = 0; i <=maxI; i++)
            {
                if (i == length - 1 - i)
                {
                    if (rCnt <= maxI) res += 25;
                }
                else
                {
                    if (rCnt==maxI&&a[i] != a[length - 1 - i]) res += 48;
                    else res += 50;
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