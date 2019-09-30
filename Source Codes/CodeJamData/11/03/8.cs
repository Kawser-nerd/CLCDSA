using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

static class ProgramB
{
    static void Main(string[] args)
    {
        using (var prob = new CodeJamProblem('c', ProblemType.Large, 0))
        {
            int t = prob.ReadLineInt32();
            for (int cases = 0; cases < t; cases++)
            {
                int n = prob.ReadLineInt32();
                int ans = 0;
                int[] f = prob.ReadInt32Array();

                int min = 10000000;
                int sum = 0;
                foreach (int x in f)
                {
                    ans = (ans ^ x);
                    sum += x;
                    if (min > x)
                        min = x;
                }
                if (ans != 0)
                    prob.OutputCase("NO");
                else
                    prob.OutputCase(sum-min);
            }
        }
    }
}
