using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam2015Q1C_3
{
    public class ProblemLarge
    {
        public ProblemLarge()
        {
            var pathname = "Sample.txt";
            using (FileStream fs = new FileStream(pathname, FileMode.Open))
            {
                StreamReader sr = new StreamReader(fs);
                using (FileStream fsout = new FileStream(pathname + ".large.out", FileMode.Create))
                {
                    StreamWriter sw = new StreamWriter(fsout);
                    int caseScenario = Int32.Parse(sr.ReadLine()); // Nb de scenario
                    for (int sc = 1; sc <= caseScenario; sc++)
                    {
                        string[] lines = sr.ReadLine().Split(' ');
                        long C = long.Parse(lines[0]);
                        long D = long.Parse(lines[1]);
                        long V = long.Parse(lines[2]);
                        long result = 0;

                        var values = sr.ReadLine().Split(' ').ToArray().Select(s => long.Parse(s)).ToList<long>();
                        long max= 0;
                        for (int i = 0; i < D; i++)
                        {
                            if (max > V)
                                break;

                            if (values[i] <= max + 1)
                            {
                                max = C * values[i] + max;
                            }
                            else
                            {
                                while (values[i] > max + 1)
                                {
                                    result++;
                                    max = C * (max + 1) + max;
                                }
                                max = C * values[i] + max;
                            }
                        }
                        while (max < V)
                        {
                            result++;
                            max = C * (max + 1) + max;
                        }

                        sw.WriteLine("Case #{0}: {1}", sc, result);
                    }
                    sw.Flush();
                }

            }
        }


    }
}
