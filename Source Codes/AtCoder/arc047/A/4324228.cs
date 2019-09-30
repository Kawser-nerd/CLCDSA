using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_A
{
    class _047
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nl = ReadInts();
            int n = nl[0];
            int l = nl[1];
            string s = Read();
            int now = 1;
            int res = 0;
            for(int i = 0; i < s.Length; i++)
            {
                if (s[i] == '+')
                {
                    now++;
                    if (now > l)
                    {
                        now = 1;
                        res++;
                    }
                }
                else
                {
                    now--;
                }
            }
            Console.WriteLine(res);
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