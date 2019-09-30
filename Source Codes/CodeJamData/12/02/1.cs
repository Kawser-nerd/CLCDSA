using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
// http://www.themissingdocs.net/downloads/TMD.Algo.0.0.4.0.zip
using TMD.Algo.Algorithms;
using TMD.Algo.Collections;

namespace GCJ12QRQ2
{
    class Q2
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int cases = int.Parse(lines[0]);
            int index = 1;
            for (int i = 0; i < cases; i++)
            {
                string[] bits = lines[index].Split(' ');
                int N = int.Parse(bits[0]);
                int S = int.Parse(bits[1]);
                int p = int.Parse(bits[2]);
                int[] scores = new int[N];
                for (int j=0; j < N; j++) {
                    scores[j] = int.Parse(bits[3+j]);
                }
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(N, S, p, scores)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(int N, int S, int p, int[] scores)
        {
            int total = 0;
            int available = 0;
            for (int i = 0; i < scores.Length; i++)
            {
                int lowest = scores[i]/3;
                int higherCount = scores[i] % 3;
                int highest = lowest + (higherCount > 0 ? 1 : 0);
                if (highest >= p)
                    total++;
                else if (higherCount != 1 && highest == p - 1)
                {
                    // Smallest score where we can do a 2 split is 2 itself.
                    if (scores[i] > 1)
                        available++;
                }
            }
            return (total + Math.Min(S, available)).ToString();
        }

    }
}
