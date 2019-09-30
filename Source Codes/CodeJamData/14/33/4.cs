using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace CodeJam
{
    internal class TestCase
    {
        public int Width;
        public int Height;
        public int Size;
    }

    internal class Program
    {
        private const string testFileName = "C-small-attempt3";

        public static IEnumerable<TestCase> ParseCases(TextReader reader)
        {
            var testCaseCount = int.Parse(reader.ReadLine());
            for (var i = 0; i < testCaseCount; i++)
            {
                var numbers = reader.ReadLine().Split().Select(int.Parse).ToArray();
                yield return new TestCase { Width = numbers[0], Height = numbers[1], Size = numbers[2] };
            }
        }

        private static long Solve(TestCase testCase)
        {
            if (testCase.Size <= 4) return testCase.Size; // nothing clever to do in this case
            if (testCase.Width <= 2 || testCase.Height <= 2) return testCase.Size;

            // whats the largest diamond we can fit.
            var minDimension = Math.Min(testCase.Width, testCase.Height);

            bool even = (minDimension % 2) == 0;
            
            var diamondEdge = (minDimension + 1) / 2;
            var diamondStones = GetDiamondStones(diamondEdge);
            var diamondArea = GetDiamondArea(diamondEdge);

            if (even)
            {
                diamondArea += diamondEdge * 2 - 1;
                diamondStones += 2;
            }

            if (diamondArea >= testCase.Size)
            {
                return GetOptimalCount(testCase.Size);
            }

            // stretch the "diamond" to the widest width
            var extraDimension = Math.Max(testCase.Width, testCase.Height) - minDimension;
            if (even) extraDimension += 1;

            var largestStretchedDiamond = diamondArea + extraDimension * minDimension;
            if (largestStretchedDiamond >= testCase.Size)
            {
                return StretchDiamond(diamondStones, diamondArea, diamondEdge, even, testCase.Size);
            }

            // otherwise fill in the gaps
            var stones = diamondStones + 2 * (extraDimension);
            return FillInCorners(stones, largestStretchedDiamond, diamondEdge, testCase.Size);
        }

        private static int GetDiamondArea(int diamondEdge)
        {
            return diamondEdge * diamondEdge + (diamondEdge - 1) * (diamondEdge - 1);
        }

        private static long FillInCorners(int stones, int size, int edge, int targetSize)
        {
            while (true)
            {
                for (var i = 0; i < 4; i++)
                {
                    stones++;
                    size += edge - 1;
                    if (size >= targetSize) return stones;
                }
                edge--;
            }
        }

        private static long StretchDiamond(int stones, int size, int edge, bool even, int targetSize)
        {
            while (true)
            {
                stones++;
                size += even ? edge : edge - 1;
                if (size >= targetSize) return stones;

                stones++;
                size += edge;
                if (size >= targetSize) return stones;
            }
        }

        private static long GetOptimalCount(int size)
        {
            // what's the largest diamond contained in this?
            return GrowDiamond(size);
        }

        private static int GrowDiamond( int targetSize)
        {
            var stones = 4;
            var currentSize = 5;
            var edge = 2;
            if (currentSize >= targetSize) return stones;

            while (true)
            {
                stones++;
                currentSize += edge - 1;
                if (currentSize >= targetSize) return stones;
                stones++;
                currentSize += edge;
                if (currentSize >= targetSize) return stones;
                stones++;
                currentSize += edge;
                if (currentSize >= targetSize) return stones;
                stones++;
                currentSize += edge;
                if (currentSize >= targetSize) return stones;

                edge++;
            }
        }

        private static int GetDiamondStones(int sqrt)
        {
            return 4 * sqrt - 4;
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