using System.Collections.Generic;
using System.IO;
using System.Linq;

internal class TestCase
{
    public long DiscCapacity { get; set; }
    public long[] FileSizes { get; set; }
}

class Program
{
    private const string filename = "A-large";

    private static long Solve(TestCase testCase)
    {
        var sorted = testCase.FileSizes.OrderByDescending(i => i).ToList();

        long discCount = 0;
        while (sorted.Count > 0)
        {
            discCount++;

            var firstFile = sorted[0];
            sorted.RemoveAt(0);

            var remainingCapacity = testCase.DiscCapacity - firstFile;
            var secondFileIndex = sorted.FindIndex(i => i <= remainingCapacity);

            if (secondFileIndex >= 0)
                sorted.RemoveAt(secondFileIndex);
        }
        return discCount;
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
            var capacity = long.Parse(reader.ReadLine().Split()[1]);
            var fileSizes = reader.ReadLine().Split().Select(long.Parse).ToArray();
            yield return new TestCase {DiscCapacity = capacity, FileSizes = fileSizes};
        }
    }
}