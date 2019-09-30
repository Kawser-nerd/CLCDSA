using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;

namespace GCJDevKit.Solvers
{
    public class A : AbstractSolver
    {
        protected override object Solve(System.IO.StreamReader input)
        {
            long b = NextLong();
            int n = NextInt();

            long[] nv = new long[37];
            for (int i = 0; i < n; i++)
            {
                nv[i] = NextLong();
            }

            Array.Sort(nv);
            Array.Reverse(nv);

            long left = 0;
            long right = b;

            while (right - 1 > left)
            {
                long middle = (left + right) / 2;
                if (CanFit(b, nv, middle))
                {
                    left = middle;
                }
                else
                {
                    right = middle;
                }
            }

            double max = 0;

            for (int i = -3; i <= 3; i++)
            {
                for (int j = 0; j <= 36; j++)
                {
                    max = Math.Max(max, tryItem(b, nv, right + i, j));
                }
            }

            foreach (var v in nv)
            {
                for (int i = -3; i <= 3; i++)
                {
                    for (int j = 0; j <= 36; j++)
                    {
                        max = Math.Max(max, tryItem(b, nv, v + i, j));
                    }
                }
            }


            return max;
        }

        bool CanFit(long b, long[] values, long test)
        {

            foreach (long val in values)
            {
                if (val <= test)
                {
                    {
                        b -= test - val;
                    }
                }
            }

            return b > 0;
        }

        double tryItem(long b, long[] values, long test, int kick)
        {

            List<long> bets = new List<long>();

            long totalBets = 0;

            foreach (long val in values)
            {
                if (val <= test)
                {
                    if (kick == 0 || val == 0)
                    {
                        bets.Add(test - val);
                        b -= test - val;
                        totalBets += test - val;
                    }
                    else
                    {
                        b -= test - val + 1;
                        kick--;
                        totalBets += test - val + 1;
                    }
                }
            }

            if (b < 0)
            {
                return 0;
            }

            double result = -totalBets;

            foreach (long bet in bets)
            {
                result += (double)(bet * 36) / (double)bets.Count;
            }

            return result;
        }

    }
}
