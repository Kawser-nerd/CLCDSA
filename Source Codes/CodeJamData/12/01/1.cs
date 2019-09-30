using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
// http://www.themissingdocs.net/downloads/TMD.Algo.0.0.4.0.zip
using TMD.Algo.Algorithms;
using TMD.Algo.Collections;

namespace GCJ12QRQ1
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
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(lines[index])));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(string input)
        {
            StringBuilder result = new StringBuilder();
            foreach (char c in input)
                result.Append(Map(c));
            return result.ToString();
        }

        private static char Map(char c)
        {
            //           "abcdefghijklmnopqrstuvwxyz"
            string map = "yhesocvxduiglbkrztnwjpfmaq";
            if (c - 'a' >= 0 && c - 'a' < map.Length)
                return map[c - 'a'];
            return c;
        }

    }
}
