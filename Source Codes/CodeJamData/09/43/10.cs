using System.IO;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace GoogleComp
{
    class Program3
    {
        const string directory = @"C:/temp";
        const string question = "C";

        static void Main(string[] args)
        {
            //            string sample = String.Format("{0}/{1}-sample.in", directory, question);
            string small = String.Format("{0}/{1}-small-attempt1.in", directory, question);
            string large = String.Format("{0}/{1}-large.in", directory, question);

            string input = small;
            var reader = new InputReader(input);

            List<Object> results = new List<object>();
            int N = reader.readInt();
            Trace.WriteLine(string.Format("Computing output for {0} test cases", N));
            for (int i = 0; i < N; i++)
            {
                object result = performTest(reader);
                results.Add(result);
            }

            string output = String.Format("{0}.txt", input);
            PrintResult(output, results);
        }

        private static object performTest(InputReader reader)
        {
            var ints = reader.readInts();
            var n = ints[0];
            var k = ints[1];

            List<List<int>> prices = new List<List<int>>();
            for (int i = 0; i < n; i++)
            {
                prices.Add(new List<int>());

                int[] itemPrices = reader.readInts();
                prices[i].AddRange(itemPrices);
            }

            // work out price compatibility
            var incompatibility = new Dictionary<int, List<int>>();
            var incompatibilityCount = new Dictionary<int, int>();
            for (int i = 0; i < n; i++)
            {
                lineIncompatibility(prices, i, incompatibility, incompatibilityCount);
            }

            var items = from key in incompatibilityCount.Keys
                        orderby incompatibilityCount[key] descending
                        select key;

            // count graphs needed
            var graphs = new List<List<int>>();
            foreach (int key in items)
            {
                List<int> incomp = incompatibility[key];

                bool newNeeded = true;
                int j;
                for (j = 0; j < graphs.Count; j++)
                {
                    bool found = false;
                    for (int l = 0; l < incomp.Count; l++)
                    {
                        if (graphs[j].Contains(incomp[l]))
                        {
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        newNeeded = false;
                        break;
                    }
                }

                if (newNeeded)
                {
                    graphs.Add(new List<int>());
                    graphs.Last().Add(key);
                }
                else
                {
                    graphs[j].Add(key);
                }
            }

            return graphs.Count;
        }

        private static void lineIncompatibility(List<List<int>> prices, int index, Dictionary<int, List<int>> lookup, Dictionary<int, int> dictionary)
        {
            lookup.Add(index, new List<int>());
            int incompatibilities = 0;
            for (int i = 0; i < prices.Count; i++)
            {
                if (i != index)
                {
                    var differences = new List<int>();
                    for (int j = 0; j < prices[index].Count; j++)
                    {
                        differences.Add(prices[index][j] - prices[i][j]);
                    }

                    if (differences.Contains(0) || (differences.FindIndex(k => k > 0) >= 0 && differences.FindIndex(k => k < 0) >= 0))
                    {
                        incompatibilities++;
                        lookup[index].Add(i);
                    }
                }
            }
            dictionary[index] = incompatibilities;
        }

        private static void PrintResult(string output, IEnumerable<Object> results)
        {
            Trace.WriteLine(string.Format("Writing output file {0}", output));

            File.Delete(output);
            StreamWriter writer = File.CreateText(output);

            int testCase = 1;
            foreach (Object result in results)
            {
                string caseResult = string.Format("Case #{0}: {1}", testCase++, result.ToString());
                writer.WriteLine(caseResult);
                Trace.WriteLine(caseResult);
            }
            writer.Close();
        }

        private class InputReader
        {
            private int currentLine = 0;
            private string[] inputLines;

            public InputReader(string fileName)
            {
                Trace.WriteLine(string.Format("Reading input file {0}", fileName));
                inputLines = File.ReadAllLines(fileName);
            }

            public int readInt()
            {
                return Int32.Parse(readLine());
            }

            public int[] readInts()
            {
                string line = readLine();
                string[] numbers = line.Split(' ');
                int[] retVal = new int[numbers.Length];
                for (int i = 0; i < numbers.Length; i++)
                {
                    retVal[i] = Int32.Parse(numbers[i]);
                }

                return retVal;
            }

            public string readLine()
            {
                return inputLines[currentLine++];
            }

            public List<string> readLines(int numLines)
            {
                List<string> retVal = new List<string>();
                for (int i = 0; i < numLines; i++)
                {
                    retVal.Add(readLine());
                }

                return retVal;
            }
        }
    }
}
