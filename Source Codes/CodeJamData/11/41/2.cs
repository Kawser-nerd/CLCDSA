/*
    State: Accepted
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Utility;

namespace GCJ2011Round2
{
    public class A_AirportWalkways
    {

        public void Solve(TextReader input, TextWriter output)
        {
            var scanner = new StreamTokenizer(input);
            int testNum = scanner.NextInt();
            foreach (int caseId in Enumerable.Range(1, testNum))
            {
                
                int x = scanner.NextInt();
                int s = scanner.NextInt();
                int r = scanner.NextInt();
                double t = scanner.NextInt();
                int n = scanner.NextInt();
                Tuple<int, int>[] a = new Tuple<int, int>[n + 1];
                for (int i = 0; i < n; i++)
                {
                         int b = scanner.NextInt();
                         int e = scanner.NextInt();
                         int w = scanner.NextInt();
                         x -= e - b;
                         a[i] = Tuple.Create(s + w, e - b);
                }
                a[n] = Tuple.Create(s, x);
                int d = r - s;
                double answer = 0;
                foreach (var p in a.OrderBy(p => p.Item1))
                {
                    double l = p.Item2;
                    double v = p.Item1;
                    double ct = Math.Min(l / (d + v), t);
                    answer += l / v - d / v * ct;
                    t -= ct;
                }
                output.WriteLine("Case #{0}: {1:F10}", caseId, answer);
            }
            output.Close();
        }

        static void Main(string[] args)
        {
       //       new A_AirportWalkways().Solve(Console.In, Console.Out);
          //  new A_AirportWalkways().Solve(new StreamReader("A-small-attempt0.in"), new StreamWriter("A-small.out"));
           new A_AirportWalkways().Solve(new StreamReader("A-large.in"), new StreamWriter("A-large.out"));
        }
    }
}
