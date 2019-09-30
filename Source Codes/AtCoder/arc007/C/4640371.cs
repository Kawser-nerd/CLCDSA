using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
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
            string s = Read();
            int n = s.Length;
            int allPat = 1 << (n - 1);
            int res = 100;
            for(int i = 0; i < allPat; i++)
            {
                bool[] on = new bool[n];
                for(int j = 0; j < n; j++)
                {
                    on[j] = s[j] == 'o';
                }
                int cnt = 1;
                for(int j = 0; j < n - 1; j++)
                {
                    if ((i & (1 << j)) == 0) continue;
                    cnt++;
                    for (int k = 0; k < n; k++)
                    {
                        on[(k + j + 1) % n] |= s[k] == 'o';
                    }
                }
                bool ok = true;
                for(int j = 0; j < n; j++)
                {
                    ok &= on[j];
                }
                if (ok) res = Min(res, cnt);
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