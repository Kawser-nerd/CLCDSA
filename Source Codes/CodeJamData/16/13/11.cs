using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;

namespace BFFs
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
                    var childCount = int.Parse(reader.ReadLine());
                    var bffs = reader.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

                    var largestCircle = GetLargestCircle(bffs);

                    writer.WriteLine("Case #{0}: {1}", caseId, largestCircle);
                    writer.Flush();
                }
            }
        }

        private static int GetLargestCircle(int[] bffs)
        {
            var subgraphs = FindSubgraphs(bffs);

            // two shapes can work - either a cycle, or a series of length 2 cycles with 1 or 2 chains leading in.

            var largestCycle = subgraphs.Max(s => s.Cycle.Length);
            var maxChains =
                subgraphs.Where(s => s.Cycle.Length == 2)
                    .Sum(s => s.Cycle.Length + s.Chains.OrderByDescending(c => c.MaxLength).Take(2).Sum(c => c.MaxLength));

            return Math.Max(largestCycle, maxChains);
        }


        class Subgraph
        {
            public int[] Cycle;
            public List<Chain> Chains = new List<Chain>();
        }

        class Chain
        {
            public int EndNode;
            public int MaxLength;
        }

        private static List<Subgraph> FindSubgraphs(int[] bffs)
        {
            var subgraphs = new List<Subgraph>();

            var indexes = new List<int>();
            for (var i = 0; i < bffs.Length; i++)
            {
                indexes.Clear();

                var bff = i;
                while (!indexes.Contains(bff))
                {
                    indexes.Add(bff);
                    bff = bffs[bff] - 1;
                }

                var cycleStartIndex = indexes.IndexOf(bff);

                var subgraph = subgraphs.FirstOrDefault(s => s.Cycle.Contains(bff));
                if (subgraph == null)
                {
                    subgraph = new Subgraph { Cycle = indexes.Skip(cycleStartIndex).ToArray() };
                    subgraphs.Add(subgraph);
                }

                if (cycleStartIndex >= 1)
                {
                    var endNode = indexes[cycleStartIndex];
                    var chain = subgraph.Chains.FirstOrDefault(c => c.EndNode == endNode);
                    if (chain == null)
                    {
                        chain = new Chain { EndNode = endNode };
                        subgraph.Chains.Add(chain);
                    }
                    chain.MaxLength = Math.Max(chain.MaxLength, cycleStartIndex);
                }
            }

            return subgraphs;
        }
    }
}
