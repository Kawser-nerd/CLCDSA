using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class UpAndDown : GCJBase
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
                string[] s2 = Console.ReadLine().Split(' ');
                int[] A = new int[N];
                for (int i = 0; i < N; i++)
                {
                    A[i] = int.Parse(s2[i]);
                }
                long ret = minSwaps(N, A);

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

        private int minSwaps(int N, int[] A)
        {
            List<int> vals = new List<int>(A);
            int ret = 0;
            List<int> sortedVals = new List<int>(A);
            sortedVals.Sort();
            for (int i = 0; i < N; i++)
            {
                int val = sortedVals[i];
                for (int j = 0; j < N - i; j++)
                {
                    if (vals[j] == val)
                    {
                        ret += Math.Min(j, N - i - j - 1);
                        vals.RemoveAt(j);
                        break;
                    }
                }
            }
            return ret;
        }

    }
}
