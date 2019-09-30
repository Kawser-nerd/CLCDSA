using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ08Qual3
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int cases = int.Parse(lines[0]);
            int index = 1;
            for (int i = 0; i < cases; i++)
            {
                Dictionary<string, int> labels = new Dictionary<string, int>();
                string[] bits = lines[index].Split(' ');
                index++;
                double f = double.Parse(bits[0]);
                double R = double.Parse(bits[1]);
                double t = double.Parse(bits[2]);
                double r = double.Parse(bits[3]);
                double g = double.Parse(bits[4]);
                double ratio;
                Solve(f, R, t, r, g, out ratio);
                output.Add(string.Format("Case #{0}: {1}", i + 1, ratio.ToString("0.0000000")));
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static void Solve(double f, double R, double t, double r, double g, out double ratio)
        {
            if (2 * f >= g || R - t - f <= 0)
            {
                ratio = 1.0;
                return;
            }
            double basis = Math.PI * R * R / 4.0;
            double accumulator = 0.0;
            // we do have holes.
            // fudge numbers to make it simpler.
            t += f;
            r += f;
            g -= 2 * f;
            double innerRadius = R - t;
            double innerRadiusSq = innerRadius * innerRadius;
            double Rsq = R * R;
            double step = 2 * r + g;
            double gSq = g * g;
            for (double blx = r; blx <= innerRadius; blx += step)
            {
                double trX = blx + g;
                for (double bly = r; bly <= innerRadius; bly += step)
                {
                    if (blx * blx + bly * bly > innerRadiusSq)
                        break;
                    double trY = bly + g;
                    if (trX * trX + trY * trY <= innerRadiusSq)
                    {
                        accumulator += gSq;
                    }
                    else
                    {
                        double tlX = blx;
                        double tlY = bly + g;
                        bool tlIn = false;
                        if (tlX * tlX + tlY * tlY <= innerRadiusSq)
                            tlIn = true;
                        double brX = blx + g;
                        double brY = bly;
                        bool brIn = false;
                        if (brX * brX + brY * brY <= innerRadiusSq)
                            brIn = true;
                        double xc1;
                        double xc2;
                        double yc1;
                        double yc2;
                        // calculate the triangle truncated square area.
                        // 4 cases to handle.
                        // first calc intercepts.
                        if (tlIn)
                        {
                            yc1 = tlY;
                            xc1 = Math.Sqrt(innerRadiusSq - yc1 * yc1);
                        }
                        else
                        {
                            xc1 = tlX;
                            yc1 = Math.Sqrt(innerRadiusSq - xc1 * xc1);
                        }
                        if (brIn)
                        {
                            xc2 = brX;
                            yc2 = Math.Sqrt(innerRadiusSq - xc2 * xc2);
                        }
                        else
                        {
                            yc2 = brY;
                            xc2 = Math.Sqrt(innerRadiusSq - yc2 * yc2);
                        }
                        if (tlIn)
                        {
                            if (brIn)
                            {
                                accumulator += gSq - (trX - xc1) * (trY - yc2) / 2.0;
                            }
                            else
                            {
                                accumulator += g * (xc1 - tlX) + (xc2 - xc1) * g / 2.0;
                            }
                        }
                        else
                        {
                            if (brIn)
                            {
                                accumulator += g * (yc2 - brY) + (yc1 - yc2) * g / 2.0;
                            }
                            else
                            {
                                accumulator += (yc1 - bly) * (xc2 - blx) / 2.0;
                            }
                        }
                        // add area of arc to cord of the triangle.
                        // arc to cord is r2[theta-sin(theta)]/2 where theta = 2 arcsin(c/[2r]) where c is the cord length
                        double a = xc2 - xc1;
                        double b = yc1 - yc2;
                        double c = Math.Sqrt(a * a + b * b);
                        double theta = 2.0 * Math.Asin(c / 2.0 / innerRadius);
                        double area = innerRadiusSq * (theta - Math.Sin(theta)) / 2.0;
                        accumulator += area;
                    }
                }
            }
            ratio = (basis-accumulator) / basis;
            return;
        }
    }
}
