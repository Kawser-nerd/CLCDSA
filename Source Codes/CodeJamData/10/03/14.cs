using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
// http://www.themissingdocs.net/downloads/TMD.Algo.0.0.4.0.zip
using TMD.Algo.Algorithms;
using TMD.Algo.Collections;

namespace GCJ10QRQ3
{
    class Q3
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int cases = int.Parse(lines[0]);
            int index = 1;
            for (int i = 0; i < cases; i++)
            {
                int[] values = lines[index].Split(' ').Select(int.Parse).ToArray();
                index++;
                int R = values[0];
                int k = values[1];
                int N = values[2];
                int[] groups = lines[index].Split(' ').Select(int.Parse).ToArray();
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(R, k, groups)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static long Solve(int runs, int rcSize, int[] groups)
        {
            Dictionary<int, int> offsetTotals = new Dictionary<int, int>();
            Dictionary<int, int> offsetsSeen = new Dictionary<int, int>();
            List<int> offsets = new List<int>();
            int curOffset = 0;
            while (true)
            {
                int total = 0;
                int lastOffset = curOffset;
                if (offsetsSeen.ContainsKey(lastOffset))
                {
                    break;
                }
                if (offsets.Count >= runs)
                    break;
                for (int i = 0; i < groups.Length; i++)
                {
                    int next = groups[(curOffset + i) % groups.Length];
                    if (total + next > rcSize)
                    {
                        curOffset = (curOffset + i) % groups.Length;
                        break;
                    }
                    total += next;
                }
                offsets.Add(lastOffset);
                offsetTotals[lastOffset] = total;
                offsetsSeen[lastOffset] = offsets.Count - 1;
            }
            long totalSoFar = 0;
            for (int i = 0; i < offsets.Count; i++)
            {
                totalSoFar += offsetTotals[offsets[i]];
            }
            if (offsets.Count >= runs)
                return totalSoFar;
            int curPos = offsetsSeen[curOffset];
            long partTotal = 0;
            for (int i = curPos; i < offsets.Count; i++)
            {
                partTotal += offsetTotals[offsets[i]];
            }
            int length = offsets.Count - curPos;
            long sum = totalSoFar + ((long)((runs - offsets.Count) / length) * partTotal);
            int leftOvers = (runs - offsets.Count) % length;
            for (int i = curPos; i < curPos + leftOvers; i++)
            {
                sum += offsetTotals[offsets[i]];
            }
            return sum;
        }
    }
}
