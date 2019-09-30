using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Threading;

namespace ProblemC
{
    static class Program
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
            var values = Console.ReadLine().Split(' ').Select(long.Parse).ToList();
            return new Case
            {
                UserStallCount = values[0],
                UserNumber = values[1]
            };
        }

        static TValue GetValueOrDefault<TKey, TValue>(this SortedList<TKey, TValue> list, TKey key) =>
            list.TryGetValue(key, out var value) ? value : default(TValue);

        static (long maxSubrangeSize, long minSubrangeSize) DivideRange(long rangeSize) =>
            (rangeSize / 2, (rangeSize - 1) / 2);

        static Solution SolveCase(Case theCase)
        {
            var rangeCountsBySize = new SortedList<long, long>
            {
                [theCase.UserStallCount] = 1
            };
            var userOffset = theCase.UserNumber - 1;

            while (true)
            {
                var rangeSize = rangeCountsBySize.Keys.Last();
                var rangeCount = rangeCountsBySize.Values.Last();
                (var maxSubrangeSize, var minSubrangeSize) = DivideRange(rangeSize);

                if (userOffset < rangeCount)
                {
                    return new Solution
                    {
                        BestMaxEmptyStallCountToOneSide = maxSubrangeSize,
                        BestMinEmptyStallCountToOneSide = minSubrangeSize
                    };
                }

                userOffset -= rangeCount;
                rangeCountsBySize.Remove(rangeSize);
                rangeCountsBySize[maxSubrangeSize] = rangeCountsBySize.GetValueOrDefault(maxSubrangeSize) + rangeCount;
                rangeCountsBySize[minSubrangeSize] = rangeCountsBySize.GetValueOrDefault(minSubrangeSize) + rangeCount;
            }
        }

        static void WriteSolution(Solution solution)
        {
            Console.WriteLine($"{solution.BestMaxEmptyStallCountToOneSide} {solution.BestMinEmptyStallCountToOneSide}");
        }

        class Case
        {
            public long UserStallCount;
            public long UserNumber;
        }

        class Solution
        {
            public long BestMinEmptyStallCountToOneSide;
            public long BestMaxEmptyStallCountToOneSide;
        }
    }
}
