using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;

namespace GCJDevKit.Solvers
{
    class CCC : AbstractSolver
    {
        class Sum
        {
            public long item;
            public long sum;
            public Sum previousSum;

            public override string ToString()
            {
                if (previousSum.previousSum == null) return item.ToString();
                return previousSum.ToString() + " " + item;
            }
        }

        protected override object Solve(System.IO.StreamReader input)
        {
            int n = NextInt();
            int[] tab = NextInts(n);
            Array.Sort(tab);

            Dictionary<long, Sum> sums = new  Dictionary<long, Sum>();
            sums[0] = new Sum() { sum = 0, previousSum = null, item = 0 };


            foreach (int x in tab)
            {

                Dictionary<long, Sum> newSums = new Dictionary<long, Sum>();
                foreach (var old in sums)
                {
                    Sum oldSum = old.Value;
                    long sumSum =  oldSum.sum + x;
                    Sum s = new Sum() { previousSum = oldSum, item = x, sum = oldSum.sum + x };

                    if (sums.ContainsKey(sumSum))
                    {
                        return "\n" + sums[sumSum] + "\n" + s;
                    }
                    if (newSums.ContainsKey(sumSum))
                    {
                        return "\n" + newSums[sumSum] + "\n" + s;
                    }
                    newSums[sumSum] =  s;
                }

                foreach (var d in newSums)
                {
                    sums[d.Key] = d.Value;
                }
            }


            return "Impossible";
        }

    }
}
