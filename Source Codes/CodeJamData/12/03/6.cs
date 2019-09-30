using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class RecycledNumbers
    {
        private static NumbersCase[] ReadFile(string filepath)
        {
            string[] lines = File.ReadAllLines(filepath);
            int cases = int.Parse(lines[0]);
            var result = new NumbersCase[cases];
            for (int caseNo = 1; caseNo < lines.Length; caseNo++)
            {
                var items = lines[caseNo].Split(' ').Select(s => int.Parse(s)).ToArray();

                result[caseNo - 1] = new NumbersCase { A = items[0], B = items[1] };
            }
            return result;
        }

        private class NumbersCase
        {
            public int A;
            public int B;
        }

        public static void Main()
        {
            string inputSize = "large";
            string inputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\RecycledNumbers\" + inputSize + " input.txt";
            string outputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\RecycledNumbers\" + inputSize + " output.txt";

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

        private static int SolveCase(NumbersCase gCase)
        {
            int digits = gCase.A.ToString().Length;
            int[] powers = new []{0,1,2,3,4,5,6,7,8}.Select(i => (int)Math.Pow(10, i)).ToArray();
            int result = 0;

            var matchDict = new Dictionary<int, string>();
            for (int i = gCase.A; i <= gCase.B; i++)
            {
                if (matchDict.Count > 0)
                    matchDict.Clear();

                //Console.Write(i);
                for (int s = 1; s < digits; s++)
                {
                    int right = i % powers[s];
                    int left = i - right;
                    int j = right * powers[digits - s] + left / powers[s];
                    //Console.Write(":" + j);
                    if (j >= gCase.A && j > i && j <= gCase.B && !matchDict.ContainsKey(j))
                    {
                        result++;
                        matchDict[j] = "";
                        //Console.Write("*");
                    }
                }
                //Console.WriteLine();
            }

            return result;
        }
    }
}
