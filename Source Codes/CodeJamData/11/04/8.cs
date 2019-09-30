using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

static class ProgramB
{
    static void Main(string[] args)
    {
        using (var prob = new CodeJamProblem('d', ProblemType.Large, 0))
        {
            int t = prob.ReadLineInt32();
            for (int cases = 0; cases < t; cases++)
            {
                int n = prob.ReadLineInt32();
                int ans = 0;
                int[] f = prob.ReadInt32Array();

                for (int i = 0; i < n; i++)
                {
                    if (f[i] != i + 1)
                        ans++;
                }
                prob.OutputCase(ans.ToString() + ".000000");
            }
        }
    }
}
