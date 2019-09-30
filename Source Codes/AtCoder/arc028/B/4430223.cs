using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _028
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nk = ReadInts();
            int n = nk[0];
            int k = nk[1];
            int[] array = ReadInts();
            var posDict = new Dictionary<int, int>();
            for(int i = 0; i < n; i++)
            {
                posDict.Add(array[i], i);
            }
            Array.Sort(array);
            var valPosDict = new Dictionary<int, int>();
            for(int i = 0; i < n; i++)
            {
                valPosDict.Add(posDict[array[i]], i);
                //WriteLine(posDict[array[i]] + " " + i);
            }
            int[] res = new int[n];
            bool[] unuses = new bool[n];
            int now = k - 1;
            for (int i = n - 1; i >= k - 1; i--)
            {
                while (unuses[now]) now++;
                res[i] = posDict[array[now]] + 1;
                unuses[valPosDict[i]] = true;
                if (valPosDict[i] < now) now++;
            }
            //for (int i = 0; i < n; i++) WriteLine(unuses[i]);
            for(int i = k - 1; i < n; i++)
            {
                WriteLine(res[i]);
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