using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;

namespace GCJDevKit.Solvers
{
    public class B : AbstractSolver
    {
        protected override object Solve(System.IO.StreamReader input)
        {
            int N = NextInt();
            long P = NextLong
                ();

            long N2 = 1L << N;

            if (P == (N2))
            {
                return (N2 - 1) + " " + (N2 - 1);
            }


            //return "worst position for 3, 5 is " + worst(3, 5) + " "
            // + "best position for 5 is "+ best(3, 5);

            return firstResult(N, P - 1) + " " + secondResult(N, P - 1);

        }

        long firstResult(int n, long p)
        {
            long left = 0; //must win
            long right = (1l << n) - 1; //could lose

            while (right - 1 > left)
            {
                long middle = (left + right) / 2;

                if (worst(n, middle) <= p)
                {
                    left = middle;
                }
                else
                {
                    right = middle;
                }
            }

            return left;
        }


        long secondResult(int n, long p)
        {
            long left = 0; //could win
            long right = (1L << n) - 1; //guaranteed to lose

            while (right - 1 > left)
            {
                long middle = (left + right) / 2;

                if (best(n, middle) <= p)
                {
                    left = middle;
                }
                else
                {
                    right = middle;
                }
            }

            return left;
        }


        long best(int n, long mine)
        {
            long z = (1L << (n) )- 1;
            return z - worst(n, z - mine);
        }

        //what is the worst possible place I can get?
        long worst(int n, long mine)
        {
            if (mine == 0)
            {
                return 0;
            }
            return (1L << (n - 1)) + worst(n - 1, (mine - 1) / 2);
        }


    }
}
