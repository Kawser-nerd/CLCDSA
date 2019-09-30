using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Prizes : GCJBase
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
                int N = int.Parse(s.Split(' ')[0]);
                long P = long.Parse(s.Split(' ')[1]);
                string ret = CalcPrizes(N, P);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string CalcPrizes(int N, long P)
        {
            checked
            {
                long l1 = 1;
                long teams = l1 << N;

                long lowestPossible = lowestPossibleWinner(N, P);
                long highestPossibleLoser = lowestPossibleWinner(N, teams - P);
                highestPossibleLoser = teams - highestPossibleLoser - 2;

                return String.Format("{0} {1}", highestPossibleLoser, lowestPossible);
            }
        }

        private long lowestPossibleWinner(int N, long P)
        {
            checked
            {
                long l1 = 1;
                long teams = l1 << N;
                long winners = teams;

                for (int i = 0; i <= N; i++)
                {
                    if (P >= winners)
                    {
                        return teams - (l1 << i);
                    }
                    winners /= 2;
                }

                return -1;
            }

        }

    }
}
