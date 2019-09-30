using System;
using System.Collections.Generic;
using System.Text;

namespace GCJ10Q
{
    class ThemePark : GCJBase
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
                long R = long.Parse(s[0]);
                long k = long.Parse(s[1]);
                long N = long.Parse(s[2]);
                s = Console.ReadLine().Split(' ');
                long[] caps = new long[N];
                for (int i = 0; i < N; i++)
                {
                    caps[i] = long.Parse(s[i]);
                }
                long ret = FairCash(R, k, N, caps);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private long FairCash(long R, long k, long N, long[] groups)
        {
            long allgroups = 0;
            int[] firstfront = new int[N+1];
            for (int i = 0; i < N; i++)
            {
                allgroups += groups[i];
                firstfront[i] = -1;
            }
            if (allgroups <= k)
            {
                return R * allgroups;
            }
            firstfront[0] = 0;
            int front = 0;
            long tot = 0;
            int idx = 0;
            long[] totidx = new long[N + 1];
            bool found = false;

            do
            {
                long cap=k;
                int lastfront = front;
                idx++;
                if (idx > R) return tot;
                while (groups[front] <= cap)
                {
                    tot += groups[front];
                    cap -= groups[front];
                    front++;
                    if (front == N) front = 0;
                }
                if (!found)
                {
                    totidx[idx] = tot;
                    if (firstfront[front] >= 0)
                    {
                        // cycle found
                        int cylen = idx - firstfront[front];
                        long cymon = totidx[idx] - totidx[firstfront[front]];
                        long cyrem = (R - idx) / cylen;
                        tot += cymon * cyrem;
                        R -= cylen * cyrem;
                        found = true;
                        continue;
                    }
                    firstfront[front] = idx;
                }
            } while (true);
        }
    }
}
