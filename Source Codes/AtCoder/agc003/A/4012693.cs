using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _003_A
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string ss = Read();
            bool n = false;
            bool w = false;
            bool s = false;
            bool e = false;
            for (int i = 0; i < ss.Length; i++)
            {
                switch (ss[i])
                {
                    case 'N': n = true; break;
                    case 'W': w = true; break;
                    case 'S': s = true; break;
                    case 'E': e = true; break;
                }
            }
            if (n == s && w == e) Console.WriteLine("Yes");
            else Console.WriteLine("No");
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