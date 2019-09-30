using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class B : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string[] s = Console.ReadLine().Split();
                int N = int.Parse(s[0]);
                double V = double.Parse(s[1]);
                double X = double.Parse(s[2]);
                double[] R = new double[N];
                double[] C = new double[N];
                for (int i = 0; i < N; i++)
                {
                    string[] s2 = Console.ReadLine().Split();
                    R[i] = double.Parse(s2[0]);
                    C[i] = double.Parse(s2[1]);
                }
                string ret = minTime(N, V, X, R, C);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //System.Diagnostics.Debug.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //    System.Diagnostics.Debug.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string minTime(int N, double totVol, double temp, double[] rate, double[] pipetemp)
        {
            Array.Sort(pipetemp, rate);
            for (int i = 0; i < N; i++)
            {
                pipetemp[i] -= temp;
            }
            double perfectrate = 0;
            List<double> heatUnits = new List<double>();
            List<double> baseUnits = new List<double>();
            double hotTot = 0;
            double coldTot = 0;
            for (int i = 0; i < N; i++)
            {
                heatUnits.Add(0);
                baseUnits.Add(0);
                double abstemp = Math.Abs(pipetemp[i]);
                if (abstemp == 0)
                {
                    perfectrate += rate[i];
                }
                double hotUnits = abstemp / (100 - abstemp);
                double totUnits = 1 + hotUnits;
                double scale = rate[i] / totUnits;
                baseUnits[i] = scale;
                heatUnits[i] = hotUnits * scale;
                if (pipetemp[i] > 0)
                {
                    hotTot += heatUnits[i];
                }
                if (pipetemp[i] < 0)
                {
                    coldTot += heatUnits[i];
                }
            }

            if (hotTot == 0 && perfectrate == 0) return "IMPOSSIBLE";
            if (coldTot == 0 && perfectrate == 0) return "IMPOSSIBLE";
            double secondRate = 0;
            if (hotTot == coldTot)
            {
                for (int i = 0; i < N; i++)
                {
                    secondRate += rate[i];
                }
            }

            if (hotTot == 0 || coldTot == 0)
            {
                secondRate = perfectrate;
            }

            if (hotTot > coldTot && coldTot > 0)
            {
                double budget = coldTot;
                secondRate = secondRateCalc(N, pipetemp, heatUnits, baseUnits, budget, true);
            }

            if (hotTot < coldTot && hotTot > 0)
            {
                double budget = hotTot;
                secondRate = secondRateCalc(N, pipetemp, heatUnits, baseUnits, budget, false);
            }

            return (totVol / secondRate).ToString();
        }

        private double secondRateCalc(int N, double[] pipeTemp, List<double> heatUnits, List<double> baseUnits, double budget, bool toohot)
        {
            int pos = N - 1;
            int move = -1;
            if (toohot)
            {
                pos = 0;
                move = 1;
            }
            double tot = 0;
            double secondRate = 0;
            while (tot < budget)
            {
                if (toohot && pipeTemp[pos] <= 0)
                {
                    secondRate += heatUnits[pos] + baseUnits[pos];
                }
                if (!toohot && pipeTemp[pos] >= 0)
                {
                    secondRate += heatUnits[pos] + baseUnits[pos];
                }
                if ((toohot && pipeTemp[pos] > 0) || (!toohot && pipeTemp[pos] < 0))
                {
                    if (tot + heatUnits[pos] <= budget)
                    {
                        secondRate += heatUnits[pos] + baseUnits[pos];
                        tot += heatUnits[pos];
                    }
                    else
                    {
                        double time = (budget - tot) / heatUnits[pos];
                        tot = budget;
                        secondRate += baseUnits[pos] * time;
                        secondRate += heatUnits[pos] * time;
                    }
                }
                pos += move;
            }

            return secondRate;
        }

    }
}
