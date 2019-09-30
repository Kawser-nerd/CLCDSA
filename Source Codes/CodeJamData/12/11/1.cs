using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
// http://www.themissingdocs.net/downloads/TMD.Algo.0.0.5.0.zip
using TMD.Algo.Algorithms;
using TMD.Algo.Collections;
using TMD.Algo.Collections.Generic;

namespace GCJ12R1AQ1
{
    class Q1
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
                int A = int.Parse(bits[0]);
                int B = int.Parse(bits[1]);
                index++;
                double[] probs = new double[A];
                string[] bits2 = lines[index].Split(' ');
                for (int j = 0; j < A; j++)
                {
                    if (bits2[j].Length > 12)
                        bits2[j] = bits2[j].Substring(0, 12);
                    probs[j] = double.Parse(bits2[j]);
                }
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(A, B, probs)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(int A, int B, double[] probs)
        {
            // Start with the give up cost.
            double bestCost = 2.0 + B;
            double probAllRight = 1.0;
            for (int i = 0; i <= A; i++)
            {
                double expectValue = ((double)((A-i)+(B-i)+1))*probAllRight + 
                    (1.0-probAllRight)*(A-i+(B-i)+1+B+1);
                if (expectValue < bestCost)
                    bestCost = expectValue;
                if (i < A)
                    probAllRight *= probs[i];
            }
            return bestCost.ToString();
        }

    }
}
