using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _035
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] ts = new int[n];
            for (int i = 0; i < n; i++) ts[i] = ReadInt();
            Array.Sort(ts);
            long val = 0;
            long time = 0;
            var cntDict = new Dictionary<int, int>();
            for(int i = 0; i < n; i++)
            {
                time += ts[i];
                val += time;
                if (!cntDict.ContainsKey(ts[i])) cntDict.Add(ts[i], 0);
                cntDict[ts[i]]++;
            }
            WriteLine(val);
            long pat = 1;
            long mask = 1000000000 + 7;
            foreach (int cnt in cntDict.Values)
            {
                pat = MultiMod(pat, Permutation(cnt, cnt, mask), mask);
            }
            WriteLine(pat);
        }

        static long Permutation(long n, long m, long mask)
        {
            long val = 1;
            for (long i = 0; i < m; i++)
            {
                val *= ((n - i) % mask);
                val %= mask;
            }
            return val;
        }

        static long MultiMod(long a, long b, long mask)
        {
            return ((a % mask) * (b % mask)) % mask;
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