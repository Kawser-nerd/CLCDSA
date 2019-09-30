using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            const string inputFile = @"E:\Visual Studio Projects\Google Code Jam\cj2012\GoogleCodeJam1C\ProblemA\Input\A-large.in";
            const string outputFile = @"E:\Visual Studio Projects\Google Code Jam\cj2012\GoogleCodeJam1C\ProblemA\Output\Large.txt";

            var sr = new StreamReader(inputFile);
            var sw = new StreamWriter(outputFile);

            int testCases = int.Parse(sr.ReadLine());
            for (int i = 1; i <= testCases; i++)
            {
                var testCase = ProbA.ParseCase(sr);
                var result = "Case #" + i + ": " + testCase.SolveCase();
                sw.WriteLine(result);
            }
            sw.Flush();
            sw.Close();
        }
    }

    public class ProbA
    {
        public int N { get; set; }
        public List<List<int>> Inheritance { get; set; } 

        public static ProbA ParseCase(StreamReader sr)
        {
            var parameters =
                sr.ReadLine()
                .Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                .Select(s => int.Parse(s));

            var n = parameters.First();

            var inheritance = Enumerable.Range(0, n).Select(i => sr.ReadLine()
                                                                     .Split(" ".ToCharArray(),
                                                                            StringSplitOptions.RemoveEmptyEntries)
                                                                     .Select(s => int.Parse(s) - 1)
                                                                     .Skip(1)
                                                                     .ToList())
                .ToList();

            return new ProbA { N = n, Inheritance = inheritance };
        }

        public String SolveCase()
        {
            return Enumerable.Range(0, N).Any(i => IsDiamond(i, new HashSet<int>())) ? "Yes" : "No";
        }

        public bool IsDiamond(int index, HashSet<int> seen)
        {
            if (seen.Contains(index))
                return true;

            seen.Add(index);

            for (int i = 0; i < Inheritance[index].Count; i++)
            {
                var result = IsDiamond(Inheritance[index][i], seen);
                if (result)
                    return true;
            }
            return false;
        }
    }
}
