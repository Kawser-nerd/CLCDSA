using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

static class ProgramA
{
    static void Main(string[] args)
    {
        using (var prob = new CodeJamProblem('a', ProblemType.Large, 0))
        {
            int t = prob.ReadLineInt32();
            for (int cases = 0; cases < t; cases++)
            {
                string[] cur = prob.ReadParts();
                int n = int.Parse(cur[0]);
                for (int i = 0; i < n; i++)
                {
                    if (cur[2 * i + 1].Equals("O"))
                        cur[2 * i + 1] = "0";
                    else
                        cur[2 * i + 1] = "1";
                }
                int[] time = new int[2];
                int[] last = new int[2] {1, 1};
                for (int i = 0; i < n; i++)
                {
                    int x = int.Parse(cur[2 * i + 1]);
                    int p = int.Parse(cur[2 * i + 2]);
                    time[x] += Math.Abs(p - last[x])+1;
                    if (time[x] < time[1-x]+1)
                        time[x] = time[1-x]+1;
                    last[x] = p;
                }
                prob.OutputCase(Math.Max(time[0], time[1]));
            }
        }
    }
}
