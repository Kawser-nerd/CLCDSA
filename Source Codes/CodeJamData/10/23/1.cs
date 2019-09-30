using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ10R1
{
    class RankPure : GCJBase
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
                long ret = CalcWays(int.Parse(s));

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        long MOD = 100003;

        private long CalcWays(int N)
        {
            checked
            {
                long[,] ways = new long[N + 1, N + 1];

                for (int i = 2; i <= N; i++)
                {
                    ways[i, 1] = 1;
                    ways[i, i - 1] = 1;
                }

                long[,] choose = new long[N + 1, N + 1];

                for (int i = 0; i <= N; i++)
                {
                    choose[0, i] = 1;
                    choose[i, i] = 1;
                    for (int j = 1; j < i; j++)
                    {
                        choose[j, i] += choose[j, i - 1] + choose[j - 1, i - 1];
                        choose[j, i] %= MOD;
                    }
                }

                for (int i = 3; i <= N; i++)
                {
                    for (int d = 2; d <= i - 2; d++)
                    {
                        for (int lowd = 1; lowd <= d - 1; lowd++)
                        {
                            int highd = d - lowd - 1;
                            long lowways = ways[d, lowd];
                            long highways;
                            long highpool = i - d - 1;
                            if (highpool >= highd)
                            {
                                highways = choose[highd, highpool];
                            }
                            else
                            {
                                highways = 0;
                            }
                            ways[i, d] += lowways * highways;
                            ways[i, d] %= MOD;
                        }
                    }
                }

                long ret = 0;
                for (int i = 0; i <= N; i++)
                {
                    ret += ways[N, i];
                    ret %= MOD;
                }
                return ret;
            }
        }

    }
}
