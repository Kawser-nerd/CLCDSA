/*
    State: Accepted
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Utility;

namespace GCJ2010QualRound
{
    public class B_PickingUpChicks
    {
        const int Modulus = 100003;
        public void Solve(TextReader input, TextWriter output)
        {
            var scanner = new StreamTokenizer(input);
            int testNum = scanner.NextInt();
            Random rnd = new Random();
            foreach (int caseId in Enumerable.Range(1, testNum))
            {
                int n = scanner.NextInt();
                int k = scanner.NextInt();
                int b = scanner.NextInt();
                int t = scanner.NextInt();
                var x = Enumerable.Range(0, n).Select(i => scanner.NextInt()).ToArray();
                var v = Enumerable.Range(0, n).Select(i => scanner.NextInt()).ToArray();
                int answer = 0;
                for (int i = n - 1, j = n - 1; i >= 0 && k > 0; i--)
                {
                    if (x[i] + v[i] * t >= b)
                    {
                        k--;
                        answer += j - i;
                        j--;
                    }
                }
                if (k > 0)
                    output.WriteLine("Case #{0}: {1}", caseId, "IMPOSSIBLE");
                else 
                    output.WriteLine("Case #{0}: {1}", caseId, answer);

            }
            output.Close();
        }

        static void Main(string[] args)
        {
            new B_PickingUpChicks().Solve(Console.In, Console.Out);
            new B_PickingUpChicks().Solve(new StreamReader("B-small-attempt0.in"), new StreamWriter("B-small.out"));
            new B_PickingUpChicks().Solve(new StreamReader("B-large.in"), new StreamWriter("B-large.out"));
        }

    }
}
