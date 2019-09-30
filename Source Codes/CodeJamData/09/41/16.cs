using System.IO;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace GoogleComp
{
    class Program1
    {
        const string directory = @"C:/temp";
        const string question = "A";

        static void Main(string[] args)
        {
            //var sample = String.Format("{0}/{1}-sample.in", directory, question);
            //var small = String.Format("{0}/{1}-small-attempt0.in", directory, question);
            var large = String.Format("{0}/{1}-large.in", directory, question);

            var input = large;
            var reader = new InputReader(input);

            var results = new List<object>();
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
            var N = reader.readInt();

            var lastOnes = new List<int>();

            for (int i = 0; i < N; i++)
            {
                var line = reader.readLine();
                lastOnes.Add(line.LastIndexOf("1"));
            }

            return steps(lastOnes);
        }

        private static int steps(List<int> items)
        {
            bool swapped;
            var count = 0;

            do
            {
                swapped = false;
                for (int i = 0; i < items.Count - 1; i++)
                {
                    if (items[i] > i)
                    {
                        // find first item to move up
                        var minIndex = i;
                        var index = items.FindIndex(i + 1, v => v <= minIndex);

                        count += index - i;

                        // construct new sequence
                        var item = items[index];
                        items.RemoveAt(index);
                        items.Insert(i, item);

                        swapped = true;
                        break;
                    }
                }
            } while (swapped);

            return count;
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
