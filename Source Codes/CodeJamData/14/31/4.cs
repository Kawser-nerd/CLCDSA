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
            var wde = NextWord();
            var s = wde.Split('/');
            long p = long.Parse(s[0]);
            long q = long.Parse(s[1]);

            long g = gcd(p, q);
            p /= g;
            q /= g;

            if (!is_possible(q)) return "impossible";
            return solve(p, q);
        }

        public long gcd(long a, long b)
        {
            if (b == 0) return a;
            return gcd(b, a % b);
        }

        bool is_possible(long q)
        {
            while (q > 1)
            {
                if (q % 2 != 0)
                {
                    return false;
                }
                q = q / 2;
            }
            return true;
        }

        int solve(long p, long q)
        {
            if (p >= q) return 0;
            return 1+solve(p, q / 2);
        }
      

    }
}
