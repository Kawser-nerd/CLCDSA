using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Osmos : GCJBase
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
                long A = long.Parse(s.Split(' ')[0]);
                long N = long.Parse(s.Split(' ')[1]);
                long[] motes = new long[N];
                string[] s2 = Console.ReadLine().Split(' ');
                for (int i = 0; i < N; i++)
                {
                    motes[i] = long.Parse(s2[i]);
                }
                long ret = minMoves(A,motes);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private long minMoves(long A, long[] motes)
        {
            if (A == 1) return motes.Length;
            int best = motes.Length;
            Array.Sort(motes);
            for (int r = 0; r < motes.Length; r++)
            {
                int adds = 0;
                long A2 = A;
                for (int i = 0; i < motes.Length-r; i++)
                {
                    while (A2 <= motes[i])
                    {
                        A2 += A2 - 1;
                        adds++;
                    }
                    A2 += motes[i];
                }
                best = Math.Min(best, adds + r);
            }
            return best;
        }

    }
}
