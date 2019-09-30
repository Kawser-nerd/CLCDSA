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
                int N = int.Parse(s[0]);
                int D = int.Parse(s[1]);
                s = Console.ReadLine().Split();
                int S0 = int.Parse(s[0]);
                int As = int.Parse(s[1]);
                int Cs = int.Parse(s[2]);
                int Rs = int.Parse(s[3]);
                s = Console.ReadLine().Split();
                int M0 = int.Parse(s[0]);
                int Am = int.Parse(s[1]);
                int Cm = int.Parse(s[2]);
                int Rm = int.Parse(s[3]);
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWork(N, D, S0, As, Cs, Rs, M0, Am, Cm, Rm)
                    );
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);
            }
        }

        private string DoWork(int N, int D, int S0, long As, int Cs, int Rs, int M0, long Am, int Cm, int Rm)
        {
            int[] S = new int[N];
            int[] S2 = new int[N];
            int[] M = new int[N];
            int[] EID = new int[N];
            S[0] = S0;
            M[0] = M0;
            S2[0] = S0;

            for (int i = 1; i < N; i++)
            {
                S[i] = (int)((S[i - 1] * As + Cs) % Rs);
                S2[i] = S[i];
                M[i] = (int)((M[i - 1] * Am + Cm) % Rm);
                EID[i] = i;
            }

            for (int i = 1; i < N; i++)
            {
                M[i] = M[i] % i;
            }

            Array.Sort(S2, EID);

            bool[] employed = new bool[N];
            int[] reports = new int[N];
            int min = 0;
            int best = 0;
            for (int max = 0; max < N; max++)
            {
                // New max is S2[max]
                int emp = EID[max];
                int cur = emp;
                int newreports = reports[emp] + 1;
                employed[cur] = true;
                while (cur != 0)
                {
                    int mgr = M[cur];
                    reports[mgr] += newreports;
                    cur = mgr;
                    if (!employed[cur]) break;
                }

                while (S2[max] - D > S2[min])
                {
                    // Remove employee min

                    emp = EID[min];
                    cur = emp;
                    int lostreports = reports[emp] + 1;
                    employed[cur] = false;
                    while (cur != 0)
                    {
                        int mgr = M[cur];
                        reports[mgr] -= lostreports;
                        cur = mgr;
                        if (!employed[cur]) break;
                    }
                    min++;
                }

                if (employed[0]) best = Math.Max(best, reports[0] + 1);
            }

            return best.ToString();
        }
    }
}
