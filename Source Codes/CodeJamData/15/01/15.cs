using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _2008_1a;

namespace CodeJam
{
    class StandingOvation
    {
        public static void Run(CodeJamHelper helper)
        {
            var numTestCases = helper.ReadLineInt32();
            foreach (var n in Enumerable.Range(1, numTestCases))
            {
                var line = helper.ReadLine();
                var parts = line.Split(' ');
                var Smax = Int32.Parse(parts[0]);
                var answer = Solve(Smax, parts[1]);

                helper.OutputCase(answer);
            }
        }

        public static int Solve(int Smax, string people)
        {
            var counts = people.Select(c => c - '0').ToList();
            int maxDeficit = 0;
            int runningTotal = 0;
            for (int i = 0; i < counts.Count; ++i)
            {
                maxDeficit = Math.Max(maxDeficit, i - runningTotal);
                runningTotal += counts[i];
            }
            return maxDeficit;
        }
    }
}
