using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Solvers
{
    class KubaB : AbstractSolver
    {
        int[,] solutions;

        int solve(int x, int y)
        {
            if (solutions[x, y] == -1)
            {
                solutions[x, y] = solveTemp(x, y);
            }
            return solutions[x, y];
        }
        int L, P, C;
        protected override object Solve(System.IO.StreamReader input)
        {
             L = NextInt();
             P = NextInt();
             C = NextInt();
            solutions = new int[P+1, P+1];
            for (int i = 0; i <= P;i++ )
                for (int j = 0; j <= P; j++)
                {
                    solutions[i, j] = -1;
                }
                return solveTemp(L, P);
        }

        private int solveTemp(int x, int y)
        {
            if (x * C >= y) return 0;
            int best = int.MaxValue;
            for (int i = x*C; i < y; i++)
            {
                best = Math.Min( best, Math.Max( solve(x, i) , solve(i, y)) + 1);
            }
            return best;
        }
    }
}
