using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class CookieClickerAlpha : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string[] s = Console.ReadLine().Split(' ');
                double C = double.Parse(s[0]);
                double F = double.Parse(s[1]);
                double X = double.Parse(s[2]);
                double ret = MinTime(C,F,X);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private double MinTime(double farmCost, double farmOutput, double target)
        {
            double time = 0;
            double rate = 2;
            do
            {
                double timeToFinish = target / rate;
                double timeToFarm = farmCost / rate;
                double timeToFinishWithFarm = timeToFarm + (target / (rate + farmOutput));
                if (timeToFinish <= timeToFinishWithFarm)
                {
                    return time + timeToFinish;
                }
                else
                {
                    time += timeToFarm;
                    rate += farmOutput;
                }
            } while (true);
        }

    }
}
