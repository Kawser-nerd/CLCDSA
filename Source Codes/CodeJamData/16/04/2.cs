using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;

namespace Fractiles
{
    class Program
    {
        static void Main(string[] args)
        {
            var testName = args[0];

            using (var reader = new StreamReader($"{testName}.in"))
            using (var writer = new StreamWriter($"{testName}.out"))
            {
                var count = int.Parse(reader.ReadLine());
                for (var caseID = 1; caseID <= count; caseID++)
                {
                    var numbers = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();

                    var originalLength = numbers[0];
                    var complexity = numbers[1];
                    var cleanCount = numbers[2];

                    var tiles = TilesToClean(originalLength, complexity, cleanCount);

                    writer.WriteLine("Case #{0}: {1}", caseID, tiles == null ? "IMPOSSIBLE" : string.Join(" ", tiles));
                    writer.Flush();
                }
            }
        }

        private static long[] TilesToClean(long originalLength, long complexity, long cleanCount)
        {
            var tiles = new List<long>();

            for (var i = 0L; i < originalLength; i += complexity)
            {
                var n = 0L;
                for (var j = 0; j < complexity && i+j<originalLength; j++)
                {
                    n *= originalLength;
                    n += i + j;
                }
                tiles.Add(n + 1);
            }

            return tiles.Count > cleanCount ? null : tiles.ToArray();
        }
    }
}
