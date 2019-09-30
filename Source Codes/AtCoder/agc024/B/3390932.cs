using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _024_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var ps = new int[n];
            for (int i = 0; i < n; i++)
            {
                ps[i] = ReadInt();
            }
            var lengthArray = new int[n];
            var indexDict = new Dictionary<int, int>();
            for(int i = n - 1; i >= 0; i--)
            {
                if (indexDict.ContainsKey(ps[i] + 1))
                {
                    lengthArray[i] = lengthArray[indexDict[ps[i] + 1]] + 1;
                }
                else
                {
                    lengthArray[i] = 1;
                }
                indexDict.Add(ps[i], i);
            }
            int max = 0;
            for(int i = 0; i < n; i++)
            {
                max = Math.Max(lengthArray[i], max);
            }
            Console.WriteLine(n - max);
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