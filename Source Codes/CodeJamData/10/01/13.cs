using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
// http://www.themissingdocs.net/downloads/TMD.Algo.0.0.4.0.zip
using TMD.Algo.Algorithms;
using TMD.Algo.Collections;

namespace GCJ10QRQ1
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
                int n = int.Parse(bits[0]);
                int k = int.Parse(bits[1]);
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(n, k)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(int n, int k)
        {
            long size = 1L << n;
            return (k % size) == (size - 1) ? "ON" : "OFF";
        }
    }
}
