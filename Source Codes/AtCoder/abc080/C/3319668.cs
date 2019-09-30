using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_080
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var fs = new bool[n, 10];
            for (int i = 0; i < n; i++)
            {
                int[] fi = ReadInts();
                for(int j = 0; j < 10; j++)
                {
                    fs[i, j] = fi[j] == 1;
                }
            }
            var ps = new long[n, 11];
            for(int i = 0; i < n; i++)
            {
                long[] pi = ReadLongs();
                for(int j = 0; j <= 10; j++)
                {
                    ps[i, j] = pi[j];
                }
            }
            //bit???
            int allPat = (int)Math.Pow(2, 10);
            long surplus = long.MinValue;
            for(int i = 1; i < allPat; i++)
            {
                long surplusTemp = 0;
                for(int j = 0; j < n; j++)
                {
                    int bothCnt = 0;
                    for (int k = 0; k < 10; k++)
                    {
                        if (((i >> k) & 1) == 1 && fs[j, k])
                        {
                            bothCnt++;
                        }
                    }
                    surplusTemp += ps[j, bothCnt];
                }
                surplus = Math.Max(surplus, surplusTemp);
            }
            Console.WriteLine(surplus);
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}