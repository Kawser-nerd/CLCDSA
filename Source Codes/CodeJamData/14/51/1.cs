using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Transistors : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string[] s = Console.ReadLine().Split(' ');
                int N = int.Parse(s[0]);
                int p = int.Parse(s[1]);
                int q = int.Parse(s[2]);
                int r = int.Parse(s[3]);
                int s2 = int.Parse(s[4]);
                double ret = maxChance(N, p, q, r, s2);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //System.Diagnostics.Debug.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //    System.Diagnostics.Debug.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private double maxChance(int N, long p, long q, long r, long s)
        {

            long[] t = new long[N];
            long tot = 0;
            for (int i = 0; i < N; i++)
            {
                t[i] = (i * p + q) % r + s;
                tot += t[i];
            }
            long[] totLeft = new long[N + 1];
            long[] totRight = new long[N + 1];
            for (int i = 0; i < N; i++)
            {
                totLeft[i + 1] = totLeft[i] + t[i];
            }
            for (int i = N - 1; i >= 0; i--)
            {
                totRight[i] = totRight[i + 1] + t[i];
            }

            long best = 0;

            for (int a = 0; a < N; a++)
            {
                long left = totLeft[a];
                long remaining = tot - left;
                int bmax = N - 1;
                int bmin = a;

                long right;
                long mid;

                while (bmax > bmin)
                {
                    int btry = (bmax + bmin + 1) / 2;
                    right = totRight[btry + 1];
                    mid = remaining - right;
                    if (right >= mid)
                    {
                        bmin = btry;
                    }
                    else
                    {
                        bmax = btry - 1;
                    }
                }

                right = totRight[bmin + 1];
                mid = remaining - right;
                long max3 = Math.Max(left, Math.Max(right, mid));
                best = Math.Max(best, tot - max3);

                if (bmin > a)
                {
                    right = totRight[bmin];
                    mid = remaining - right;
                    max3 = Math.Max(left, Math.Max(right, mid));
                    best = Math.Max(best, tot - max3);
                }

                if (bmin < N - 1)
                {
                    right = totRight[bmin + 2];
                    mid = remaining - right;
                    max3 = Math.Max(left, Math.Max(right, mid));
                    best = Math.Max(best, tot - max3);
                }
            }

            return 1.0 * best / tot;
        }
    }
}
