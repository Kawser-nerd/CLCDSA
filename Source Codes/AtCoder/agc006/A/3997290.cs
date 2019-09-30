using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _006_A
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            string ps = Read();
            string ss = Read();
            for(int i = 0; i < n; i++)
            {
                bool canMake = true;
                for (int j = 0; j < n - i; j++)
                {
                    if (ps[i + j] != ss[j])
                    {
                        canMake = false;
                        break;
                    }
                }
                if (canMake)
                {
                    Console.WriteLine(i + n);
                    return;
                }
            }
            Console.WriteLine(n * 2);
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