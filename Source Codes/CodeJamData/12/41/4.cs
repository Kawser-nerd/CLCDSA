using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Swinging : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string s = Console.ReadLine();
                int N = int.Parse(s);
                long[] vinepos = new long[N];
                long[] vinelen = new long[N];
                for (int i = 0; i < N; i++)
                {
                    s = Console.ReadLine();
                    vinepos[i] = long.Parse(s.Split(' ')[0]);
                    vinelen[i] = long.Parse(s.Split(' ')[1]);
                }
                s = Console.ReadLine();
                long D = long.Parse(s);
                string ret = vineswing(N,vinepos,vinelen,D);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string vineswing(int N, long[] vinepos, long[] vinelen,long D)
        {
            long[] bestlen = new long[N];
            bestlen[0] = vinepos[0];

            for (int i = 0; i < N; i++)
            {
                long len = bestlen[i];
                len = Math.Min(len, vinelen[i]);
                if (len == 0) return "NO";

                long bestpos = vinepos[i] + len;
                if (bestpos >= D) return "YES";
                int j = i + 1;
                while (j < N && vinepos[j] <= bestpos)
                {
                    long jlen = vinepos[j] - vinepos[i];
                    bestlen[j] = Math.Max(bestlen[j], jlen);
                    j++;
                }
            }

            return "NO";
        }
    }
}
