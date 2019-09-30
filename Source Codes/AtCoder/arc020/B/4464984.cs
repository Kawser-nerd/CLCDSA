using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _020
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nc = ReadInts();
            int n = nc[0];
            int c = nc[1];
            int[] array = new int[n];
            for (int i = 0; i < n; i++) array[i] = ReadInt() - 1;
            int minCost = int.MaxValue;
            for(int i = 0; i < 10; i++)
            {
                for (int j = i + 1; j < 10; j++)
                {
                    int iCost = 0;
                    int jCost = 0;
                    for (int k = 0; k < n; k++)
                    {
                        if (k % 2 == 0)
                        {
                            if (i != array[k]) iCost += c;
                            if (j != array[k]) jCost += c;
                        }
                        else
                        {
                            if (i != array[k]) jCost += c;
                            if (j != array[k]) iCost += c;
                        }
                    }
                    minCost = Min(minCost, Min(iCost, jCost));
                }
            }
            WriteLine(minCost);
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