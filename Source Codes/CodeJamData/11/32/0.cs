using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

static class ProgramA
{
    static void Main(string[] args)
    {
        using (var prob = new CodeJamProblem('b', ProblemType.Large, 0))
        {
            int tcase = prob.ReadLineInt32();
            for (int cases = 0; cases < tcase; cases++)
            {
                long[] a = prob.ReadInt64Array();
                long l = a[0];
                long t = a[1];
                long n = a[2];
                long c = a[3];
                long sum = 0;
                for (int i = 0; i < c; i++)
                {
                    a[i] = a[i + 4] * 2;
                    sum += a[i];
                }
                long left = t;
                int now = 0;
                long ans = 0;
                while (now < n && left >= a[now % c])
                {
                    left -= a[now % c];
                    ans += a[now % c];
                    now++;
                }
                if (now == n) {
                    prob.OutputCase(ans.ToString());
                    continue;
                }
                long[] ap = new long[11000 * 2];
                ans += left;
                ap[a[now % c] - left]++;
                long numleft = n - now - 1;
                for (int i = 0; i < c; i++)
                {
                    if (i < (numleft % c))
                        ap[a[(now + 1 + i) % c]] += numleft / c + 1;
                    else
                        ap[a[(now + 1 + i) % c]] += numleft / c;
                }
                for (int i = 21000; i >= 0; i--)
                {
                    if (ap[i] <= l)
                    {
                        l -= ap[i];
                        ans += ap[i] * i / 2;
                    }
                    else
                    {
                        ans += ap[i] * i - (l * i / 2);
                        l = 0;
                    }
                }
                prob.OutputCase(ans.ToString());
            }
        }
    }
}
