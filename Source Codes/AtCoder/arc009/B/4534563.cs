using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _009
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] bArray = ReadInts();
            var cDict = new Dictionary<int, int>();
            var rDict = new Dictionary<int, int>();
            for(int i = 0; i <= 9; i++)
            {
                cDict.Add(bArray[i],i);
                rDict.Add(i,bArray[i]);
            }
            int n = ReadInt();
            int[] array = new int[n];
            for(int i = 0; i < n; i++)
            {
                int val = ReadInt();
                int rev = 0;
                int div = 1;
                while (val > 0)
                {
                    rev += cDict[val % 10] * div;
                    val /= 10;
                    div *= 10;
                }
                array[i] = rev;
            }
            Array.Sort(array);
            for(int i = 0; i < n; i++)
            {
                int res = 0;
                int div = 1;
                while (array[i] > 0)
                {
                    res += rDict[array[i] % 10]*div;
                    array[i] /= 10;
                    div *= 10;
                }
                WriteLine(res);
            }
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