using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace B
{
    public class Program
    {
        public static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: A.exe <input file> <output file>");
                return;
            }
            using (var textReader = File.OpenText(args[0]))
            {
                using (var textWriter = File.CreateText(args[1]))
                {
                    var testsCount = int.Parse(textReader.ReadLine().Trim());
                    for (int i = 0; i < testsCount; i++)
                        ProcessTestCase(i + 1, textReader, textWriter);
                }
            }
        }

        private static void ProcessTestCase(int testCaseNumber, TextReader reader, TextWriter writer)
        {
            var n = int.Parse(reader.ReadLine().Trim());
            var edges = new List<int>[n + 1];
            for (int i = 0; i < edges.Length; i++)
                edges[i] = new List<int>();
            for (int i = 0; i < n - 1; i++)
            {
                var line = reader.ReadLine().Trim().Split(' ').Select(int.Parse).ToArray();
                edges[line[0]].Add(line[1]);
                edges[line[1]].Add(line[0]);
            }
            int best = (int) 1e9;
            for (int i = 1; i <= n; i++)
                best = Math.Min(best, Solve(i, edges, new bool[n + 1]).Item1);
            
            writer.WriteLine("Case #{0}: {1}", testCaseNumber, best);
        }

        private static Tuple<int, int> Solve(int root, List<int>[] edges, bool[] used)
        {
            used[root] = true;
            var fromChilds = new List<Tuple<int, int>>();
            var diffs = new List<int>();
            int totalCount = 0;
            foreach (var v in edges[root])
            {
                if (used[v])
                    continue;
                var solveChild = Solve(v, edges, used);
                fromChilds.Add(solveChild);
                totalCount += solveChild.Item2;
                diffs.Add(solveChild.Item2 - solveChild.Item1);
            }
            if (fromChilds.Count == 0)
                return new Tuple<int, int>(0, totalCount + 1);
            if (fromChilds.Count == 1)
                return new Tuple<int, int>(fromChilds[0].Item2, totalCount + 1);
            var ordered = diffs.OrderByDescending(i => i).ToArray();
            return new Tuple<int, int>(totalCount - ordered[0] - ordered[1], totalCount + 1);
        }
    }
}
