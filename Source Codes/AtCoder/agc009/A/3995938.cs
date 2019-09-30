using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _009_A
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var aArray = new long[n];
            var bArray = new long[n];
            for(int i = 0; i < n; i++)
            {
                int[] ab = ReadInts();
                aArray[i] = ab[0];
                bArray[i] = ab[1];
            }
            Array.Reverse(aArray);
            Array.Reverse(bArray);
            long cnt = 0;
            for(int i = 0; i < n; i++)
            {
                long aNow = aArray[i] + cnt;
                if (aNow % bArray[i] == 0) continue;

                long dest = (aNow / bArray[i] + 1) * bArray[i];
                cnt += dest - aNow;
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