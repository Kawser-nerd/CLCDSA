using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_017
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nm = ReadInts();
            int n = nm[0];
            int m = nm[1];
            var fs = new int[n];
            var samePoses = new int[n];
            var dict = new Dictionary<int, int>();
            for (int i = 0; i < n; i++)
            {
                fs[i] = ReadInt();
                if (dict.ContainsKey(fs[i]))
                {
                    samePoses[i] = dict[fs[i]];
                    dict[fs[i]] = i;
                }
                else
                {
                    samePoses[i] = -1;
                    dict.Add(fs[i], i);
                }
            }
            for(int i = 1; i < n; i++)
            {
                samePoses[i] = Math.Max(samePoses[i - 1], samePoses[i]);
            }
            var sums = new long[n];
            long mask = 1000000000 + 7;
            sums[0] = 1;
            for(int i = 1; i < n; i++)
            {
                if (samePoses[i] == -1)
                {
                    sums[i] = sums[i - 1] * 2 + 1;
                }
                else
                {
                    if (samePoses[i] == 0)
                    {
                        sums[i] = sums[i - 1] * 2;
                    }
                    else
                    {
                        sums[i] = sums[i - 1] * 2 - sums[samePoses[i] - 1];
                    }
                }
                sums[i] %= mask;
                //Console.WriteLine(sums[i]);
            }
            Console.WriteLine((sums[n - 1] - sums[n - 2] + mask) % mask);
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