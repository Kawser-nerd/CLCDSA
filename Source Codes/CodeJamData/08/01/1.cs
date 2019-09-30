using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ08Qual1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int cases = int.Parse(lines[0]);
            int index=1;
            for (int i = 0; i < cases; i++)
            {
                Dictionary<string, int> labels = new Dictionary<string, int>();
                int labelCount = int.Parse(lines[index]);
                index++;
                for (int j = 0; j < labelCount; j++)
                {
                    labels[lines[index]] = j;
                    index++;
                }
                int queueCount = int.Parse(lines[index]);
                index++;
                int[] data = new int[queueCount];
                for (int j = 0; j < queueCount; j++)
                {
                    data[j] = labels[lines[index]];
                    index++;
                }
                output.Add(string.Format("Case #{0}: {1}", i+1, Solve(data, labelCount)));
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static int Solve(int[] data, int labelCount)
        {
            if (data.Length == 0)
                return 0;
            int[,] lp = new int[labelCount, data.Length + 1];
            lp[data[0], 0] = 5 * data.Length;
            for (int i = 1; i <= data.Length; i++)
            {
                for (int j = 0; j < labelCount; j++)
                {
                    int min = 5 * data.Length;
                    if (data[i - 1] != j)
                    {
                        for (int k = 0; k < labelCount; k++)
                        {
                            int trial = lp[k, i - 1] + (j == k ? 0 : 1);
                            if (trial < min)
                                min = trial;
                        }
                    }
                    lp[j, i] = min;
                }
            }
            int trueMin = int.MaxValue;
            for (int i = 0; i < labelCount; i++)
            {
                if (data[data.Length - 1] == i)
                    continue;
                if (lp[i, data.Length] < trueMin)
                    trueMin = lp[i, data.Length];
            }
            return trueMin;
        }
    }
}
