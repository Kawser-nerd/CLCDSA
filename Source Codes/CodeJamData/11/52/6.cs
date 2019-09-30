using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Diagnostics;
using System.Threading;

namespace GCJDevKit.Solvers
{
    class B : AbstractSolver
    {


        class Straight
        {
            public int lastElement;
            public int Length;
        }

        int[] elements;

        protected override object Solve(System.IO.StreamReader input)
        {
            int n = NextInt();
            if (n == 0) return 0;
            elements = NextInts(n);

            List<Straight> list = new List<Straight>();

            Array.Sort(elements);
            foreach (var e in elements)
            {
                Straight bestStraight = null;
                foreach (var straight in list)
                {

                    if (straight.lastElement == e - 1)
                    {
                        if (bestStraight == null)
                            bestStraight = straight;
                        else
                        {
                            if (bestStraight.Length > straight.Length)
                            {
                                bestStraight = straight;
                            }
                        }
                    }
                }
                if (bestStraight != null)
                {
                    bestStraight.lastElement = e;
                    bestStraight.Length++;
                }
                else
                {
                    list.Add(new Straight() { Length = 1, lastElement = e });
                }

                
            }
            int shortest = int.MaxValue;
            foreach (var stra in list)
            {
                if (stra.Length < shortest)
                {
                    shortest = stra.Length;
                }

            }

            return shortest;

                
        }
    }
}
