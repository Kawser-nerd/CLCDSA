using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Solvers
{
    class B : AbstractSolver
    {
        protected override object Solve(System.IO.StreamReader input)
        {
            int n = NextInt();
            int s = NextInt();
            int p = NextInt();

            int[] t = NextInts(n);

            int border = p + 2 * (Math.Max(0, p - 1));
            int surprisingBorder = p + 2 * (Math.Max(0, p - 2));

            return t.OrderByDescending(x => x).Count((x) =>
            {
                return x >= border || (x >= surprisingBorder && s-- > 0);
            });
        }
    }
}
