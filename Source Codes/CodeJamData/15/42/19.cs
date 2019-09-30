using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;

namespace GoogleCodeJam2015Q2_B
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
                        decimal result = 0m;

                        string[] input = sr.ReadLine().Split(' ');
                        int N = int.Parse(input[0]);
                        decimal V = decimal.Parse(input[1], NumberStyles.AllowDecimalPoint, CultureInfo.InvariantCulture);
                        decimal C = decimal.Parse(input[2], NumberStyles.AllowDecimalPoint, CultureInfo.InvariantCulture);
                        decimal[] rates = new decimal[N];
                        decimal[] temperatures = new decimal[N];

                        decimal minTemp = 100.0m;
                        decimal maxTemp = 0.0m;
                        
                        for (int n = 0; n < N; n++)
                        {
                            decimal[] rc = sr.ReadLine().Split(' ').Select(s => decimal.Parse(s, NumberStyles.AllowDecimalPoint, CultureInfo.InvariantCulture)).ToArray<decimal>();
                            rates[n] = rc[0];
                            temperatures[n] = rc[1];
                            minTemp = minTemp < rc[1] ? minTemp : rc[1];
                            maxTemp = maxTemp > rc[1] ? maxTemp : rc[1];
                        }

                        if (minTemp <= C && C <= maxTemp)
                        {
                            if (N == 1)
                            {
                                if (temperatures[0] == C)
                                {
                                    result = V / rates[0];
                                }
                            }
                            if (N == 2)
                            {
                                decimal V0;
                                decimal V1;
                                if (C == temperatures[0] && C == temperatures[1])
                                {
                                    result = V / (rates[0] + rates[1]);
                                }
                                else if (C == temperatures[0])
                                {
                                    result = V / rates[0];
                                }
                                else if (C == temperatures[1])
                                {
                                    result = V / rates[1];
                                }
                                else {
                                decimal x0 = temperatures[0];
                                decimal x1 = temperatures[1];
                                V0 = V * (C - x1) / (x0 - x1);
                                V1 = V * (C - x0) / (x1 - x0);
                                decimal t0 = V0 / rates[0];
                                decimal t1 = V1 / rates[1];
                                result = t0 > t1 ? t0 : t1;
                            }
                            
                            }
                        }
                        sw.WriteLine("Case #{0}: {1}", sc, result == 0m ? "IMPOSSIBLE" : result.ToString("F9",CultureInfo.InvariantCulture));
                    }
                    sw.Flush();
                }

            }
        }


    }
}
