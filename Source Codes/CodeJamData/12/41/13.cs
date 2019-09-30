using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;

namespace GCJDevKit.Solvers
{
    class AALines : AbstractSolver
    {
        protected override object Solve(System.IO.StreamReader input)
        {
            int N = NextInt();

            Console.WriteLine("TEST");

            var d = new int[N];
            var l = new int[N];

            //pozycja linii z lewej ktora mozna zlapac.
            var s = new int[N];

            s[0] = 0;

            for (int i=0; i<N; i++)
            {
                d[i] = NextInt();
                l[i] = NextInt();
            }

            int D = NextInt();


            for (int i = 0; i < N; i++)
            {
                if (i > 0 && s[i] == 0) return "NO";
                int r = Math.Min(d[i] - s[i], l[i]);

                if (r + d[i] >= D)
                {

                    return "YES";
                }
                for (int j = i + 1; j < N; j++)
                {
                    if (s[j] == 0 && d[i] + r >= d[j])
                    {
                        s[j] = d[i];
                    }
                    if (d[i] + r < d[j]) break;
                }
            }
            return "NO";
        }

        
    }
}
