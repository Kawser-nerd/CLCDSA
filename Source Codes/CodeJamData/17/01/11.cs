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
            int iCases = int.Parse(sLines);

            System.Threading.Tasks.Task<string>[] tasks = new System.Threading.Tasks.Task<string>[iCases];

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string[] s = Console.ReadLine().Split();
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWork(s[0], int.Parse(s[1]))
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

        private string DoWork(string s, int k)
        {
            bool[] b = new bool[s.Length];
            for (int i = 0; i < s.Length; i++)
            {
                b[i] = s[i] == '+';
            }
            int ret = 0;
            for (int i = 0; i+k-1 < s.Length; i++)
            {
                if (!b[i])
                {
                    ret++;
                    for (int j = 0; j < k; j++)
                    {
                        b[i + j] = !b[i + j];
                    }
                }
            }

            for (int i = 0; i < s.Length; i++)
            {
                if (!b[i]) return "IMPOSSIBLE";
            }
            return ret.ToString();
        }
    }
}
