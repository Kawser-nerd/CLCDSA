using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ09QRQ3
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int cases = int.Parse(lines[0]);
            int index = 1;
            for (int i = 0; i < cases; i++)
            {
                output.Add(string.Format("Case #{0}: {1:0000}", i + 1, Solve(lines[index])));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static int Solve(string input)
        {
            string match = "welcome to code jam";
            int[,] counts = new int[input.Length+1, match.Length + 1];
            for (int i=0; i < input.Length; i++)
                counts[i, 0] = 1;

            for (int i = 1; i < input.Length + 1; i++)
            {
                for (int j = 1; j <= i && j < match.Length+1; j++)
                {
                    if (input[i - 1] == match[j - 1])
                    {
                        int total = counts[i-1,j-1] + counts[i-1,j];
                        counts[i, j] = total % 10000;
                    }
                    else
                    {
                        counts[i, j] = counts[i-1, j];
                    }
                }
            }
            return counts[input.Length, match.Length];
        }
    }
}
