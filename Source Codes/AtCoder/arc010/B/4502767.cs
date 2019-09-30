using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _010
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] holidays = new int[n];
            int[] days = new int[12] {
                31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            for (int i =0; i < n; i++)
            {
                string[] ss = Read().Split('/');
                int m = int.Parse(ss[0]);
                for(int j = 0; j < m - 1; j++)
                {
                    holidays[i] += days[j];
                }
                holidays[i] += int.Parse(ss[1]);
                //WriteLine(holidays[i]);
            }
            Array.Sort(holidays);
            bool[] isHolidays = new bool[366];
            int week = 6;
            int holidayNow = 0;
            int holidayRemain = 0;
            for (int i = 0; i < 366; i++)
            {
                if (holidayNow < n && i == holidays[holidayNow] - 1)
                {
                    holidayRemain++;
                    holidayNow++;
                }

                if (week < 5 && holidayRemain>0)
                {
                    isHolidays[i] = true;
                    holidayRemain--;
                }
                if (week >= 5)
                {
                    isHolidays[i] = true;
                }
                week = (week + 1) % 7;
            }
            int res = 1;
            int tmp = 1;
            int day = 2;
            while (day<=366)
            {
                if (isHolidays[day-1])
                {
                    tmp++;
                }
                else
                {
                    tmp = 0;
                }
                res = Max(res, tmp);
                day++;
            }
            WriteLine(res);
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