using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJamSharp
{

    class A
    {
        static double Sqr(double x) { return x * x; }

        static void Main(string[] args)
        {
            using (StreamReader sr = File.OpenText(@"C:\Google\A.in"))
            using (StreamWriter sout = File.CreateText(@"C:\Google\A.out"))
            {
                string line = sr.ReadLine();
                int cases = int.Parse(line);
                for (int cas = 1; cas <= cases; cas++)
                {
                    line = sr.ReadLine();
                    string[] items = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    double x1 = double.Parse(items[0]);
                    double y1 = double.Parse(items[1]);

                    double x2 = double.Parse(items[2]);
                    double y2 = double.Parse(items[3]);

                    double x3 = double.Parse(items[4]);
                    double y3 = double.Parse(items[5]);

                    line = sr.ReadLine();
                    items = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    double xx1 = double.Parse(items[0]);
                    double yy1 = double.Parse(items[1]);

                    double xx2 = double.Parse(items[2]);
                    double yy2 = double.Parse(items[3]);

                    double xx3 = double.Parse(items[4]);
                    double yy3 = double.Parse(items[5]);

                    double K = (Sqr(x1 - x2) + Sqr(y1 - y2)) / (Sqr(xx1 - xx2) + Sqr(yy1 - yy2));

                    //  (X-x1)^2 + (Y-y1)^2 = K* ((X-xx1)^2 + (Y-yy1)^2)
                    //  (X-x2)^2 + (Y-y2)^2 = K* ((X-xx2)^2 + (Y-yy2)^2)
                    //  (X-x3)^2 + (Y-y3)^2 = K* ((X-xx3)^2 + (Y-yy3)^2)

                    // (X-x1-X+x2)*(X-x1+X-x2) + (Y-y1-Y+y2)*(Y-y1+Y-y2) = K* ...
                    // (X-x1-X+x3)*(X-x1+X-x3) + (Y-y1-Y+y3)*(Y-y1+Y-y3) = K* ...
                    //  (x2-x1)*(2X - x1 - x2) + (y2-y1)*(2Y - y1-y2) = K* ...
                    //  (x3-x1)*(2X - x1 - x3) + (y3-y1)*(2Y - y1-y3) = K* ...

                    // 2X*(x2-x1 - K*xx2 + K*xx1) + 2Y * (y2-y1 - K*yy2 + K*yy1) = (x2-x1)*(x1+x2) + (y2-y1)*(y1+y2)  + K*((xx2-xx1)*(xx1+xx2) + (yy2-y1)*(yy1+yy2)) 
                    // 2X*(x3-x1 - K*xx3 + K*xx1) + 2Y * (y3-y1 - K*yy3 + K*yy1) = (x3-x1)*(x1+x3) + (y3-y1)*(y1+y3)  + K*((xx3-xx1)*(xx1+xx2) + (yy2-y1)*(yy1+yy2)) 
                    double A1 = 2 * (x2 - x1) - 2 * K * (xx2 - xx1);
                    double B1 = 2 * (y2 - y1) - 2 * K * (yy2 - yy1);
                    double C1 = (x2 - x1) * (x1 + x2) + (y2 - y1) * (y1 + y2) - K * ((xx2 - xx1) * (xx1 + xx2) + (yy2 - yy1) * (yy1 + yy2));

                    double A2 = 2 * (x3 - x1) - 2 * K * (xx3 - xx1);
                    double B2 = 2 * (y3 - y1) - 2 * K * (yy3 - yy1);
                    double C2 = (x3 - x1) * (x1 + x3) + (y3 - y1) * (y1 + y3) - K * ((xx3 - xx1) * (xx1 + xx3) + (yy3 - yy1) * (yy1 + yy3));


                    double D = A2 * B1 - A1 * B2;
                    if (D == 0)
                    {
                        if (C1 != C2)
                        {
                            sout.WriteLine("Case #{0}: No Solution", cas);
                        }
                        else
                        {
                            sout.WriteLine("Case #{0}: {1} {2}", cas, xx1, yy1);
                        }
                    }
                    else
                    {

                        double retY = (C1 * A2 - C2 * A1) / D;
                        double retX = -(C1 * B2 - C2 * B1) / D;
                        sout.WriteLine("Case #{0}: {1} {2}", cas, retX, retY);
                    }




                    //    sout.WriteLine("Case #{0}: {1}", cas, ret);
                }
            }
        }
    }
}
