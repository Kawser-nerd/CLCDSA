using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _021
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            long k = ReadLong();
            int n = ReadInt();
            long[][] ads = new long[n][];
            for (int i = 0; i < n; i++) ads[i] = ReadLongs();
            long bottom = 0;
            long top = long.MaxValue / 2;
            while (bottom + 1 < top)
            {
                long mid = (top + bottom) / 2;
                decimal cnt = 0;
                for(int i = 0; i < n; i++)
                {
                    if (ads[i][0] > mid) continue;

                    cnt += (mid - ads[i][0]) / ads[i][1] + 1;
                }
                if (cnt < k) bottom = mid;
                else top = mid;
            }
            long res = 0;
            for (int i = 0; i < n; i++)
            {
                if (ads[i][0] >= top) continue;

                long cnt = (top - ads[i][0]) / ads[i][1];
                if ((top - ads[i][0]) % ads[i][1] > 0) cnt++;
                res += ads[i][0] * cnt;
                res += (cnt * (cnt - 1) / 2) * ads[i][1];
                k -= cnt;
            }
            res += k * top;
            /*long t = 100000000;
            long t2 = 1000;
            long v = t * t / 2;
            v *= t2;
            v += t * t2;
            WriteLine(v);*/
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