using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class AGC_021_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var xys = new int[n][];
            for(int i = 0; i < n; i++)
            {
                xys[i] = ReadInts();
            }

            for(int i = 0; i < n; i++)
            {
                var rads = new double[n - 1];
                for (int j = 0; j < n; j++)
                {
                    if (i == j) continue;
                    double x = xys[j][0] - xys[i][0];
                    double y = xys[j][1] - xys[i][1];
                    double rad = Math.Atan2(y, x);
                    rad += Math.PI / 2;
                    if (rad < 0) rad += Math.PI * 2;
                    if (j > i)
                    {
                        rads[j - 1] = rad;
                    }
                    else
                    {
                        rads[j] = rad;
                    }
                }
                if (rads.Length == 1)
                {
                    Console.WriteLine(0.5);
                    continue;
                }

                Array.Sort(rads);
                double r = 0;
                for(int j = 0; j < n - 1; j++)
                {
                    int kk = (j + n - 2) % (n - 1);
                    while (rads[kk] == rads[j] && j != kk)
                    {
                        kk += (n - 2);
                        kk %= (n - 1);
                    }
                    double delta = rads[kk] - rads[j];
                    if (delta < 0) delta += Math.PI*2;
                    if (delta < Math.PI) r = Math.Max(r, Math.PI - delta);
                }
                Console.WriteLine(r / Math.PI / 2);
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