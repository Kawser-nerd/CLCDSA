using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_023
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var hs = new long[n];
            var ss = new long[n];
            for(int i = 0; i < n; i++)
            {
                long[] hsIn = ReadLongs();
                hs[i] = hsIn[0];
                ss[i] = hsIn[1];
            }
            long top = long.MaxValue;
            long bottom = 0;
            while (top - bottom > 1)
            {
                long h = (top + bottom) / 2;
                if(CanMake(n,hs, ss, h))
                {
                    top = h;
                }
                else
                {
                    bottom = h;
                }
            }
            Console.WriteLine(top);
        }

        static bool CanMake(int n,long[] hs,long[] ss,long h)
        {
            var canSet = new int[n];
            for(int i = 0; i < n; i++)
            {
                long margin = h - hs[i];
                if (margin < 0) return false;
                long cnt = margin / ss[i];
                cnt = Math.Min(cnt, n - 1);
                canSet[cnt]++;
            }
            int all = 0;
            for(int i = 0; i < n; i++)
            {
                all += canSet[i];
                if (all > i + 1) return false;
            }
            return true;
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