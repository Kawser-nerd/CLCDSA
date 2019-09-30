using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _014
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            string s = Read();
            int[] rgbCnt = new int[3];
            for(int i = 0; i < n; i++)
            {
                switch (s[i])
                {
                    case 'R':
                        rgbCnt[0]++;
                        break;
                    case 'G':
                        rgbCnt[1]++;
                        break;
                    case 'B':
                        rgbCnt[2]++;
                        break;
                }
            }
            WriteLine(rgbCnt[0] % 2 + rgbCnt[1] % 2 + rgbCnt[2] % 2);
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