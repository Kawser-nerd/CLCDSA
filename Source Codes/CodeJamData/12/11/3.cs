using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class PassProblem : GCJBase
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
                int A = int.Parse(s[0]);
                int B = int.Parse(s[1]);
                s = Console.ReadLine().Split(' ');
                double[] p = new double[A];
                for (int i = 0; i < A; i++)
                {
                    p[i] = double.Parse(s[i]);
                }

                double ret = BestKeys(A,B,p);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private double BestKeys(int A, int B, double[] p)
        {
            double[] allCorrect = new double[A+1];
            allCorrect[0] = 1;
            for (int i = 0; i < A; i++)
            {
                allCorrect[i + 1] = allCorrect[i] * p[i];
            }

            // Enter
            double best = B + 2;

            // X backspaces
            for (int i = 0; i <= A; i++)
            {
                int kRight = B -A +2*i + 1;
                int kWrong = kRight + B + 1;
                double possRight = allCorrect[A - i];
                double possWrong = 1 - possRight;
                double expected = possRight * kRight + possWrong * kWrong;
                best = Math.Min(best, expected);
            }

            return best;
        }

    }
}
