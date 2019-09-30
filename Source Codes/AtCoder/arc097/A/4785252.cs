using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.Virtual
{
    class ARC097_C
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            string s = Read();
            int k = ReadInt();
            List<long> vals = new List<long>();
            for(int i = 0; i < s.Length; i++)
            {
                long val = 0;
                for(int j = i; j < Min(i + 5, s.Length); j++)
                {
                    val += (s[j] - 'a' + 1) * (long)Pow(100, 4 - (j - i));
                    vals.Add(val);
                }
            }
            vals.Sort();
            int cnt = 0;
            for(int i = 0; i < vals.Count; i++)
            {
                if (i == 0 || vals[i - 1] != vals[i]) cnt++;
                if (cnt == k)
                {
                    long val = vals[i];
                    //WriteLine(val);
                    for(int j = 4; j >= 0; j--)
                    {
                        long div = (long)Pow(100, j);
                        long v = (val / div) % 100;
                        if (v > 0)
                        {
                            Write((char)(v + 'a' - 1));
                        }
                    }
                    WriteLine();
                    return;
                }
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