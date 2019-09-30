using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_A
{
    class _056
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            long[] abkl = ReadLongs();
            long res = abkl[2] / abkl[3] * abkl[1];
            long cnt = abkl[2] % abkl[3];
            res += Math.Min(abkl[0] * cnt, abkl[1]);
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