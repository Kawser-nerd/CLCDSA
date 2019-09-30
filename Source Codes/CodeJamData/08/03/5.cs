using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

public class Program
{
    static double segarea(double r, double start, double end, double y)
    {
        double t1 = start * Math.Sqrt(1.0 - (start * start) / (r * r)) + r * Math.Asin(start / r);
        double t2 = end * Math.Sqrt(1.0 - (end * end) / (r * r)) + r * Math.Asin(end / r);
        double area = (t2 - t1) * r / 2;
        area -= y * (end - start);
        return area;
    }

    static void Main()
    {
        int n = Int32.Parse(Console.ReadLine());

        for (int c = 0; c < n; ++c)
        {
            string[] s = Console.ReadLine().Split(' ');
            double f = Double.Parse(s[0]);
            double R = Double.Parse(s[1]);
            double t = Double.Parse(s[2]);
            double r = Double.Parse(s[3]);
            double g = Double.Parse(s[4]);

            double p;

            if (g <= f * 2)
            {
                p = 1.0;
            }
            else
            {
                double rgrid = R - t - f;

                g -= f * 2;
                r += f;

                double holeArea = 0.0;
                for (double x = r; x < rgrid; x += r * 2 + g)
                {
                    for (double y = r; x * x + y * y < rgrid * rgrid; y += r * 2 + g)
                    {
                        double xmax = Math.Min(
                            Math.Cos(Math.Asin(y / rgrid)) * rgrid, x + g);
                        double ynext = y + g;
                        if (x * x + ynext * ynext >= rgrid * rgrid)
                        {
                            holeArea += segarea(rgrid, x, xmax, y);
                        }
                        else
                        {
                            double xmid = Math.Sin(Math.Acos(ynext / rgrid)) * rgrid;
                            if (xmid < xmax)
                            {
                                holeArea += g * (xmid - x);
                                holeArea += segarea(rgrid, xmid, xmax, y);
                            }
                            else
                            {
                                holeArea += g * (xmax - x);
                            }
                        }

                    }
                    
                }
                
                p = 1.0 - holeArea * 4 / (Math.PI*R*R);
            }
            

            Console.WriteLine("Case #{0}: {1:f8}", c+1, p);
        }
    }
}
