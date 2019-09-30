using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace GJamR1SumC_B
{
    class Program
    {
        private static CultureInfo culture = new CultureInfo("en-US");

        static void Main(string[] args)
        {
            if (args.Length == 0) return;

            string filename = args[0];
            var lines = File.ReadLines(filename).ToList();

            int testCount = int.Parse(lines.ElementAt(0));
            int lineNumber = 1;

            for (int i = 0; i < testCount; i++)
            {
                string line = lines[lineNumber];
                lineNumber++;

                string[] initS = line.Split(new char[] { ' ' });
                double Distance = double.Parse(initS[0], culture);
                int N = int.Parse(initS[1]);
                int A = int.Parse(initS[2]);

                double[,] carArray = new double[N,2];
                double[] accelerations = new double[A];

                for (int j = 0; j < N; j++)
                {
                    line = lines[lineNumber];
                    lineNumber++;
                    initS = line.Split(new char[] { ' ' });

                    carArray[j, 0] = double.Parse(initS[0], culture);
                    carArray[j, 1] = double.Parse(initS[1], culture);
                }


                line = lines[lineNumber];
                lineNumber++;
                initS = line.Split(new char[] { ' ' });
                for (int j = 0; j < A; j++)
                {
                    accelerations[j] = double.Parse(initS[j], culture);
                }


                File.AppendAllText(filename + ".out", "Case #" + (i + 1) + ": ");
                File.AppendAllText(filename + ".out", "\n");

                for (int j = 0; j < A; j++)
                {
                    double res = GetTime(carArray, accelerations[j], Distance);
                    File.AppendAllText(filename + ".out", res.ToString(culture));
                    File.AppendAllText(filename + ".out", "\n");
                }
            }
        }

        private static double GetTime(double[,] carArray, double accelerations, double D)
        {
            double noBrakesTime = Math.Sqrt(2*D/accelerations);

            double otherCarTime = 0;

            if (carArray[0, 1] >= D)
                return noBrakesTime;

            for (int i = carArray.Length/2 - 1; i >= 0; i--)
            {
                if (carArray[i, 1] < D)
                {
                    otherCarTime = carArray[i, 0] + ((D - carArray[i, 1]) * (carArray[i+1, 0] - carArray[i, 0])) / (carArray[i + 1, 1] - carArray[i, 1]);

                    //get other times
                    for (int j = 1; j <= i; j++)
                    {
                        //double v = Math.Sqrt(2 * carArray[j, 1] * accelerations);

                        //double res = SolveQuadProb(D - carArray[j, 1], v, accelerations) + carArray[j, 0];

                        double t0 = carArray[j, 0] - Math.Sqrt(2 * carArray[j, 1] / accelerations);

                        double res = noBrakesTime + t0;

                        if (res > otherCarTime)
                            otherCarTime = res;
                    }

                    break;
                }
            }

            if (otherCarTime > noBrakesTime)
                return otherCarTime;
            else
                return noBrakesTime;            
        }

        private static double SolveQuadProb(double s, double v, double a)
        {
            return (Math.Sqrt(v*v+2*a*s)) / a;
        }
    }
}
