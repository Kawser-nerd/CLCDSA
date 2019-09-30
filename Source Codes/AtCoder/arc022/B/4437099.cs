using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _022
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] array = ReadInts();
            int max = 1;
            int left = 0;
            int right = 0;
            var dict = new Dictionary<int, bool>();
            for (; right < n; right++)
            {
                while (dict.ContainsKey(array[right]))
                {
                    dict.Remove(array[left]);
                    left++;
                }
                dict.Add(array[right], true);
                max = Max(max, right - left + 1);
            }
            WriteLine(max);
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