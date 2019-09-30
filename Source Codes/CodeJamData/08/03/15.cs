using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Globalization;

namespace FlySwatter
{
    class Program
    {
        static double getSectorS(double rr2, double x1, double y1, double x2, double y2)
        {
            double c2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            double cosA = 1 - (c2 / (2 * rr2));
            return rr2 * Math.Acos(cosA) / 2;
        }

        static double Solve(double f, double R, double t, double r, double g)
        {
            if (2 * f >= g)
                return 1;
            g -= 2 * f;
            r += f;
            t += f;
            if (t >= R)
                return 1;
            double rr = R - t;
            double rr2 = rr * rr;
            double gapS = 0;
            double y0 = r;
            while (y0 < rr)
            {
                double y1 = y0 + g;
                double y02 = y0 * y0;
                double y12 = y1 * y1;

                double xL2 = rr2 - y02;
                double xH2 = rr2 - y12;
                double x0 = r;
                while (x0 * x0 < xL2)
                {
                    double x1 = x0 + g;
                    double x12 = x1 * x1;
                    if (x12 <= xH2)
                        gapS += g * g;
                    else
                    {
                        double xR1;
                        double yR1;
                        if (x12 <= xL2)
                        {
                            xR1 = x1;
                            yR1 = Math.Sqrt(rr2 - x12);
                            gapS += ((yR1 - y0) * x1 - (g * y0)) / 2;
                        }
                        else
                        {
                            yR1 = y0;
                            xR1 = Math.Sqrt(rr2 - y02);
                            gapS -= (xR1 - x0) * y0 / 2;
                        }
                        double xR2;
                        double yR2;
                        if (y12 + x0 * x0 < rr2)
                        {
                            xR2 = Math.Sqrt(rr2 - y12);
                            yR2 = y1;
                            gapS += ((xR2 - x0) * y1 - g * x0) / 2;
                        }
                        else
                        {
                            xR2 = x0;
                            yR2 = Math.Sqrt(rr2 - x0 * x0);
                            gapS -= (yR2 - y0) * x0 / 2;
                        }
                        gapS += getSectorS(rr2, xR1, yR1, xR2, yR2);
                    }
                    x0 += g + 2 * r;
                }
                y0 += g + 2 * r;
            }
            return 1 - (gapS * 4 / (Math.PI * R * R));
        }

        static void Main(string[] args)
        {
            string DataFolder = @"C:\Projects\CSharp\CodeJam2008\FlySwatter\Data\";
            StreamReader sr = File.OpenText(DataFolder + "C-large.in");
            using (StreamWriter sw = File.CreateText(DataFolder + "C-large.out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int i = 0; i < caseCount; ++i)
                {
                    string[] s = sr.ReadLine().Split(' ');
                    sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solve(
                            double.Parse(s[0], CultureInfo.InvariantCulture), 
                            double.Parse(s[1], CultureInfo.InvariantCulture), 
                            double.Parse(s[2], CultureInfo.InvariantCulture), 
                            double.Parse(s[3], CultureInfo.InvariantCulture),
                            double.Parse(s[4], CultureInfo.InvariantCulture)
                            ).ToString("F8", CultureInfo.InvariantCulture));
                }
            }
        }
    }
}
