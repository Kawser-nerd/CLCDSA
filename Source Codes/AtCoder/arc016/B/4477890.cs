using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _016
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            bool[] ons = new bool[9];
            int res = 0;
            for(int i = 0; i < n; i++)
            {
                string s = Read();
                for(int j = 0; j < 9; j++)
                {
                    if (s[j] == 'o')
                    {
                        if (!ons[j])
                        {
                            res++;
                            ons[j] = true;
                        }
                    }
                    else
                    {
                        ons[j] = false;
                        if (s[j] == 'x') res++;
                    }
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