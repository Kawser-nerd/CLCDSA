using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
// http://www.themissingdocs.net/downloads/TMD.Algo.0.0.4.0.zip
using TMD.Algo.Algorithms;
using TMD.Algo.Collections;

namespace GCJ10QRQ2
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
                int count = int.Parse(bits[0]);
                BigInteger[] values = new BigInteger[count];
                for (int j = 0; j < count; j++)
                {
                    values[j] = BigInteger.Parse(bits[j + 1]);
                }
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(values)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(BigInteger[] values)
        {
            Array.Sort(values);
            BigInteger gcd = values[1] - values[0];
            for (int i = 2; i < values.Length; i++)
            {
                gcd = BigInteger.GreatestCommonDivisor(gcd, values[i]-values[i-1]);
            }
            BigInteger mod = values[0] % gcd;
            if (mod == 0)
                return "0";
            return (gcd - mod).ToString();
        }
    }
}
