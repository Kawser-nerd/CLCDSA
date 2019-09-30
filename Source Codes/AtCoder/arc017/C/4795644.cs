using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _017
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
            long x = nx[1];
            long[] ws = new long[n];
            for(int i = 0; i < n; i++)
            {
                ws[i] = ReadLong();
            }

            int formerCnt = n / 2;

            var formerDict = new Dictionary<long, long>();
            formerDict.Add(0, 1);
            for(int i = 0; i < formerCnt; i++)
            {
                var next = new Dictionary<long, long>();
                foreach(long key in formerDict.Keys)
                {
                    if (!next.ContainsKey(key))
                    {
                        next.Add(key, 0);
                    }
                    next[key] += formerDict[key];
                    long nextKey = key + ws[i];
                    if (x < nextKey) continue;

                    if (!next.ContainsKey(nextKey))
                    {
                        next.Add(nextKey, 0);
                    }
                    next[nextKey] += formerDict[key];
                }
                formerDict = next;
            }
            var laterDict = new Dictionary<long, long>();
            laterDict.Add(0, 1);
            for (int i = formerCnt; i < n; i++)
            {
                var next = new Dictionary<long, long>();
                foreach (long key in laterDict.Keys)
                {
                    if (!next.ContainsKey(key))
                    {
                        next.Add(key, 0);
                    }
                    next[key] += laterDict[key];
                    long nextKey = key + ws[i];
                    if (x < nextKey) continue;

                    if (!next.ContainsKey(nextKey))
                    {
                        next.Add(nextKey, 0);
                    }
                    next[nextKey] += laterDict[key];
                }
                laterDict = next;
            }
            long res = 0;
            foreach(long key in formerDict.Keys)
            {
                if (laterDict.ContainsKey(x - key))
                {
                    res += formerDict[key] * laterDict[x - key];
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