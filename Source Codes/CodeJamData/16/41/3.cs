using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Threading;

using IharBury.Algorithms;
using System.Text;

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
            var values = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            return new Case
            {
                N = values[0],
                R = values[1],
                P = values[2],
                S = values[3]
            };
        }

        static Solution SolveCase(Case theCase)
        {
            var solution = new Solution();
            var currentRound = new Dictionary<char, string> { { 'P', "P" }, { 'R', "R" }, { 'S', "S" } };
            for (var roundIndex = 0; roundIndex < theCase.N; roundIndex++)
            {
                currentRound = GetNextRound(currentRound);
            }
            foreach (var variant in currentRound.Values.OrderBy(x => x))
            {
                var counts = variant.GroupBy(x => x).ToDictionary(grouping => grouping.Key, grouping => grouping.Count());
                if (counts.GetValueOrDefault('P') != theCase.P)
                    continue;
                if (counts.GetValueOrDefault('S') != theCase.S)
                    continue;
                if (counts.GetValueOrDefault('R') != theCase.R)
                    continue;
                return new Solution { Result = variant };
            }
            return solution;
        }

        static Dictionary<char, string> GetNextRound(Dictionary<char, string> currentRound)
        {
            var result = new Dictionary<char, string>();
            var p1 = currentRound['P'] + currentRound['R'];
            var p2 = currentRound['R'] + currentRound['P'];
            result['P'] = string.CompareOrdinal(p1, p2) < 0 ? p1 : p2;
            var r1 = currentRound['R'] + currentRound['S'];
            var r2 = currentRound['S'] + currentRound['R'];
            result['R'] = string.CompareOrdinal(r1, r2) < 0 ? r1 : r2;
            var s1 = currentRound['P'] + currentRound['S'];
            var s2 = currentRound['S'] + currentRound['P'];
            result['S'] = string.CompareOrdinal(s1, s2) < 0 ? s1 : s2;
            return result;
        }

        static void WriteSolution(Solution solution)
        {
            Console.WriteLine(solution.Result ?? "IMPOSSIBLE");
        }

        class Case
        {
            public int N;
            public int R;
            public int P;
            public int S;
        }

        class Solution
        {
            public string Result;
        }
    }
}
