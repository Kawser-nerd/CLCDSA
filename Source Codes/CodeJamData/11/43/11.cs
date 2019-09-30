using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class ExpensiveDinner : GCJBase
    {
        List<long> primes;
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            int maxp = 1000000;
            primes = new List<long>();
            bool[] comp = new bool[maxp];
            for (int i = 2; i < maxp; i++)
            {
                if (!comp[i])
                {
                    primes.Add(i);
                    for (int j = 2*i; j < maxp; j+=i)
                    {
                        comp[j] = true;
                    }
                }
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                long N = long.Parse(s);
                long ret = Calc(N);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }
            if (bManual) Console.ReadKey();
        }

        private long Calc(long N)
        {
            if (N == 1) return 0;
            long diff = 1;
            for (int i = 0; i < primes.Count && primes[i]*primes[i]<=N; i++)
            {
                long p = primes[i];

                long np = N;
                long pcount = 0;
                while (np >= p)
                {
                    np/=p;
                    pcount++;
                }
                diff += pcount - 1;
            }

            return diff;
        }

    }
}
