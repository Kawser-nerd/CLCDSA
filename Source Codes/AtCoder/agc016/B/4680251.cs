using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.AGC_Challenge
{
    class _016_B
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

            int multis = 0;
            int alones = 0;
            for(int i = 0; i < n; i++)
            {
                if (array[n - 1] == array[i]) multis++;
                else alones++;
            }
            if (multis == n && array[n - 1] == n - 1)
            {
                WriteLine("Yes");
                return;
            }

            if (multis == 1)
            {
                WriteLine("No");
                return;
            }

            int multiMin = 1;
            int multiMax = multis / 2;
            if(array[n-1]< alones+multiMin
                || array[n - 1] > alones + multiMax)
            {
                WriteLine("No");
                return;
            }
            WriteLine("Yes");
            return;
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