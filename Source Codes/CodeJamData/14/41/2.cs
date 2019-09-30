using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class DataPackin : GCJBase
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
                int X = int.Parse(s.Split(' ')[1]);
                string[] s2 = Console.ReadLine().Split(' ');
                int[] S = new int[N];
                for (int i = 0; i < N; i++)
                {
                    S[i] = int.Parse(s2[i]);
                }

                long ret = minDiscs(N, X, S);

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

        private int minDiscs(int N, int X, int[] S)
        {
            Array.Sort(S);
            List<int> sizes = new List<int>(S);
            int ret = 0;
            while (sizes.Count > 0)
            {
                int idx = sizes.Count - 1;
                int val1 = sizes[idx];
                for (int i = idx - 1; i >= 0; i--)
                {
                    if (val1 + sizes[i] <= X)
                    {
                        sizes.RemoveAt(idx);
                        sizes.RemoveAt(i);
                        break;
                    }
                }
                if (sizes.Count - 1 == idx)
                {
                    sizes.RemoveAt(idx);
                }
                ret++;
            }
            return ret;
        }
    }
}
