using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _007
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nm = ReadInts();
            int n = nm[0];
            int m = nm[1];
            var posDict = new Dictionary<int, int>();
            for(int i = 0; i <= n; i++)
            {
                posDict.Add(i, i);
            }
            int now = 0;
            for(int i = 0; i < m; i++)
            {
                int next = ReadInt();
                posDict[now] = posDict[next];
                posDict[next] = 0;
                now = next;
            }
            int[] res = new int[n];
            for(int i = 0; i <= n; i++)
            {
                if (posDict[i] > 0) res[posDict[i] - 1] = i;
            }
            for(int i = 0; i < n; i++)
            {
                WriteLine(res[i]);
            }
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