using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Threading;

using IharBury.Algorithms;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var caseCount = int.Parse(Console.ReadLine());
            var cases = Enumerable.Range(1, caseCount).Select(_ => ReadCase()).ToList();
            var solutions = cases
                //.AsParallel().AsOrdered()
                .Select(SolveCase).ToList();
            foreach (var caseNumber in Enumerable.Range(1, caseCount))
            {
                Console.Write("Case #{0}: ", caseNumber);
                WriteSolution(solutions[caseNumber - 1]);
            }
        }

        static Case ReadCase()
        {
            return new Case
            {
                Moods = Console.ReadLine()
            };
        }

        static Solution SolveCase(Case theCase)
        {
            var list = new LinkedList<char>(theCase.Moods);
            long score = 0;

            var current = list.First;
            while (current != null)
            {
                if (current.Previous == null)
                    current = current.Next;

                if (current.Value == current.Previous.Value)
                {
                    var toRemove1 = current.Previous;
                    var toRemove2 = current;
                    current = current.Next;
                    list.Remove(toRemove1);
                    list.Remove(toRemove2);
                    score += 10;
                }
                else
                {
                    current = current.Next;
                }
            }

            score += list.Count / 2 * 5;

            return new Solution
            {
                MaxScore = score
            };
        }

        static void WriteSolution(Solution solution)
        {
            Console.WriteLine(solution.MaxScore);
        }

        class Case
        {
            public string Moods;
        }

        class Solution
        {
            public long MaxScore;
        }
    }
}
