using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_030
{
    class B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            long[] ln = ReadLongs();
            long l = ln[0];
            int n = (int)ln[1];
            var xs = new long[n + 1];
            var xSums = new long[n + 1];
            for (int i = 1; i <= n; i++)
            {
                xs[i] = ReadLong();
                xSums[i] = xSums[i - 1] + xs[i];
            }
            var ys = new long[n + 1];
            var ySums = new long[n + 1];
            for (int i = 1; i <= n; i++)
            {
                ys[i] = l - xs[n + 1 - i];
                ySums[i] = ySums[i - 1] + ys[i];
            }

            long res = 0;
            for (int i = 0; i <= n; i++)
            {
                int r = n - i;
                long cnt = 0;
                long ll = 0;
                if (i > 0)
                {
                    cnt = Math.Min(i - 1, r);
                    ll += (xSums[i - 1] - xSums[i - 1 - cnt]) * 2;
                    ll += (ySums[r] - ySums[r - cnt]) * 2;
                    ll += xs[i];
                }

                long lr = 0;
                cnt = Math.Min(i, r);
                lr += (xSums[i] - xSums[i - cnt]) * 2;
                lr += (ySums[r] - ySums[r - cnt]) * 2;
                lr -= xs[i];

                long rl = 0;
                cnt = Math.Min(i, r);
                rl += (xSums[i] - xSums[i - cnt]) * 2;
                rl += (ySums[r] - ySums[r - cnt]) * 2;
                rl -= ys[r];

                long rr = 0;
                if (r > 0)
                {
                    cnt = Math.Min(i, r - 1);
                    rr += (xSums[i] - xSums[i - cnt]) * 2;
                    rr += (ySums[r - 1] - ySums[r - 1 - cnt]) * 2;
                    rr += ys[r];
                }
                res = Math.Max(res, Math.Max(Math.Max(ll, lr), Math.Max(rl, rr)));
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