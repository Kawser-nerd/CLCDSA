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
                string s = Console.ReadLine();
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWork(s)
                    );
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);
            }
        }

        private string DoWork(string s)
        {
            int N = s.Length;
            int pos = N - 1;
            string beg = "";
            string end = "";
            bool[] used = new bool[N];
            do
            {
                int nextpos = -1;
                char best = (char)('A' - 1);
                for (int i = 0; i <= pos; i++)
                {
                    if (s[i]>=best)
                    {
                        best = s[i];
                        nextpos = i;
                    }
                }
                used[nextpos] = true;
                beg += best;
                pos = nextpos - 1;
            } while (pos>=0);

            for (int i = 0; i < N; i++)
            {
                if (!used[i]) end += s[i];
            }

            return beg + end;
        }
    }
}
