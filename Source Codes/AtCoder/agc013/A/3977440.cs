using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _013_A
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] array = ReadInts();
            int state = 0;
            int cnt = 0;
            for(int i = 1; i < n; i++)
            {
                if (array[i - 1] < array[i])
                {
                    if (state == 1)
                    {
                        cnt++;
                        state = 0;
                    }
                    else state = 2;
                }
                else if (array[i - 1] > array[i])
                {
                    if (state == 2)
                    {
                        cnt++;
                        state = 0;
                    }
                    else
                    {
                        state = 1;
                    }
                }
            }
            cnt++;
            Console.WriteLine(cnt);
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