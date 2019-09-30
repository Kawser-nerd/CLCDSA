using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
// http://www.themissingdocs.net/downloads/TMD.Algo.0.0.4.0.zip
using TMD.Algo.Algorithms;
using TMD.Algo.Collections;
using TMD.Algo.Collections.Generic;

namespace GCJ11R1AQ1
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
                long n = long.Parse(bits[0]);
                int pd = int.Parse(bits[1]);
                int pg = int.Parse(bits[2]);
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(n, pd, pg)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(long n, int pd, int pg)
        {
            // does there exist k between 1 and n inclusive such that pd*n/100 is an integer and there exists l >= n such that pg*l/100 is an integer and larger than pd*n/100
            if (pg == 100 && pd != 100)
                return "Broken";
            if (pg == 0 && pd != 0)
                return "Broken";
            if (n >= 100)
                return "Possible";
            for (int i = 1; i <= n; i++)
            {
                if ((pd * i) % 100 == 0)
                {
                    return "Possible";
                }
            }
            return "Broken";
        }

    }
}
