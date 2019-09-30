using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_A
{
    class _052
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string s = Read();
            bool digit2 = false;
            int val = 0;
            for(int i = s.Length - 1; i >= 0; i--)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    if (digit2)
                    {
                        val+=(s[i]-'0')*10;
                    }
                    else
                    {
                        val += s[i] - '0';
                        digit2 = true;
                    }
                }
            }
            Console.WriteLine(val);
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