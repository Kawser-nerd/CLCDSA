using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class C : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            int iCases = int.Parse(sLines);

            System.Threading.Tasks.Task<string>[] tasks = new System.Threading.Tasks.Task<string>[iCases];

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string[] s = Console.ReadLine().Split();
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWork(long.Parse(s[0]), long.Parse(s[1]))
                    );
                //tasks[iCase - 1].Wait();
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);
            }
        }

        private string DoWork(long N, long K)
        {
            SortedDictionary<long, long> gaps = new SortedDictionary<long, long>();
            gaps[-N] = 1;
            do
            {
                var gap = gaps.First();
                    long gap1 = -gap.Key / 2;
                long gap2 = (-gap.Key - 1) / 2;
                if (K <= gap.Value)
                {
                    return string.Format("{0} {1}", gap1, gap2);
                }
                K -= gap.Value;
                if (gap1 > 0)
                {
                    if (gaps.ContainsKey(-gap1))
                    {
                        gaps[-gap1] += gap.Value;
                    } else
                    {
                        gaps[-gap1] = gap.Value;
                    }
                }

                if (gap2 > 0)
                {
                    if (gaps.ContainsKey(-gap2))
                    {
                        gaps[-gap2] += gap.Value;
                    }
                    else
                    {
                        gaps[-gap2] = gap.Value;
                    }
                }
                gaps.Remove(gap.Key);

            } while (gaps.Count>0);
            return "0 0";
        }
    }
}
