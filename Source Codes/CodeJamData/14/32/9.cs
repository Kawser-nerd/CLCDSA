using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    internal class TestCase
    {
        public string[] Cars;
    }

    internal class Pair
    {
        public char First { get; set; }
        public char Last { get; set; }
    }

    internal class Program
    {
        private const string testFileName = "B-large";
        private const int Base = 1000000007;

        public static IEnumerable<TestCase> ParseCases(TextReader reader)
        {
            var testCaseCount = int.Parse(reader.ReadLine());
            for (var i = 0; i < testCaseCount; i++)
            {
                var carCount = int.Parse(reader.ReadLine());
                var cars = reader.ReadLine().Split();
                yield return new TestCase { Cars = cars };
            }
        }

        private static long Solve(TestCase testCase)
        {
            // 3 types of cars
            // single letters: aaa
            // two letters: aabb
            // multiple letters aabcddd

            // simplify consecutive letters
            var withoutRuns = testCase.Cars.Select(RemoveConsecutive).ToArray();

            var singleLetters = withoutRuns.Where(c => c.Length == 1).Select(c => c[0]).ToArray();
            var hiddenLetters = withoutRuns.Where(c => c.Length > 2).SelectMany(c => c.Substring(1, c.Length - 2)).Distinct().ToArray();
            var pairs = withoutRuns.Where(c => c.Length > 1).Select(c => new Pair { First = c[0], Last = c[c.Length - 1] }).ToArray();

            // eliminate case 3 now
            if (pairs.Any(p => hiddenLetters.Contains(p.First) || hiddenLetters.Contains(p.Last)) || singleLetters.Any(hiddenLetters.Contains))
                return 0;

            // we know just have to find orderings for pairs and single letters.

            // check that all the pairs can be ordered successfully
            if (pairs.Select(p => p.First).Distinct().Count() != pairs.Count()
                || pairs.Select(p => p.Last).Distinct().Count() != pairs.Count())
                return 0;

            //check the groups that have an order imposed on them by the pairs
            var sortedPairs = GetFixedChains(pairs);
            if (sortedPairs == null)
                return 0;

            var singleLetterCounts = singleLetters.GroupBy(c => c, (key, values) => Tuple.Create(key, values.Count()));
            var lettersInChains = sortedPairs.SelectMany(p => p).SelectMany(p => new[] { p.First, p.Last }).Distinct();

            var independentSingleLetters = singleLetters.Except(lettersInChains).ToArray();

            // single letters can be in any order relative to each other
            long combinations = 1;
            foreach (var pair in singleLetterCounts)
            {
                combinations *= Factorial(pair.Item2);
                combinations %= Base;
            }

            // chains can be in any order relative to each other, and to the independent letters
            var independentBlockCount = independentSingleLetters.Count() + sortedPairs.Length;
            combinations *= Factorial(independentBlockCount);
            combinations %= Base;

            return combinations;
        }

        private static long Factorial(int x)
        {
            long fact = 1;
            while (x > 1)
            {
                fact *= x;
                fact %= Base;
                x--;
            }
            return fact;
        }

        private static Pair[][] GetFixedChains(Pair[] pairs)
        {
            var remainingPairs = pairs.ToList();
            var sorted = new List<Pair[]>();

            while (remainingPairs.Count > 0)
            {
                var chain = new List<Pair>();
                
                var current = remainingPairs[0];
                remainingPairs.RemoveAt(0);
                chain.Add(current);

                int index;
                
                var first = current;
                while ((index = remainingPairs.FindIndex(p => p.Last == first.First)) >= 0)
                {
                    first = remainingPairs[index];
                    remainingPairs.RemoveAt(index);
                    chain.Insert(0, first);
                }

                var last = current;
                while ((index = remainingPairs.FindIndex(p => p.First == last.Last)) >= 0)
                {
                    last = remainingPairs[index];
                    remainingPairs.RemoveAt(index);
                    chain.Add(last);
                }

                if (last.Last == first.First) return null;

                sorted.Add(chain.ToArray());
            }

            return sorted.ToArray();
        }

        private static string RemoveConsecutive(string arg)
        {
            var builder = new StringBuilder(arg.Length);
            char current = '\0';
            foreach (var c in arg)
            {
                if (c != current)
                {
                    builder.Append(c);
                    current = c;
                }
            }

            return builder.ToString();
        }

        private static void Main(string[] args)
        {
            TestCase[] cases;
            using (var reader = new StreamReader(testFileName + ".in"))
            using (var writer = new StreamWriter(testFileName + ".out"))
            {
                cases = ParseCases(reader).ToArray();

                for (int caseIndex = 0; caseIndex < cases.Length; caseIndex++)
                {
                    var testCase = cases[caseIndex];
                    var solution = Solve(testCase);

                    writer.WriteLine("Case #{0}: {1}", caseIndex + 1, solution);
                }
            }
        }
    }
}