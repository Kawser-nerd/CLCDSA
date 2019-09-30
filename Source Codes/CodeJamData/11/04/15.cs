using System;
using System.Linq;
using System.Collections.Generic;
using CodeJam;

namespace Problems
{
    public class GoroSort
    {
        public static void Main(string[] args)
        {
            ProblemParser.ParseProblem(@"D:\Chrome\Downloads\D-large.in");
            for (var problem = 0; problem < ProblemParser.Cases; problem++)
            {
                var input = ProblemParser.GetLines(2);
                var array = new List<string>(input[1].Split(' ')).Select(Int64.Parse).ToList();
                var copy = new List<string>(input[1].Split(' ')).Select(Int64.Parse).ToList();
                copy.Sort();
                ProblemParser.WriteSolution(array.Where((t, i) => t != copy[i]).Count() + ".000000");
            }
        }
    }
}
