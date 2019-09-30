using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class D : GCJBase
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
                        () => DoWork(int.Parse(s[0]), int.Parse(s[1]), int.Parse(s[2]))
                    );
                tasks[iCase - 1].Wait();
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);
            }
        }

        private string DoWork(int K, int C, int S)
        {
            if (S * C < K) return "IMPOSSIBLE";
            long pos = 0;
            List<long> ret = new List<long>();
            do
            {
                long p = 0;
                for (int i = 0; i < C; i++)
                {
                    p *= K;
                    p += Math.Min(pos, K - 1);
                    if (pos < K) pos++;
                }
                ret.Add(p + 1);
            } while (pos < K);

            string sret = "";
            foreach (var r in ret)
            {
                sret += r.ToString() + " ";
            }
            return sret.TrimEnd();
        }
    }
}
