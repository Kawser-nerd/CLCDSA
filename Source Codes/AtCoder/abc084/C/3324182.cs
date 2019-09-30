using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_084
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var cs = new int[n - 1];
            var ss = new int[n - 1];
            var fs = new int[n - 1];
            for (int i = 0; i < n - 1; i++)
            {
                int[] input = ReadInts();
                cs[i] = input[0];
                ss[i] = input[1];
                fs[i] = input[2];
            }
            for (int i = 0; i < n; i++)
            {
                long time = 0;
                for(int j = i; j < n; j++)
                {
                    if (j == n - 1)
                    {
                        Console.WriteLine(time);
                    }
                    else
                    {
                        if (time <= ss[j])
                        {
                            time = ss[j];
                        }
                        else if (time % fs[j] != 0)
                        {
                            time = (time / fs[j] + 1) * fs[j];
                        }
                        time += cs[j];
                    }
                }
            }
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