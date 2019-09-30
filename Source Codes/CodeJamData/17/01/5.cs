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
            var values = Console.ReadLine().Split(' ');
            return new Case
            {
                PancakeStates = values[0]
                    .Select(pancakeStateCode => pancakeStateCode == '+' ? PancakeState.HappyFace : PancakeState.Blank)
                    .ToArray(),
                FlipperSize = int.Parse(values[1])
            };
        }

        static Solution SolveCase(Case theCase)
        {
            var currentFlippingCount = 0;
            var doPancakesNeedFlippingStartingFromThem = new bool[theCase.PancakeStates.Length];
            doPancakesNeedFlippingStartingFromThem[0] = theCase.PancakeStates[0] == PancakeState.Blank;
            for (var pancakeIndex = 1; pancakeIndex < theCase.PancakeStates.Length; pancakeIndex++)
                doPancakesNeedFlippingStartingFromThem[pancakeIndex] =
                    theCase.PancakeStates[pancakeIndex] != theCase.PancakeStates[pancakeIndex - 1];

            for (
                var flippingStartIndex = 0;
                flippingStartIndex + theCase.FlipperSize <= theCase.PancakeStates.Length;
                flippingStartIndex++)
            {
                if (doPancakesNeedFlippingStartingFromThem[flippingStartIndex])
                {
                    currentFlippingCount++;
                    doPancakesNeedFlippingStartingFromThem[flippingStartIndex] = false;

                    var indexAfterFlippingEnd = flippingStartIndex + theCase.FlipperSize;
                    if (indexAfterFlippingEnd < theCase.PancakeStates.Length)
                        doPancakesNeedFlippingStartingFromThem[indexAfterFlippingEnd] =
                            !doPancakesNeedFlippingStartingFromThem[indexAfterFlippingEnd];
                }
            }

            return new Solution
            {
                MinFlippingCount = 
                    doPancakesNeedFlippingStartingFromThem.Any(
                            doesPancakeNeedFlippingStartingFormIt => doesPancakeNeedFlippingStartingFormIt) ?
                        (int?)null :
                        currentFlippingCount
            };
        }

        static void WriteSolution(Solution solution)
        {
            Console.WriteLine(solution.MinFlippingCount?.ToString() ?? "IMPOSSIBLE");
        }

        class Case
        {
            public int FlipperSize;
            public PancakeState[] PancakeStates;
        }

        enum PancakeState
        {
            HappyFace,
            Blank
        }

        class Solution
        {
            public int? MinFlippingCount;
        }
    }
}
