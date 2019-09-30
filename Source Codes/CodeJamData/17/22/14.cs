using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Threading;

using IharBury.Algorithms;
using System.Text;

namespace ProblemB
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
                TotalCount = values[0],
                ColorCounts = new Dictionary<Color, int>
                {
                    [Color.Red] = values[1],
                    [Color.Orange] = values[2],
                    [Color.Yellow] = values[3],
                    [Color.Green] = values[4],
                    [Color.Blue] = values[5],
                    [Color.Violet] = values[6]
                }
            };
        }

        static readonly Color[] MonoColors = { Color.Blue, Color.Yellow, Color.Red };

        static bool IsMonoColor(Color color) => MonoColors.Contains(color);

        static Solution SolveCase(Case theCase)
        {
            var arrangement = new List<Color>(theCase.TotalCount);
            var colorCountsLeft = new Dictionary<Color, int>(theCase.ColorCounts);
            Color? firstColor = null;
            Color? lastColor = null;

            while (arrangement.Count < theCase.TotalCount)
            {
                var monoColorCountsLeftOrdered = colorCountsLeft
                    .Where(x => IsMonoColor(x.Key))
                    .OrderByDescending(x => x.Value)
                    .ThenByDescending(x => x.Key == firstColor)
                    .Select(x => x.Key);

                var bestColor = monoColorCountsLeftOrdered.Where(color => color != lastColor).First();
                if (colorCountsLeft[bestColor] == 0)
                    return new Solution();

                arrangement.Add(bestColor);
                colorCountsLeft[bestColor]--;
                lastColor = bestColor;
                if (firstColor == null)
                    firstColor = bestColor;
            }

            if (arrangement[0] == arrangement[theCase.TotalCount - 1])
                return new Solution();

            var solution = new Solution
            {
                Arrangement = arrangement
            };
            return solution;
        }

        static char GetColorCode(Color color)
        {
            switch (color)
            {
                case Color.Blue:
                    return 'B';
                case Color.Green:
                    return 'G';
                case Color.Orange:
                    return 'O';
                case Color.Red:
                    return 'R';
                case Color.Violet:
                    return 'V';
                case Color.Yellow:
                    return 'Y';
                default:
                    throw new InvalidOperationException();
            }
        }

        static void WriteSolution(Solution solution)
        {
            Console.WriteLine(solution.Arrangement == null
                ? "IMPOSSIBLE"
                : new string(solution.Arrangement.Select(GetColorCode).ToArray()));
        }

        class Case
        {
            public int TotalCount;
            public IDictionary<Color, int> ColorCounts;
        }

        enum Color
        {
            Red,
            Orange,
            Yellow,
            Green,
            Blue,
            Violet
        }

        class Solution
        {
            public IReadOnlyList<Color> Arrangement;
        }
    }
}
