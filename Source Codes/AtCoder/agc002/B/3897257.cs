using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _002_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nm = ReadInts();
            var xys = new int[nm[1]][];
            for(int i = 0; i < nm[1]; i++)
            {
                xys[i] = ReadInts();
            }
            var cnts = new int[nm[0]];
            var inRed = new bool[nm[0]];
            inRed[0] = true;

            for (int i = 0; i < nm[1]; i++)
            {
                int x = xys[i][0] - 1;
                int y = xys[i][1] - 1;

                if (inRed[x])
                {
                    if (cnts[x] == 0)
                    {
                        inRed[x] = false;
                    }
                    inRed[y] = true;
                }
                cnts[x]--;
                cnts[y]++;
            }

            int cnt = 0;
            for(int i = 0; i < nm[0]; i++)
            {
                if (inRed[i]) cnt++;
            }
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