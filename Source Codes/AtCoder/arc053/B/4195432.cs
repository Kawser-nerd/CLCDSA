using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_B
{
    class _053
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string s = Read();
            int[] cnts = new int[26];
            for (int i = 0; i < s.Length; i++)
            {
                cnts[s[i] - 'a']++;
            }
            int alones = 0;
            for (int i = 0; i < 26; i++)
            {
                if (cnts[i] % 2 > 0) alones++;
            }
            int pairs = (s.Length - alones) / 2;
            if (alones > 0)
            {
                Console.WriteLine(pairs / alones * 2 + 1);
            }
            else
            {
                Console.WriteLine(s.Length);
            }
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