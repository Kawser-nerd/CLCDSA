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
            var values = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            var destinationDistance = values[0];
            var otherHorseCount = values[1];
            var otherHorses = new List<(int StartPosition, int MaxSpeed)>(otherHorseCount);
            for (var i = 0; i < otherHorseCount; i++)
            {
                var horseValues = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
                otherHorses.Add((horseValues[0], horseValues[1]));
            }
            return new Case
            {
                DestinationDistance = destinationDistance,
                OtherHorses = otherHorses
            };
        }

        static Solution SolveCase(Case theCase)
        {
            var otherHorseTimes = theCase.OtherHorses
                .Select(otherHorse => (theCase.DestinationDistance - otherHorse.StartPosition) / (double)otherHorse.MaxSpeed);
            var minTime = otherHorseTimes.Max();

            var solution = new Solution
            {
                MaxCruiseSpeed = theCase.DestinationDistance / minTime
            };
            return solution;
        }

        static void WriteSolution(Solution solution)
        {
            Console.WriteLine(solution.MaxCruiseSpeed);
        }

        class Case
        {
            public int DestinationDistance;
            public IReadOnlyList<(int StartPosition, int MaxSpeed)> OtherHorses;
        }

        class Solution
        {
            public double MaxCruiseSpeed;
        }
    }
}
