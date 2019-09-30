using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace CodeJam
{

    class Solver
    {
        struct hiker
        {
            public double p;
            public int speed;
        }

        struct arrival
        {
            public long time;
            public long crosses;
        }

        List<arrival> arrivalTimes = new List<arrival>();
        string solveCase(int[][] input)
        {
            List<hiker> hikers = new List<hiker>();
            for (int i = 1; i < input.Length; i++)
            {
                var line = input[i];
                int p = line[0];
                int h = line[1];
                int m = line[2];
                for (int j = 0; j < h; j++)
                {
                    hikers.Add(new hiker { p = p, speed = m + j });
                }
            }

            long minCrosses = long.MaxValue;
            for (int i = 0; i < hikers.Count; i++)
            {
                var hiker = hikers[i];
                double time2finish = ((double)hiker.speed / 360 * (360 - hiker.p));
                long crosses = 0;
                for (int j = 0; j < hikers.Count; j++)
                {
                    if (i == j)
                        continue;
                    crosses += getCrosses(hikers[j], time2finish);
                    if (crosses >= minCrosses)
                        break;
                }
                if (minCrosses > crosses)
                    minCrosses = crosses;
            }
            return minCrosses + "";
        }

        private long getCrosses(hiker hiker, double time2finish)
        {
            double time2finishFirst = (double)hiker.speed / 360 * (360 - hiker.p);
            if (time2finish <= time2finishFirst)
                return 1;

            time2finish = time2finish - time2finishFirst;

            long fullTurns = (long)(time2finish / hiker.speed);
            double remainTime = (double)time2finish % hiker.speed;
            if (remainTime == 0)
                fullTurns++;
            return fullTurns;
        }


        public string Solve(string input)
        {
            string[] lines = input.Trim().Split('\n').Select(l => l.TrimEnd('\r')).ToArray();

            StringBuilder sb = new StringBuilder();
            int nbCases = Convert.ToInt32(lines[0]);
            int iLine = 1;
            for (int i = 0; i < nbCases; i++)
            {
                //Console.WriteLine("Case: " + i);

                string[] lineParts = lines[iLine].Split(' ');
                int[] linePartsint = lineParts.Select(p => Convert.ToInt32(p)).ToArray();

                int caseLines = linePartsint[0];
                int[][] caseInput = new int[caseLines + 1][];
                caseInput[0] = linePartsint;

                for (var caseLine = 0; caseLine < caseLines; caseLine++)
                {
                    iLine++;
                    lineParts = lines[iLine].Split(' ');
                    linePartsint = lineParts.Select(p => Convert.ToInt32(p)).ToArray();
                    caseInput[caseLine + 1] = linePartsint;
                }
                string result = solveCase(caseInput);
                sb.AppendLine("Case #" + (i + 1) + ": " + result);
                iLine++;
            }
            return sb.ToString();
        }
    }

}


