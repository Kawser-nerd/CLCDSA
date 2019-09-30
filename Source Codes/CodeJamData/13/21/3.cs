using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;

namespace GCJDevKit.Solvers
{
    class A : AbstractSolver
    {
        protected override object Solve(System.IO.StreamReader input)
        {
            int a = NextInt();
            int n = NextInt();

            int[] motes = NextInts(n);

            List<int> lista = new List<int>();
            lista.AddRange(motes);
            lista.Sort();

            return solve(a, lista);
        }

        private int solve(int a, List<int> lista)
        {
            while (lista.Count > 0 && lista[0] < a)
            {
                a = a + lista[0];
                lista.RemoveAt(0);
            }

            if (lista.Count == 0)
            {
                return 0;
            }

            if (a == 1) return lista.Count;

            return Math.Min(lista.Count, 1 + solve(2 * a - 1, lista));

        }



    }
}
