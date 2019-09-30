using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.Virtual
{
    class AGC016_B
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
            Array.Sort(array);
            if (array[n - 1] - array[0] > 1)
            {
                WriteLine("No");
                return;
            }
            if (array[n - 1] == array[0]
                && array[0] == n - 1)
            {
                WriteLine("Yes");
                return;
            }

            int smallCnt = 0;
            int largeCnt = 0;
            for(int i = 0; i < n; i++)
            {
                if (array[i] == array[n-1]) largeCnt++;
                else smallCnt++;
            }
            int min = 1;
            int max = largeCnt / 2;
            if (largeCnt>1&&min + smallCnt <= array[n - 1] 
                && array[n - 1] <= max + smallCnt)
            {
                WriteLine("Yes");
            }
            else
            {
                WriteLine("No");
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