/*
    State: Accepted
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Utility;

namespace GCJ2011Round1B
{
    public class B_RevengeOfHotDogs
    {
        public void Solve(TextReader input, TextWriter output)
        {
            var scanner = new StreamTokenizer(input);
            int testNum = scanner.NextInt();
            Random rnd = new Random();
            foreach (int caseId in Enumerable.Range(1, testNum))
            {
                int n = scanner.NextInt();
                double d = scanner.NextDouble();
                double[] p = new double[n];
                int[] v = new int[n];

                for (int i = 0; i < n; i++)
                {
                    p[i] = scanner.NextDouble();
                    v[i] = scanner.NextInt();
                }

                double left = 0, right = 1E12;
                while (right - left > 1E-8)
                {
                    double mid = (left + right) / 2;
                    bool success = true;
                    double bound = -1E10;
                    for (int i = 0; i < n; i++)
                        if (v[i] > 0)
                        {
                            bound = Math.Max(p[i] - mid, bound);
                            bound += d * v[i];
                            if (bound - d > p[i] + mid)
                            {
                                success = false;
                                break;
                            }
                        }
                    if (success)
                        right = mid;
                    else
                        left = mid;
                }
                
                output.WriteLine("Case #{0}: {1}", caseId, left);
            }
            output.Close();
        }

        static void Main(string[] args)
        {
            // new B_RevengeOfHotDogs().Solve(Console.In, Console.Out);
             new B_RevengeOfHotDogs().Solve(new StreamReader("B-small-attempt0.in"), new StreamWriter("B-small.out"));
            //new B_RevengeOfHotDogs().Solve(new StreamReader("B-large.in"), new StreamWriter("B-large.out"));
        }

    }
}
