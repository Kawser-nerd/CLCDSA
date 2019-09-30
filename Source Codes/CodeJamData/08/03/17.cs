using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace GoogleCodeJam
{
    class Program
    {
        static double integral(double R, double x1, double x2)
        {
            var t1 = Math.Acos(x2/R);
            var t2 = Math.Acos(x1/R);
            var a = R*R/2;
            return -a*(t1 - t2) + a/2*(Math.Sin(2*t1) - Math.Sin(2*t2));
        }

        static void Main(string[] args)
        {
            var sr = new StreamReader("input.txt");
            var sw = new StreamWriter("output.txt");
            var N = int.Parse(sr.ReadLine());

            for (int i = 0; i < N; i++)
            {
                var temp = sr.ReadLine().Replace('.', ',').Split(' ');
                double f, R, t, r, g;
                f = double.Parse(temp[0]);
                R = double.Parse(temp[1]);
                t = double.Parse(temp[2]);
                r = double.Parse(temp[3]);
                g = double.Parse(temp[4]);

                var totalArea = Math.PI*R*R;
                var flyArea = 0.0;
                var x0 = r + f;
                var y0 = r + f;
                var sqSize = g - 2*f;
                var sR = R - t - f;

                if(sqSize <= 0.0)
                    sw.WriteLine("Case #" + (i + 1) + ": " + 1.0);
                else
                {
                    for (; x0 < sR; x0 += g + 2 * r)
                    {
                        y0 = r + f;
                        for (; y0 < sR; y0 += g + 2*r)
                        {
                            if (x0*x0 + y0*y0 >= sR*sR)
                                break;
                            if ((x0 + sqSize)*(x0 + sqSize) + (y0 + sqSize)*(y0 + sqSize) <= sR*sR)
                            {
                                flyArea += sqSize*sqSize;
                            }
                            else
                            {
                                var dist1 = x0*x0 + (y0 + sqSize)*(y0 + sqSize);
                                var dist2 = y0*y0 + (x0 + sqSize)*(x0 + sqSize);
                                var sR1 = sR*sR;

                                double x1;
                                double x2;

                                if (sR1 <= dist1 && sR1 <= dist2)
                                {
                                    x1 = x0;
                                    x2 = Math.Sqrt(sR*sR - y0*y0);
                                }
                                else if (sR1 >= dist1 && sR1 >= dist2)
                                {
                                    x1 = Math.Sqrt(sR*sR - (y0 + sqSize)*(y0 + sqSize));
                                    x2 = x0 + sqSize;

                                }
                                else if (sR1 >= dist1 && sR1 <= dist2)
                                {
                                    x1 = Math.Sqrt(sR*sR - (y0 + sqSize)*(y0 + sqSize));
                                    x2 = Math.Sqrt(sR*sR - y0*y0);
                                }
                                else
                                {
                                    x1 = x0;
                                    x2 = x0 + sqSize;
                                }
                                flyArea += integral(sR, x1, x2) - y0*(x2 - x1) + sqSize*(x1 - x0);
                            }
                        }
                    }

                    flyArea *= 4.0;

                    var result = (1.0 - flyArea/totalArea).ToString().Replace(',', '.');
                    sw.WriteLine("Case #" + (i + 1) + ": " + result);
                }
            }
            sw.Close();
        }
    }
}
