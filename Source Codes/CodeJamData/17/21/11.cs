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
                long D = long.Parse(s[0]);
                int N = int.Parse(s[1]);
                long[] horseStartLoc = new long[N];
                long[] horseSpeed = new long[N];
                for (int i = 0; i < N; i++)
                {
                    s = Console.ReadLine().Split();
                    horseStartLoc[i] = long.Parse(s[0]);
                    horseSpeed[i] = long.Parse(s[1]);
                }
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWork(D, N, horseStartLoc, horseSpeed)
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

        private string DoWork(long D, int N, long[] horseStartLoc, long[] horseSpeed)
        {
            double time = 0;
            for (int i = 0; i < N; i++)
            {
                long dis = D - horseStartLoc[i];
                time = Math.Max(time, (1.0 * dis) / horseSpeed[i]);
            }

            double speed = D / time;
            return speed.ToString();
        }
    }
}
