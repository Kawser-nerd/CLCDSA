using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.AGC_031
{
    class B
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] cs = new int[n];
            for (int i = 0; i < n; i++) cs[i] = ReadInt();
            var have = new Dictionary<int, int>();
            have.Add(cs[n - 1], n - 1);
            var sums = new long[n];
            long mask = 1000000000 + 7;
            long res = 1;
            for(int i = n - 2; i >= 0; i--)
            {
                sums[i] = sums[i + 1];
                if (have.ContainsKey(cs[i]))
                {
                    if (i + 1 < have[cs[i]])
                    {
                        long next= sums[have[cs[i]]] + 1;
                        res += next;
                        res %= mask;
                        sums[i] += next;
                        sums[i] %= mask;
                    }
                    have[cs[i]] = i;
                }
                else
                {
                    have.Add(cs[i], i);
                }
                //WriteLine(sums[i]);
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