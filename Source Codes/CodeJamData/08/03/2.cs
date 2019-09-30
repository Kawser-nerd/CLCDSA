using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace test.Google
{
    public class FlySwatter
    {
        public static void Main(string[] arg)
        {
            try
            {
                using (StreamReader sr = new StreamReader(arg[0]))
                using (StreamWriter sw = new StreamWriter(arg[1]))
                {
                    int num = int.Parse(sr.ReadLine());
                    for (int i = 0; i < num; ++i)
                    {
                        string[] els = sr.ReadLine().Split(' ');
                        double[] vals = new double[5];
                        for (int j=0;j<5;++j)vals[j]=double.Parse(els[j]);
                        double prop = Get(vals[0], vals[1], vals[2], vals[3], vals[4]);

                        //string input=sr.ReadLine();
                        //string output = Convert(input.Split(' '));
                        //Console.WriteLine(input + "=" + output);

                        sw.WriteLine("Case #" + (i + 1) + ": " + Math.Abs(prop).ToString("f6"));
                    }
                }
            }
            catch (Exception e) { Console.WriteLine(e.Message + e.StackTrace); }
            Console.ReadKey();
        }


        public static double Get(double f, double R, double t, double r, double g)
        {
            if (2 * f >= g - 1e-10) return 1;
            double total = Math.Atan(1) * 4 * R * R;
            double spare = 0;
            R = R - f - t;
            double x = f + r;
            double unit = g + r + r;
            double dx = (g - 2 * f) / 2500;
            while (x < R)
            {
                for (int i = 0; i < 2500; ++i)
                {
                    double X = x + (i+0.5) * dx;
                    if (X > R) break;

                    double Y = Math.Sqrt(R * R - X * X);
                    int numg = (int)(Y / unit);
                    double diff = numg * 2 * (f + r);
                    double left = Y - numg * unit;
                    if (left > f + r)
                    {
                        diff += f + r;
                        if (left > g + r - f) diff += left - (g +r- f);
                    }
                    else diff += left;

                    spare += dx * (Y-diff);
                }

                x += unit;
            }

            return (total - spare*4) / total;
        }
    }
}
