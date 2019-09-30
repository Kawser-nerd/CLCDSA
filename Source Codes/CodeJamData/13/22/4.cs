using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class FallingDiamonds : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                long N = long.Parse(s.Split(' ')[0]);
                long X = long.Parse(s.Split(' ')[1]);
                long Y = long.Parse(s.Split(' ')[2]);
                double ret = probFallen(N,X,Y);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private double probFallen(long N, long X, long Y)
        {
            long layer = Math.Abs(X) + Y;
            System.Diagnostics.Debug.Assert(layer % 2 == 0);
            layer /= 2;

            long layersize = 1;
            long fallen = 0;
            for (int i = 0; i < layer; i++)
            {
                fallen += layersize;
                layersize += 4;
            }
            long nextfallen = fallen + layersize;
            if (N <= fallen) return 0;
            if (N >= nextfallen) return 1;

            long thislayer = N - fallen;

            if (Y > thislayer) return 0;
            if (Y < thislayer - layersize / 2) return 1;
            if (Y == layer * 2) return 0;


            double[] probs = new double[thislayer + 1];
            double[] probs2 = new double[thislayer + 1];
            probs[0] = 1;
            for (int i = 1; i <= thislayer; i++)
            {
                probs2[0]=probs[0]/2;
                probs2[i]=probs[i-1]/2;
                for (int j = 1; j < i; j++)
                {
                    probs2[j] = (probs[j] + probs[j - 1]) / 2;
                }
                double[] temp = probs;
                probs = probs2;
                probs2 = temp;
            }

            double ret = 0;
            for (int i = (int)Y+1; i <= thislayer; i++)
            {
                ret += probs[i];
            }

            return ret;
        }

        private double comb(long n, long k)
        {
            double sum = 0;
            for (int i = 0; i < k; i++)
            {
                sum += Math.Log(n - i);
                sum -= Math.Log(i + 1);
            }
            return Math.Exp(sum);
        }
    }
}
