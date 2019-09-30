using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_A
{
    class _055
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            List<char> val = new List<char>();
            int n = ReadInt();
            val.Add('1');
            for(int i = 0; i < n-1; i++)
            {
                val.Add('0');
            }
            val.Add('7');
            Console.WriteLine(val.ToArray());
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