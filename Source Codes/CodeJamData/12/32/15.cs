using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Codejam2012._3A
{
    class Resolucion
    {
        public static void Resolver(string path)
        {
            StreamWriter escritor = new StreamWriter(string.Concat(path, "/", "current.out"));
            StreamReader lector = new StreamReader(string.Concat(path, "/", "current.in"));
            int T = int.Parse(lector.ReadLine());
            for (int t = 0; t < T; ++t)
            {
                string[] data = lector.ReadLine().Split(' ');
                double D = double.Parse(data[0].Replace(".",","));
                int N = int.Parse(data[1]);
                int A = int.Parse(data[2]);

                CarPos[] positions = new CarPos[N];
                for (int p = 0; p < N; p++)
                {
                    data = lector.ReadLine().Split(' ');
                    positions[p] = new CarPos(double.Parse(data[0].Replace(".", ",")), double.Parse(data[1].Replace(".", ",")));
                }

                data = lector.ReadLine().Split(' ');

                escritor.WriteLine(string.Concat("Case #", t + 1, ":"));
                for (int i = 0; i < A; i++)
                {
                    double a = double.Parse(data[i].Replace(".", ","));

                    double timeElapsed = 0;
                    double myCarLastPosition = 0;
                    double myCarLastSpeed = 0;
                    for (int p = 1; p < N; p++)
                    {
                        double myCarTime = TimeFromX0ToXf(myCarLastPosition, positions[p].X, myCarLastSpeed, a);
                        double otherCarTime = positions[p].T - positions[p - 1].T;

                        if (myCarTime <= otherCarTime)
                        {
                            if (positions[p].X >= D)
                            {
                                double otherCarSpeed = (positions[p].X - positions[p - 1].X) / (positions[p].T - positions[p - 1].T);
                                timeElapsed += Math.Max(TimeFromX0ToXf(myCarLastPosition, D, myCarLastSpeed, a), (D - positions[p-1].X) / otherCarSpeed);
                                myCarLastPosition = D;
                                break;
                            }
                            myCarLastSpeed = FinalSpeed(myCarLastPosition, positions[p].X, myCarLastSpeed, a);
                            myCarLastPosition = positions[p].X;
                        }
                        else
                        {
                            double positionIWillBe = myCarLastSpeed * otherCarTime + (a / 2) * otherCarTime * otherCarTime;
                            if (positionIWillBe >= D)
                            {
                                timeElapsed += TimeFromX0ToXf(myCarLastPosition, D, myCarLastSpeed, a);
                                myCarLastPosition = D;
                                break;
                            }
                            myCarLastPosition = positionIWillBe;
                            myCarLastSpeed = myCarLastSpeed + a * otherCarTime;
                        }
                        timeElapsed += otherCarTime;
                    }
                    if (myCarLastPosition < D)
                    {
                        timeElapsed += TimeFromX0ToXf(myCarLastPosition, D, myCarLastSpeed, a);
                    }

                    escritor.WriteLine(timeElapsed.ToString("N6").Replace(".", "").Replace(",", "."));
                }
            }
            lector.Close();
            escritor.Close();
        }

        static double FinalSpeed(double x0, double xf, double v0, double a)
        {
            return Math.Sqrt(v0 * v0 + 2 * a * (xf - x0));
        }

        static double TimeFromX0ToXf(double x0, double xf, double v0, double a)
        {
            return (FinalSpeed(x0, xf, v0,a) - v0) / a;
        }

        struct CarPos
        {
            public double X;
            public double T;

            public CarPos(double t, double x)
            {
                X = x;
                T = t;
            }
        }
    }
}
