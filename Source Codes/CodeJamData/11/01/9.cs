using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2011_QRA
{
    class Program
    {
        private static void Main(string[] args)
        {
            string filedir = @"c:\temp\google_comp\";
            string inputfile = filedir + @"test1.in";
            string outputfile = inputfile.Replace(".in", ".out");
            Queue<string> lines = new Queue<string>(File.ReadAllLines(inputfile));
            int numcases = int.Parse(lines.Dequeue());
            var results = new List<string>();
            for (int casenum = 0; casenum < numcases; casenum++)
            {
                string[] curcase = lines.Dequeue().Split();
                int[] p = new int[2];
                int[] t = new int[2];
                p[0] = 1;
                p[1] = 1;
                int time = 0;
                int cc = 1;
                while(cc < curcase.Length)
                {
                    int index = curcase[cc] == "O" ? 0 : 1;
                    int pressPos = int.Parse(curcase[cc + 1]);
                    cc += 2;
                    int elp = time - t[index];
                    int dist = Math.Abs(pressPos - p[index]);
                    if(elp >= dist)
                    {
                        time++;
                    }
                    else
                    {
                        time += dist - elp + 1;
                    }
                    p[index] = pressPos;
                    t[index] = time;
                }

                results.Add(string.Format("Case #{0}: {1}", casenum + 1, time));
            }

            File.WriteAllLines(outputfile, results);

        }

    }
}
