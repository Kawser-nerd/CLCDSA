using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class BBBB : GCJBase
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
                int[] cards = new int[N];
                for (int i = 0; i < N; i++)
                {
                    cards[i] = int.Parse(s[i + 1]);
                }
                long ret = longstraight(cards);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private long longstraight(int[] cards)
        {
            int N = cards.Length;
            if (N == 0) return 0;
            int MAX=10005;
            int[] count = new int[MAX];
            for (int i = 0; i < N; i++)
            {
                count[cards[i]]++;
            }

            List<int> starts = new List<int>();
            List<int> ends = new List<int>();
            for (int i = 1; i < MAX-1; i++)
            {
                    for (int j = 0; j < count[i]-count[i-1]; j++)
                    {
                        starts.Add(i);
                    }
                    for (int j = 0; j < count[i] - count[i+1]; j++)
                    {
                        ends.Add(i);
                    }
            }

            long slen = N/starts.Count;
            while (slen > 1)
            {
                bool[] used = new bool[ends.Count];
                for (int i = 0; i < starts.Count; i++)
                {
                    bool foundend = false;
                    for (int j = 0; j < ends.Count; j++)
                    {
                        if (!used[j] && ends[j] >= starts[i] + slen - 1)
                        {
                            foundend = true;
                            used[j] = true;
                            break;
                        }
                    }
                    if (!foundend)
                    {
                        slen--;
                        break;
                    }
                }
                return slen;
            }


            return 1;
        }
    }
}
