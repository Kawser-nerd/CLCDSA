using System.IO;
using System.Linq;

namespace Problem1A
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
                for (var caseId = 1; caseId <= count; caseId++)
                {
                    var splitLine = reader.ReadLine().Split(' ');

                    var pancakes = splitLine[0];
                    var flipperSize = int.Parse(splitLine[1]);

                    var flips = new Flipper(flipperSize).CountFlips(pancakes);

                    writer.WriteLine("Case #{0}: {1}", caseId, flips?.ToString() ?? "IMPOSSIBLE");
                    writer.Flush();
                }
            }
        }
    }
}
