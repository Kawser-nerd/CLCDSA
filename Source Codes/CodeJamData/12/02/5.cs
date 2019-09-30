using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class DancingWithTheGooglers
    {
        private static GooglerCase[] ReadFile(string filepath)
        {
            string[] lines = File.ReadAllLines(filepath);
            int cases = int.Parse(lines[0]);
            var result = new GooglerCase[cases];
            for (int caseNo = 1; caseNo < lines.Length; caseNo++)
            {
                var items = lines[caseNo].Split(' ').Select(s => int.Parse(s)).ToArray();

                result[caseNo - 1] = new GooglerCase { N = items[0], S = items[1], p = items[2], t = items.Where((t, i) => i > 2).ToArray() };
            }
            return result;
        }

        private class GooglerCase
        {
            public int N;
            public int S;
            public int p;
            public int[] t;
        }

        public static void Main()
        {
            string inputSize = "large";
            string inputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\DancingWithTheGooglers\"+inputSize+" input.txt";
            string outputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\DancingWithTheGooglers\" + inputSize + " output.txt";

            var cases = ReadFile(inputFilepath);

            var outputFile = File.CreateText(outputFilepath);

            int caseNo = 1;

            foreach (var gCase in cases)
            {
                string outputLine = string.Format("Case #{0}: {1}", caseNo++, SolveCase(gCase));
                Console.WriteLine(outputLine);
                outputFile.WriteLine(outputLine);
            }

            outputFile.Close();
        }

        private static int SolveCase(GooglerCase gCase)
        {
            int result = 0;
            int surprisingUnused = gCase.S;

            foreach (var t in gCase.t)
            {
                if (t >= gCase.p + 2 * Math.Max(gCase.p - 1, 0))
                    result++;
                else
                    if (surprisingUnused > 0 && t >= gCase.p + 2 * Math.Max(gCase.p - 2, 0))
                    {
                        result++;
                        surprisingUnused--;
                    }
            }

            return result;
        }
    }
}
