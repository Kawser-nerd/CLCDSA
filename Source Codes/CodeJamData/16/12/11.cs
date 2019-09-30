using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace RankAndFile
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
                    var dim = int.Parse(reader.ReadLine());
                    var rows = new int[2*dim-1][];
                    for (var i = 0; i < rows.Length; i++)
                    {
                        rows[i] = reader.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                    }

                    var missingRow = GetMissingRow(rows);

                    var result = string.Join(" ", missingRow);

                    writer.WriteLine("Case #{0}: {1}", caseId, result);
                    writer.Flush();
                }
            }
        }

        private static int[] GetMissingRow(int[][] rows)
        {
            return rows.SelectMany(r => r).GroupBy(r => r).Where(g => g.Count() % 2 == 1).Select(g => g.Key).OrderBy(i => i).ToArray();
        }
    }
}
