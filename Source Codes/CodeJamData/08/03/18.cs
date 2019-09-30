using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace CodeJam2008.FlySwatter
{
    class Program
    {
        static double Integral(double x, double r, double move_y)
        {
            return 0.5 * (r*r * Math.Asin( x / r ) + x*Math.Sqrt(r*r - x*x)) - move_y*x;
        }

        static double ChanceOfHitting(double flyRadius, double outerRadius, double thikness, double stringRadius, double gap)
        {
            int cnt = (int)((outerRadius - thikness) / (2 * stringRadius + gap)) + 1;

            double surface = 0;
            double r = outerRadius - thikness - flyRadius;

            if (2 * flyRadius < gap)
            {
                for (int j = 0; j < cnt; j++)
                {
                    double x = j * (2 * stringRadius + gap) + stringRadius + flyRadius;

                    for (int i = 0; i < cnt; i++)
                    {
                        double y = i * (2 * stringRadius + gap) + stringRadius + flyRadius;

                        double top = y + gap - 2 * flyRadius;
                        double right = x + gap - 2 * flyRadius;

                        if (x * x + y * y < r * r)
                        {
                            if (top * top + right * right <= r * r)
                            {
                                surface += (gap - 2 * flyRadius) * (gap - 2 * flyRadius);
                            }
                            else
                            {
                                if (x * x + top * top < r * r)
                                {
                                    double a = Math.Sqrt(r * r - top * top);
                                    surface += (a - x) * (gap - 2 * flyRadius);
                                    surface += Integral(Math.Min(right, Math.Sqrt(r * r - y * y)), r, y) - Integral(a, r, y);
                                }
                                else
                                {
                                    surface += Integral(Math.Min(right, Math.Sqrt(r * r - y * y)), r, y) - Integral(x, r, y);
                                }
                            }
                        }
                    }
                }
            }
            return 1.0 - (4 * surface) / (Math.PI * outerRadius * outerRadius);
        }

        static void Main(string[] args)
        {
            int time = System.Environment.TickCount;
            TextReader r = new StreamReader("input.txt");

            int N = int.Parse(r.ReadLine());

            for (int i = 1; i <= N; i++)
            {
                string[] input = r.ReadLine().Split(' ');

                var provider = new NumberFormatInfo();
                provider.NumberDecimalSeparator = ".";

                Console.WriteLine("Case #{0}: {1}", i, 
                    ChanceOfHitting(
                        double.Parse(input[0], provider),
                        double.Parse(input[1], provider),
                        double.Parse(input[2], provider),
                        double.Parse(input[3], provider),
                        double.Parse(input[4], provider)
                    ).ToString("0.000000", provider));
            }
                                
            r.Close();
            //Console.ReadLine();
        }
    }
}
