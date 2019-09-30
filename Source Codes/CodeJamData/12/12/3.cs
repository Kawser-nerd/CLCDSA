using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class KingdomRush : GCJBase
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
                int[] star1 = new int[N];
                int[] star2 = new int[N];
                for (int i = 0; i < N; i++)
                {
                    s = Console.ReadLine();
                    star1[i] = int.Parse(s.Split(' ')[0]);
                    star2[i] = int.Parse(s.Split(' ')[1]);
                }
                string ret = MinTries(N,star1,star2);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string MinTries(int N, int[] star1, int[] star2)
        {
            int bal = 0;
            int tries = 0;
            int[] done = new int[N];
            do
            {
                bool found2 = false;
                for (int i = 0; i < N; i++)
                {
                    if (done[i] < 2 && star2[i] <= bal)
                    {
                        tries++;
                        bal += 2 - done[i];
                        done[i] = 2;
                        found2 = true;
                        break;
                    }
                }
                if (found2) continue;

                int best2 = -1;
                int bestidx = -1;
                for (int i = 0; i < N; i++)
                {
                    if (done[i] == 0 && star1[i] <= bal && star2[i]>best2)
                    {
                        bestidx = i;
                        best2 = star2[i];
                    }
                }
                if (bestidx == -1) return "Too Bad";
                done[bestidx] = 1;
                tries++;
                bal++;
            } while (bal<2*N);
            return tries.ToString();
        }

    }
}
