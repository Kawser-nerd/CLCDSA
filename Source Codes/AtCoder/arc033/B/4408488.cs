using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _033
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nab = ReadInts();
            int na = nab[0];
            int nb = nab[1];
            int[] aArray = ReadInts();
            int[] bArray = ReadInts();
            var dict = new Dictionary<int, bool>();
            for(int i = 0; i < na; i++)
            {
                dict.Add(aArray[i],true);
            }
            int andCnt = 0;
            for(int i = 0; i < nb; i++)
            {
                if (dict.ContainsKey(bArray[i])) andCnt++;
            }
            WriteLine(1.0 * andCnt / (na + nb - andCnt));
        }

        private static string Read() { return ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}