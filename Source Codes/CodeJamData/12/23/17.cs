using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class SubsetSum
    {
        private static SumCase[] ReadFile(string filepath)
        {
            string[] lines = File.ReadAllLines(filepath);
            int cases = int.Parse(lines[0]);
            var result = new SumCase[cases];
            for (int caseNo = 1; caseNo < lines.Length; caseNo++)
            {
                var items = lines[caseNo].Split(' ').Select(s => int.Parse(s)).ToArray();

                result[caseNo - 1] = new SumCase{ N = items[0], s = items.Where((i, index) => index > 0).ToArray() };
            }

            return result;
        }

        private class SumCase
        {
            public int N;
            public int[] s;
        }

        public static void Main()
        {
            string inputSize = "small";
            string inputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\SubsetSum\"+inputSize+" input.txt";
            string outputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\SubsetSum\" + inputSize + " output.txt";

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

        private static string SolveCase(SumCase gCase)
        {
            var inclusion = new int[20];
            int sumA = 0;
            int sumB = 0;
            while (true)
            {
                int i = 0;
                bool carry = true;
                while (carry)
                {
                    inclusion[i]++;
                    carry = false;
                    switch (inclusion[i])
                    {
                        case 1:
                            sumA += gCase.s[i];
                            break;
                        case 2:
                            sumB += gCase.s[i];
                            sumA -= gCase.s[i];
                            break;
                        case 3:
                            sumB -= gCase.s[i];
                            inclusion[i] = 0;
                            i++;
                            carry = true;
                            if (i >= 20)
                                return "Impossible";
                            break;
                    }
                }

                if (sumA == sumB)
                    return "\n" + string.Join(" ", gCase.s.Where((value, index) => inclusion[index] == 1).ToArray())
                        + "\n" + string.Join(" ", gCase.s.Where((value, index) => inclusion[index] == 2).ToArray());
            }
        }
    }
}
