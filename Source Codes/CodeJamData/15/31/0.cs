using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam2015Q1C_1
{
    public class Problem
    {
        public Problem()
        {
            var pathname = "Sample.txt";
            using (FileStream fs = new FileStream(pathname, FileMode.Open))
            {
                StreamReader sr = new StreamReader(fs);
                using (FileStream fsout = new FileStream(pathname + ".out", FileMode.Create))
                {
                    StreamWriter sw = new StreamWriter(fsout);
                    int caseScenario = Int32.Parse(sr.ReadLine()); // Nb de scenario
                    for (int sc = 1; sc <= caseScenario; sc++)
                    {
                        long result = 0;
                        string[] lines = sr.ReadLine().Split(' ');
                        int R = int.Parse(lines[0]);
                        int C = int.Parse(lines[1]);
                        int W = int.Parse(lines[2]);

                        if (W == 1)
                        {
                            result = C * R;
                        }
                        else
                        {
                            long beforeHit = (C / W) * R;
                            long afterHit = 0;
                            if (C % W == 0)
                                afterHit = W - 1;
                            else
                                afterHit = W;
                            result = beforeHit + afterHit;
                        }
                        sw.WriteLine("Case #{0}: {1}", sc, result);
                    }
                    sw.Flush();
                }

            }
        }


    }
}
