using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Dancing
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCases = int.Parse(Console.ReadLine());
            for (int i = 1; i <= testCases; i++)
                new Program().Solve(i);
        }

        void Solve(int testCase)
        {
            var inputs = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            var suprising = inputs[1];
            var p = inputs[2];
            var scores = inputs.Skip(3).ToArray();

            int ok, couldBe;

            if (p > 1)
            {
                ok = scores.Count(s => s >= 3 * p - 2);
                couldBe = scores.Count(s => s >= 3 * p - 4) - ok;
            }
            else
            {
                ok = scores.Count(s => s >= p);
                couldBe = 0;
            }

            Console.WriteLine("Case #{0}: {1}", testCase, ok + (int)Math.Min(couldBe, suprising));            
        }
    }
}
