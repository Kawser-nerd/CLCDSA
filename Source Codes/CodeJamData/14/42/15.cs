using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

internal class TestCase
{
    public long[] Sequence { get; set; }
}

class Program
{
    private const string filename = "B-large";

    private static long Solve(TestCase testCase)
    {
        var sequence = testCase.Sequence.ToList();

        long swaps = 0;
        while (sequence.Count > 0)
        {
            var minIndex = MinIndex(sequence);

            var minSwaps = Math.Min(minIndex, sequence.Count - 1 - minIndex);
            swaps += minSwaps;
            sequence.RemoveAt(minIndex);
        }

        return swaps;
    }

    private static int MinIndex(List<long> sequence)
    {
        long min = int.MaxValue;
        int minIndex = -1;

        for (var i = 0; i < sequence.Count; i++)
        {
            if (sequence[i] < min)
            {
                min = sequence[i];
                minIndex = i;
            }
        }

        return minIndex;
    }

    static void Main(string[] args)
    {
        TestCase[] testCases;
        using (var reader = new StreamReader(filename + ".in"))
        {
            testCases = ReadTestCases(reader).ToArray();
        }

        using (var writer = new StreamWriter(filename + ".out"))
        {
            for (var testCaseIndex = 0; testCaseIndex < testCases.Length; testCaseIndex++)
            {
                var result = Solve(testCases[testCaseIndex]);
                writer.WriteLine("Case #{0}: {1}", testCaseIndex + 1, result);
            }
        }
    }

    private static IEnumerable<TestCase> ReadTestCases(StreamReader reader)
    {
        var testCaseCount = int.Parse(reader.ReadLine());
        for (var i = 0; i < testCaseCount; i++)
        {
            reader.ReadLine();
            yield return new TestCase() {Sequence = reader.ReadLine().Split().Select(long.Parse).ToArray()};
        }
    }
}