using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
// http://www.themissingdocs.net/downloads/TMD.Algo.0.0.4.0.zip
using TMD.Algo.Algorithms;
using TMD.Algo.Collections;

namespace GCJ12QRQ3
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
                string[] bits = lines[index].Split(' ');
                int A = int.Parse(bits[0]);
                int B = int.Parse(bits[1]);
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(A, B)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(int A, int B)
        {
            int length = Length(A);
            int factor = 1;
            for (int i = 1; i < length; i++)
                factor *= 10;
            int total = 0;
            for (int i = A; i < B; i++)
            {
                int current = Next(i, factor);
                while (current != i)
                {
                    if (current > i && current <= B)
                        total++;
                    current = Next(current, factor);
                }

            }
            return total.ToString();
        }

        private static int Length(int A)
        {
            int length = 0;
            while (A > 0)
            {
                length++;
                A /= 10;
            }
            return length;
        }

        private static int Next(int current, int factor)
        {
            int rem = current % 10;
            return (current / 10) + (rem * factor);
        }

    }
}
