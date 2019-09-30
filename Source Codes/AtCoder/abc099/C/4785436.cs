using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.Virtual
{
    class ABC099_C
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int length = n / 9 + 1;
            List<int> sixes = new List<int>();
            int val = 1;
            while (val < n)
            {
                val *= 6;
                sixes.Add(val);
            }
            List<int> nines = new List<int>();
            val = 1;
            while (val < n)
            {
                val *= 9;
                nines.Add(val);
            }
            int res = int.MaxValue;
            for(int i = 0; i < length; i++)
            {
                int now = n - 9 * i;
                int cnt = 0;
                for(int j = sixes.Count-1; j >= 0; j--)
                {
                    cnt += now / sixes[j];
                    now %= sixes[j];
                }
                cnt += now;

                now = 9 * i;
                for(int j = nines.Count-1; j >= 0; j--)
                {
                    cnt += now / nines[j];
                    now %= nines[j];
                }
                res = Min(res, cnt);
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