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
            return new Case
            {
                PackSize = values[1],
                GroupSizes = Console.ReadLine().Split(' ').Select(int.Parse).ToArray()
            };
        }

        static Solution SolveCase(Case theCase)
        {
            var groupModSizesLeft = theCase.GroupSizes.GroupBy(size => size % theCase.PackSize)
                .ToDictionary(grouping => grouping.Key, grouping => grouping.Count());

            var groupCountWithOnlyFreshPacks = 0;

            while (groupModSizesLeft.Values.Any(value => value > 0))
            {
                for (var divisibleGroupCount = 1; true; divisibleGroupCount++)
                {
                    if (TryRemoveGroupOfSize(divisibleGroupCount, ref groupModSizesLeft, 0, theCase.PackSize))
                    {
                        groupCountWithOnlyFreshPacks++;
                        break;
                    }

                    if (divisibleGroupCount > groupModSizesLeft.Values.Sum())
                    {
                        groupCountWithOnlyFreshPacks++;

                        return new Solution
                        {
                            GroupCountWithOnlyFreshPacks = groupCountWithOnlyFreshPacks
                        };
                    }
                }
            }

            return new Solution
            {
                GroupCountWithOnlyFreshPacks = groupCountWithOnlyFreshPacks
            };
        }

        static bool TryRemoveGroupOfSize(int divisibleGroupCount, ref Dictionary<int, int> groupModSizesLeft, int sizeModSum, int modBase)
        {
            if (divisibleGroupCount == 0)
            {
                return sizeModSum == 0;
            }

            foreach (var groupModSize in groupModSizesLeft.Keys)
            {
                if (groupModSizesLeft[groupModSize] > 0)
                {
                    var newGroupModSizesLeft = new Dictionary<int, int>(groupModSizesLeft);
                    newGroupModSizesLeft[groupModSize]--;
                    if (TryRemoveGroupOfSize(divisibleGroupCount - 1, ref newGroupModSizesLeft, (sizeModSum + modBase - groupModSize) % modBase, modBase))
                    {
                        groupModSizesLeft = newGroupModSizesLeft;
                        return true;
                    }
                }
            }

            return false;
        }

        static void WriteSolution(Solution solution)
        {
            Console.WriteLine(solution.GroupCountWithOnlyFreshPacks);
        }

        class Case
        {
            public int[] GroupSizes;
            public int PackSize;
        }

        class Solution
        {
            public int GroupCountWithOnlyFreshPacks;
        }
    }
}
