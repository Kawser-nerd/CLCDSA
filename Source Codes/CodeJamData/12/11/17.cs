using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class ProblemA
    {
        static void Main(string[] args)
        {
            int testCases = int.Parse(Console.ReadLine());
            for (int i = 1; i <= testCases; i++)
                new ProblemA().Solve(i);
        }

        void Solve(int testCase)
        {
            var values = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var typed = values[0];
            var length = values[1];
            var togo = length - typed;
            var pcorrect = Console.ReadLine().Split(' ').Select(double.Parse).ToArray();

            var pcorrectUntil = new double[pcorrect.Length + 1];
            pcorrectUntil[0] = 1.0;
            for (int i = 1; i < pcorrectUntil.Length; i++)
                pcorrectUntil[i] = pcorrectUntil[i - 1] * pcorrect[i - 1];

            var best = (double)(length + 2);
            for (int i = 0; i <= typed; i++)
            {
                var P_ok = pcorrectUntil[typed - i];
                var P_not_ok = 1 - P_ok;
                var ex = P_ok * (i * 2 + togo + 1) + P_not_ok * (i * 2 + togo + 1 + length + 1);
                best = Math.Min(ex, best);
            }

            Console.WriteLine("Case #{0}: {1:0.0000000}", testCase, best);
        }
    }
}
