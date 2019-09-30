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
                long[] pos = ReadLongs();
                poses[i] = new long[4] { 0, 0, pos[0], pos[1] };
                xs[i] = pos[0];
                ys[i] = pos[1];
            }

            Array.Sort(poses, (a, b) => (int)(a[2] - b[2]));
            for(int i = 0; i < nk[0]; i++)
            {
                poses[i][0] = i;
            }
            Array.Sort(poses, (a, b) => (int)(a[3] - b[3]));
            for (int i = 0; i < nk[0]; i++)
            {
                poses[i][1] = i;
            }
            var grid = new long[nk[0], nk[0]][];
            for(int i = 0; i < nk[0]; i++)
            {
                grid[poses[i][0], poses[i][1]]
                    = new long[2] { poses[i][2], poses[i][3] };
            }

            long minRect = long.MaxValue;
            Array.Sort(xs);
            Array.Sort(ys);
            for (int i = 0; i < nk[0]-1; i++)
            {
                for(int j = i+1; j < nk[0]; j++)
                {
                    for(int k = 0; k < nk[0]-1; k++)
                    {
                        for(int l = k + 1; l < nk[0]; l++)
                        {
                            int cnt = 0;
                            long x1 = xs[i];
                            long x2 = xs[j];
                            long y1 = ys[k];
                            long y2 = ys[l];
                            for (int m = 0; m < nk[0]; m++)
                            {
                                if(x1<=poses[m][2]&&poses[m][2]<=x2
                                    && y1 <= poses[m][3] && poses[m][3] <= y2)
                                {
                                    cnt++;
                                }
                            }
                            if (cnt >= nk[1])
                            {
                                minRect = Math.Min(minRect,
                                    (x2 - x1) * (y2 - y1));
                                //Console.WriteLine(cnt);
                                //Console.WriteLine(x1 + "-" + x2 + " "
                                //    + y1 + "-" + y2);
                            }
                        }
                    }
                }
            }
            Console.WriteLine(minRect);
        }

        static long CalcRect(params long[][] poses)
        {
            long x = long.MaxValue;
            long y = long.MaxValue;
            long x2 = long.MinValue;
            long y2= long.MinValue;
            long rect = 0;
            for(int i = 0; i < poses.Length; i++)
            {
                x = Math.Min(x, poses[i][0]);
                y = Math.Min(y, poses[i][1]);
                x2 = Math.Max(x2, poses[i][0]);
                y2 = Math.Max(y2, poses[i][1]);
            }
            return (x2 - x) * (y2 - y);
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