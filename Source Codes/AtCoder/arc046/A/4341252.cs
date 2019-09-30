using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_A
{
    class _046
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int digit = n / 9;
            if (n % 9 > 0) digit += 1;
            char chr = n % 9 == 0 ? '9' : (char)((n % 9) + '0');
            string s = "";
            for(int i = 0; i < digit; i++)
            {
                s += chr;
            }
            Console.WriteLine(s);
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