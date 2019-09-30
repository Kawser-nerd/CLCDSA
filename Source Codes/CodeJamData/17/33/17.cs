using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round2
{
    public class CoreTraining
    {
        public static IList<string> Solve(string[] inputLines)
        {
            var results = new List<string>();

            var tests = int.Parse(inputLines[0]);
            var testCases = new List<CoreTestCase>();
            int line = 1;
            for (int i = 0; i < tests; i++)
            {
                var lineTokens = inputLines[line++].Split(' ');
                var testCase = new CoreTestCase
                {
                    N = int.Parse(lineTokens[0]),
                    K = int.Parse(lineTokens[1])
                };
                testCase.U = decimal.Parse(inputLines[line++]);
                lineTokens = inputLines[line++].Split(' ');
                testCase.P = lineTokens.Select(decimal.Parse).ToArray();

                testCases.Add(testCase);
            }

            foreach (var testCase in testCases)
            {
                results.Add(Solve(testCase));
            }

            return results;
        }

//        private static string Solve(CoreTestCase testCase)
//        {
//            var p = testCase.P.OrderBy(value => value).ToArray();
//
//            while (testCase.U > 0)
//            {
//                int maxIndex = 0;
//
//                for (int i = 1; i < p.Length; i++)
//                {
//                    if (p[i] > p[0]) break;
//                    maxIndex = i;
//                }
//
//                int count = maxIndex + 1;
//                decimal difference;
//                if (maxIndex == p.Length - 1)
//                {
//                    difference = 1 - p[0];
//                }
//                else
//                {
//                    difference = p[maxIndex + 1] - p[0];
//                }
//
//                var maxAllocation = count * difference;
//
//                if (testCase.U >= maxAllocation)
//                {
//                    testCase.U -= maxAllocation;
//
//                    for (int i = 0; i <= maxIndex; i++)
//                    {
//                        p[i] += difference;
//                    }
//                }
//                else
//                {
//                    
//                }
//            }
//
//
//        }

        private static int MinIndex(decimal[] array)
        {
            var smallest = array[0];
            var index = 0;
            for (int i = 1; i < array.Length; i++)
            {
                if (array[i] < smallest)
                {
                    index = i;
                    smallest = array[i];
                }
            }

            return index;
        }

        private static string Solve(CoreTestCase testCase)
        {
            while (testCase.U > 0)
            {
                var smallestIndex = MinIndex(testCase.P);
                testCase.U -= 0.0001m;
                testCase.P[smallestIndex] += 0.0001m;
            }

            return testCase.P.Aggregate(1m, (v1, v2) => v1 * v2).ToString();
        }
    }

    class CoreTestCase
    {
        public int N { get; set; }
        public int K { get; set; }
        public decimal U { get; set; }
        public decimal[] P { get; set; }
    }
}
