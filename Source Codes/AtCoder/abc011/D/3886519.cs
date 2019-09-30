using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_011
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nd = ReadInts();
            int[] xy = ReadInts();
            long n = nd[0];
            long d = nd[1];
            long x = Math.Abs(xy[0]);
            long y = Math.Abs(xy[1]);
            if (x % d > 0 || y % d > 0
                || n * d < x + y
                || (n - (x + y) / d) % 2 > 0)
            {
                Console.WriteLine(0);
                return;
            }

            long xCnt = x / d;
            long yCnt = y / d;
            long remain = (n - (x + y) / d) / 2;

            double res = 0;
            
            for (int i = 0; i <= remain; i++)
            {
                var xyCnts = new long[4]
                { xCnt + i, i, yCnt + remain - i, remain - i };
                Array.Sort(xyCnts);
                Array.Reverse(xyCnts);
                double val = 1;
                int index = 0;
                double div = xyCnts[index];
                for(int j = 0; j < n; j++)
                {
                    val *= (n - j);
                    val /= div;
                    val /= 4;
                    div--;
                    if(div == 0&&index<3)
                    {
                        index++;
                        div = xyCnts[index];
                    }
                }
                res += val;
            }
            Console.WriteLine(res);
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