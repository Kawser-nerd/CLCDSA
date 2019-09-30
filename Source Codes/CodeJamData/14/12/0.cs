using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

namespace ProblemB
{
    class Program
    {
        private static class InputParser
        {
            private static string ReadLine()
            {
                var lineStr = Console.ReadLine();
                if (string.IsNullOrEmpty(lineStr))
                    throw new Exception("Missing line");
                return lineStr;
            }

            private static IEnumerable<string> ReadLineFragments()
            {
                return ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            }

            private static int ParseIntFromStr(string str)
            {
                int result;
                if (!int.TryParse(str, out result))
                    throw new Exception(string.Format("Invalid string: {0}", str));
                return result;
            }

            public static int ReadLineInt()
            {
                var lineStr = ReadLine();

                return ParseIntFromStr(lineStr);
            }

            public static IEnumerable<int> ReadLineInts()
            {
                return ReadLineFragments().Select(ParseIntFromStr);
            }
        }




        static void Main(string[] args)
        {
            var testCases = InputParser.ReadLineInt();

            for (var test = 1; test <= testCases; ++test)
            {
                var n = InputParser.ReadLineInt();
                var edges = new List<int>[n];
                for (int i = 0; i < n; ++i)
                    edges[i] = new List<int>();

                for (int i = 0; i < n - 1; ++i)
                {
                    var edge = InputParser.ReadLineInts().ToArray();
                    var a = edge[0] - 1;
                    var b = edge[1] - 1;
                    edges[a].Add(b);
                    edges[b].Add(a);
                }

                int best = 0;
                for (int i = 0; i < n; ++i)
                {
                    var cost = Enumerable.Repeat(-1, n).ToArray();
                    Calculate(cost, edges, i);
                    best = Math.Max(cost[i], best);
                }
                Console.WriteLine("Case #{0}: {1}", test,  n-best);
            }
        }

        private static void Calculate(int[] cost, List<int>[] edges, int start)
        {
            cost[start] = 0;

            int maxCost = 0, bestEdge=-1;

            foreach (var edge in edges[start])
            {
                if (cost[edge] == 0)
                    continue;

                Calculate(cost, edges, edge);
                if (cost[edge] > maxCost)
                {
                    maxCost = cost[edge];
                    bestEdge = edge;
                }

            }
            int secondMaxCost = 0;
            foreach (var edge in edges[start])
            {
                if (cost[edge] == 0)
                    continue;
                if (edge == bestEdge)
                    continue;
                secondMaxCost = Math.Max(secondMaxCost, cost[edge]);
            }
            if (secondMaxCost > 0)
                cost[start] = 1 + maxCost + secondMaxCost;
            else
                cost[start] = 1;
        }
    }
}
