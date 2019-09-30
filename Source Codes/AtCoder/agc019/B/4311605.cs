using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _019_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string a = Read();
            long noNeed = 0;
            var dict = new Dictionary<char, long>();
            for(int i = 0; i < a.Length; i++)
            {
                if (dict.ContainsKey(a[i]))
                {
                    noNeed += dict[a[i]];
                }
                else
                {
                    dict.Add(a[i], 0);
                }
                dict[a[i]]++;
            }
            long length = a.Length;
            long all = length * (length - 1) / 2;
            Console.WriteLine(all - noNeed + 1);
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