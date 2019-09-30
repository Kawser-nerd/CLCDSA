using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
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
            int n = ReadInt();
            int[] ws = new int[n];
            for (int i = 0; i < n; i++) ws[i] = int.MaxValue;
            for (int i = 0; i < n; i++)
            {
                int w = ReadInt();
                for (int j = 0; j < n; j++)
                {
                    if (w <= ws[j])
                    {
                        ws[j] = w;
                        break;
                    }
                }
            }
            int cnt = n;
            for(int i = 0; i < n; i++)
            {
                //WriteLine(ws[i]);
                if (ws[i] == int.MaxValue) cnt--;
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