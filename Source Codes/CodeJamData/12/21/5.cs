using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;

namespace GCJDevKit.Solvers
{
    class AAA : AbstractSolver
    {
        protected override object Solve(System.IO.StreamReader input)
        {
            int n = NextInt();
            int[] tab = NextInts(n);

            int sumAll = 0;
            foreach (int x in tab) sumAll += x;

            double[] r = new double[tab.Length];
            for (int i = 0; i < tab.Length; i++)
            {
                r[i] = findOptimal(i, tab, sumAll)*100;
            }
            return String.Join(" ", r);
        }

        double findOptimal(int pos, int[] tab, int sum)
        {
            double left = 0;
            double right = 1;

            while (right - left > 0.000000001)
            {
                double middle = (left + right) / 2;
                if (isEnough(pos, tab, sum, middle))
                {
                    right = middle;
                }
                else
                {
                    left = middle;
                }
            }
            return left;
        }

        bool isEnough(int pos, int [] tab, int sum, double p)
        {
            double score = tab[pos] + sum * p;

            double totalScoreMissing = 0;

            for (int i = 0; i < tab.Length; i++) if (i != pos && tab[i] < score)
                {
                    totalScoreMissing += score - tab[i];
                }
            return totalScoreMissing + sum * p > sum;
        }

    }
}
