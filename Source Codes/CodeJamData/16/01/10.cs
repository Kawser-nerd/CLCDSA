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
                        () => DoWork(long.Parse(s[0]))
                    );
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);
            }
        }

        private string DoWork(long i)
        {
            if (i == 0) return "INSOMNIA";
            bool[] seen = new bool[10];
            int seencount = 0;
            long l = i;
            do
            {
                string s = l.ToString();
                foreach (char c in s.ToCharArray())
                {
                    if (!seen[c-'0'])
                    {
                        seen[c - '0'] = true;
                        seencount++;
                        if (seencount==10)
                        {
                            return l.ToString();
                        }
                    }
                }
                l += i;
            } while (true);
        }
    }
}
