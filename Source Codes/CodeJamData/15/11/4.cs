using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class A : GCJBase
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
                string[] s2 = Console.ReadLine().Split();
                List<int> mushCount = s2.ToList().ConvertAll(ss => int.Parse(ss));
                long ret1 = minMushArb(mushCount);
                long ret2 = minMushConst(mushCount);
                string ret = string.Format("{0} {1}", ret1, ret2);

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

        private int minMushArb(List<int> mC)
        {
            int ret = 0;
            int last = 0;
            foreach (int m in mC)
            {
                if (m > last)
                {
                }
                else
                {
                    ret += (last - m);
                }
                last = m;
            }
            return ret;
        }

        private int minMushConst(List<int> mC)
        {
            int minRate = 0;
            for (int i = 1; i < mC.Count; i++)
            {
                minRate = Math.Max(minRate, mC[i - 1] - mC[i]);
            }
            int ret = 0;
            for (int i = 1; i < mC.Count; i++)
            {
                ret += Math.Min(mC[i-1], Math.Max(minRate, mC[i - 1] - mC[i]));
            }
            return ret;
        }

    }
}
