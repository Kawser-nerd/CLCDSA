using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.HCPCvirtual6
{
    class C
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nx = ReadInts();
            int n = nx[0];
            int x = nx[1];
            int[] ms = new int[n];
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                ms[i] = ReadInt();
                sum += ms[i];
            }
            x -= sum;
            Array.Sort(ms);
            WriteLine(n + x / ms[0]);
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