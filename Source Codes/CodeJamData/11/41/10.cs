using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;

namespace GCJDevKit.Solvers
{
    class A : AbstractSolver
    {
        protected override object Solve(System.IO.StreamReader input)
        {
            int X = NextInt();
            int S = NextInt();
            int R = NextInt();
            double t = NextInt();
            int N = NextInt();

            var walkways = new List<Tuple<int, int>>();
            for (int i = 0; i < N; i++)
            {
                int length = -NextInt() + NextInt();
                X -= length;
                walkways.Add(Tuple.Create(length, NextInt()));
            }

            walkways.Add(Tuple.Create(X, 0));

            walkways.Sort((x, y) => x.Item2.CompareTo(y.Item2));

            double minTime = 0;

            foreach (var w in walkways)
            {
                double len = w.Item1;
                int speed = w.Item2;

                double time = len / (speed + S);
                if (t <= 0)
                {
                    //Console.WriteLine("Can't run. Will walk with speed "+(speed + S) +" for " + time );
                    minTime += time;
                }
                else if (len / (R + speed) <= t)
                {
                    //nsole.WriteLine("Can run full period " + (speed + R) + " for " + len / (R + speed));
                    minTime += len / (R + speed);
                    t -= (len / (R + speed));
                }
                else
                {
                    double distanceRunning = t * (R + speed);
                    minTime += t;
                    minTime += (len - distanceRunning) / (speed + S);

                    t = 0;
                }
                
            }


            return minTime;

        }
    }
}
