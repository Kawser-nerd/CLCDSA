using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ10R1
{
    class PickUpChicks : GCJBase
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
                int N = int.Parse(s[0]);
                int K = int.Parse(s[1]);
                int B = int.Parse(s[2]);
                int T = int.Parse(s[3]);

                int[] x = new int[N];
                int[] v = new int[N];
                s = Console.ReadLine().Split(' ');
                for (int i = 0; i < N; i++)
                {
                    x[i] = int.Parse(s[i]);
                }
                s = Console.ReadLine().Split(' ');
                for (int i = 0; i < N; i++)
                {
                    v[i] = int.Parse(s[i]);
                }
                string ret = minSwaps(N, K, B, T, x, v);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string minSwaps(int N, int K, int B, int T, int[] x, int[] v)
        {
            bool[] poss = new bool[N];
            int totmake = 0;
            for (int i = 0; i < N; i++)
            {
                if (x[i] + T * v[i] >= B) poss[i] = true;
                if (poss[i]) totmake++;
            }
            if (totmake < K) return "IMPOSSIBLE";

            int home = 0;
            int swaps = 0;
            for (int i = N-1; i >=0; i--)
            {
                if (poss[i]) home++;
                if (!poss[i])
                {
                    swaps += (K - home);
                }

                if (home == K) return swaps.ToString();
            }
            return "";
        }
    }
}
