using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.AGC_C
{
    class _005
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
            int max = array[n - 1];
            if (max == 1 && n == 2)
            {
                WriteLine("Possible");
                return;
            }
            int min = (max + 1) / 2;
            int minCnt = 0;
            for(int i = 0; i < n; i++)
            {
                if (array[i] != min) break;
                minCnt++;
            }
            if ((max % 2 == 0 && minCnt != 1)
                || (max % 2 != 0 && minCnt != 2))
            {
                WriteLine("Impossible");
                return;
            }
            int now = min + 1;
            int nowCnt = 0;
            for(int i = minCnt; i < n; i++)
            {
                if (array[i] == now)
                {
                    nowCnt++;
                }
                else
                {
                    if (nowCnt < 2)
                    {
                        WriteLine("Impossible");
                        return;
                    }
                    now++;
                    nowCnt = 1;
                }
            }
            if (nowCnt < 2)
            {
                WriteLine("Impossible");
                return;
            }
            WriteLine("Possible");
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