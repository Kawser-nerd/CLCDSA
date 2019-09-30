using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _011_A
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nck = ReadInts();
            int n = nck[0];
            int c = nck[1];
            int k = nck[2];
            var ts = new int[n];
            for(int i = 0; i < n; i++)
            {
                ts[i] = ReadInt();
            }
            Array.Sort(ts);
            int cnt = 0;
            for(int i = 0; i < n;)
            {
                int limit = ts[i] + k;
                int rideCnt = 0;
                while (i < n && ts[i] <= limit && rideCnt < c)
                {
                    i++;
                    rideCnt++;
                }
                cnt++;
            }
            Console.WriteLine(cnt);
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