using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_075
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nk = ReadInts();
            var poses = new long[nk[0]][];
            var xs = new long[nk[0]];
            var ys = new long[nk[0]];
            for (int i = 0; i < nk[0]; i++)
            {
                poses[i] = ReadLongs();
                xs[i] = poses[i][0];
                ys[i] = poses[i][1];
            }

            long minRect = long.MaxValue;
            Array.Sort(xs);
            Array.Sort(ys);
            for (int i = 0; i < nk[0] - 1; i++)
            {
                for (int j = i + 1; j < nk[0]; j++)
                {
                    for (int k = 0; k < nk[0] - 1; k++)
                    {
                        for (int l = k + 1; l < nk[0]; l++)
                        {
                            int cnt = 0;
                            long x1 = xs[i];
                            long x2 = xs[j];
                            long y1 = ys[k];
                            long y2 = ys[l];
                            for (int m = 0; m < nk[0]; m++)
                            {
                                if (x1 <= poses[m][0] && poses[m][0] <= x2
                                    && y1 <= poses[m][1] && poses[m][1] <= y2)
                                {
                                    cnt++;
                                }
                            }
                            if (cnt >= nk[1])
                            {
                                minRect = Math.Min(minRect,
                                    (x2 - x1) * (y2 - y1));
                            }
                        }
                    }
                }
            }
            Console.WriteLine(minRect);
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