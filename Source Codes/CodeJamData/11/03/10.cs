using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ11Q
{
    class CandySplitting: GCJBase
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
                string[] candies = Console.ReadLine().Split(' ');
                int[] c = new int[candies.Length];
                for (int i = 0; i < candies.Length; i++)
                {
                    c[i] = int.Parse(candies[i]);
                }
                long ret = CandySplit(c);

                Console.WriteLine("Case #{0}: {1}", iCase, ret>0 ? ret.ToString() : "NO");

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private int CandySplit(int[] c)
        {
            int tot = 0;
            Array.Sort(c);
            int x = 0;
            for (int i = 0; i < c.Length; i++)
            {
                tot += c[i];
                x ^= c[i];
            }
            tot -= c[0];
            if (x != 0) tot = -1;
            return tot;
        }

    }
}
