using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _007_A
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] hw = ReadInts();
            int cnt = 0;
            for(int i = 0; i < hw[0]; i++)
            {
                string s = Read();
                for(int j = 0; j < hw[1]; j++)
                {
                    if (s[j] == '#') cnt++;
                }
            }
            Console.WriteLine(cnt == (hw[0] + hw[1] - 1)
                ? "Possible" : "Impossible");
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