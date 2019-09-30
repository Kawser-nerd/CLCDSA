using System;
using System.Linq;
using System.Collections.Generic;
using CodeJam;

namespace Problems
{
    public class CandySplitting
    {
        public static void Main(string[] args)
        {
            ProblemParser.ParseProblem(@"D:\Chrome\Downloads\C-large.in");
            for (var problem = 0; problem < ProblemParser.Cases; problem++)
            {
                var input = ProblemParser.GetLines(2);
                var candies = new List<string>(input[1].Split(' ')).Select(Int64.Parse).ToList();
                candies.Sort();

                var bits = new int[30];
                foreach (var candy in candies) CountBits(bits, candy);
                if (!bits.All(bit => bit % 2 == 0)) ProblemParser.WriteSolution("NO");
                else ProblemParser.WriteSolution("" + (candies.Sum() - candies.First()));
            }
        }

        private static void CountBits(int[] bits, long candy)
        {
            var bit = 0;
            while(candy > 0)
            {
                if ((candy & 1) != 0) bits[bit]++;
                candy >>= 1;
                bit++;
            }
        }
    }
}
