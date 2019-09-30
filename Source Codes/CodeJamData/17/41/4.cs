using System;
using System.IO;
using System.Linq;

namespace Round2ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            var inFile = args[0];
            var outFile = Path.ChangeExtension(inFile, ".out");

            using (var reader = new StreamReader(inFile))
            using (var writer = new StreamWriter(outFile))
            {
                var count = int.Parse(reader.ReadLine());
                for (var caseId = 1; caseId <= count; caseId++)
                {
                    var line = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();

                    var p = line[1];

                    var g = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();

                    var result = GetResult(p, g);

                    writer.WriteLine("Case #{0}: {1}", caseId, result);
                    writer.Flush();
                }
            }
        }

        private static int GetResult(int p, int[] g)
        {
            switch (p)
            {
                case 2:
                    return g.Count(x => x % 2 == 0) + (g.Count(x => x % 2 == 1) + 1) / 2;

                case 3:
                    {
                        var ones = g.Count(x => x % 3 == 1);
                        var twos = g.Count(x => x % 3 == 2);
                        var threes = g.Count(x => x % 3 == 0);
                        var pairs = Math.Min(twos, ones);
                        var result = threes + pairs;
                        result += (Math.Abs(ones - twos) + 2) / 3;
                        return result;
                    }

                case 4:
                    {
                        var ones = g.Count(x => x % 4 == 1);
                        var twos = g.Count(x => x % 4 == 2);
                        var threes = g.Count(x => x % 4 == 3);
                        var fours = g.Count(x => x % 4 == 0);

                        var otpairs = Math.Min(ones, threes);
                        var result = fours + twos / 2 + otpairs;

                        threes -= otpairs;
                        ones -= otpairs;
                        twos %= 2;

                        result += (threes + ones) / 4;

                        if ((threes + ones) % 4 != 0 || twos != 0)
                        {
                            result++;
                        }

                        return result;
                    }
            }

            throw new NotImplementedException();
        }
    }
}
