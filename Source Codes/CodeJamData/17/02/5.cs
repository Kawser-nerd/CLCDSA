using System;
using System.Globalization;
using System.Linq;
using System.Threading;

namespace ProblemB
{
    class Program
    {
        static long GetFirstNumberStartingWith(string firstDigits, int digitCount) =>
            long.Parse(firstDigits + new string('0', digitCount - firstDigits.Length));

        static long GetLastTidyNumber(long lastNumber)
        {
            var lastNumberString = lastNumber.ToString();
            for (var digitIndex = 1; digitIndex < lastNumberString.Length; digitIndex++)
            {
                if (lastNumberString[digitIndex] < lastNumberString[digitIndex - 1])
                {
                    return GetLastTidyNumber(
                        GetFirstNumberStartingWith(lastNumberString.Substring(0, digitIndex), lastNumberString.Length) - 1);
                }
            }
            return lastNumber;
        }

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
                LastNumber = long.Parse(Console.ReadLine())
            };
        }

        static Solution SolveCase(Case theCase)
        {
            return new Solution
            {
                LastTidyNumber = GetLastTidyNumber(theCase.LastNumber)
            };
        }

        static void WriteSolution(Solution solution)
        {
            Console.WriteLine(solution.LastTidyNumber);
        }

        class Case
        {
            public long LastNumber;
        }

        class Solution
        {
            public long LastTidyNumber;
        }
    }
}
