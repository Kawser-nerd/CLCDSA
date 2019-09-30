using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            DateTime dt1 = DateTime.Now;

            Program.Call();

            DateTime dt2 = DateTime.Now;
            TimeSpan ts2 = dt2.Subtract(dt1);
            Console.WriteLine("time: {0} ms", ts2.TotalMilliseconds);
        }

        static void Call()
        {
            MyProblem mp = new MyProblem();
            mp.run();
        }
    }

    class MyProblem
    {
        public double dist(double x1, double y1, double x2, double y2)
        {
            return Math.Sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        }
        public void run()
        {
            string infile_name = @"F:\!!!20080705\GoogleCodeJam\Program2.0\GCodeJam\1-C-Fly Swatter\C-large.in.txt";

            StreamReader sr = new StreamReader(infile_name);
            string line;
            line = sr.ReadLine();
            int N = Convert.ToInt32(line);
            double[] f = new double[N];
            double[] R = new double[N];
            double[] t = new double[N];
            double[] r = new double[N];
            double[] g = new double[N];
            for (int i = 0; i < N; i++)
            {
                line = sr.ReadLine();
                string[] ss = line.Trim().Split(' ');
                f[i] = Convert.ToDouble(ss[0]);
                R[i] = Convert.ToDouble(ss[1]);
                t[i] = Convert.ToDouble(ss[2]);
                r[i] = Convert.ToDouble(ss[3]);
                g[i] = Convert.ToDouble(ss[4]);
            }

            sr.Close();

            /************************************************/
            double[] p = new double[N];
            //double pi = Math.PI;
            for (int i = 0; i < N; i++)
            {
                if (g[i] <= 2 * f[i])
                {
                    p[i] = 1;
                    continue;
                }

                int n_squares = (int)(R[i] / (g[i] + 2 * r[i])) + 1;
                double area_not_hit = 0;
                double inner_R = R[i] - t[i] - f[i];
                for (int j = 0; j < n_squares; j++)
                {
                    for (int k = 0; k < n_squares; k++)
                    {
                        double left = (g[i] + 2 * r[i]) * j + r[i] + f[i];
                        double right = (g[i] + 2 * r[i]) * (j + 1) - r[i] - f[i];
                        double bottom = (g[i] + 2 * r[i]) * k + r[i] + f[i];
                        double top = (g[i] + 2 * r[i]) * (k + 1) - r[i] - f[i];

                        double d_rt = dist(0, 0, right, top);
                        double d_lt = dist(0, 0, left, top);
                        double d_rb = dist(0, 0, right, bottom);
                        double d_lb = dist(0, 0, left, bottom);
                        if (d_rt <= inner_R)
                        {
                            area_not_hit += (right - left) * (top - bottom);
                        }
                        else
                        {
                            if (d_lt <= inner_R && d_rb <= inner_R)
                            {
                                double a1 = Math.Asin(top / inner_R);
                                double a2 = Math.Asin(right / inner_R);
                                double xt = Math.Sqrt(inner_R * inner_R - top * top);
                                double yr = Math.Sqrt(inner_R * inner_R - right * right);
                                double s1 = (Math.PI / 2 - a1) * inner_R * inner_R / 2 - xt * top / 2;
                                double s2 = a2 * inner_R * inner_R / 2 - yr * right / 2;
                                double s3 = s2 - s1 - left * (top - yr);
                                area_not_hit += s3 + (right - left) * (yr - bottom);
                            }
                            else if(d_lt <= inner_R)
                            {
                                double a1 = Math.Asin(top / inner_R);
                                double a2 = Math.Asin(bottom / inner_R);
                                double xt = Math.Sqrt(inner_R * inner_R - top * top);
                                double xb = Math.Sqrt(inner_R * inner_R - bottom * bottom);
                                double s1 = (Math.PI / 2 - a1) * inner_R * inner_R / 2 - xt * top / 2;
                                double s2 = (Math.PI / 2 - a2) * inner_R * inner_R / 2 - xb * bottom / 2;
                                double s3 = s2 - s1 - left * (top - bottom);
                                area_not_hit += s3;
                            }
                            else if (d_rb <= inner_R)
                            {
                                double ttt = left; left = bottom; bottom = ttt;
                                ttt = right; right = top; top = ttt;
                                double a1 = Math.Asin(top / inner_R);
                                double a2 = Math.Asin(bottom / inner_R);
                                double xt = Math.Sqrt(inner_R * inner_R - top * top);
                                double xb = Math.Sqrt(inner_R * inner_R - bottom * bottom);
                                double s1 = (Math.PI / 2 - a1) * inner_R * inner_R / 2 - xt * top / 2;
                                double s2 = (Math.PI / 2 - a2) * inner_R * inner_R / 2 - xb * bottom / 2;
                                double s3 = s2 - s1 - left * (top - bottom);
                                area_not_hit += s3;
                            }
                            else if (d_lb <= inner_R)
                            {
                                double a1 = Math.Asin(bottom / inner_R);
                                double a2 = Math.Asin(left / inner_R);
                                double xb = Math.Sqrt(inner_R * inner_R - bottom * bottom);
                                double yl = Math.Sqrt(inner_R * inner_R - left * left);
                                double s2 = (Math.PI / 2 - a1) * inner_R * inner_R / 2 - xb * bottom / 2;
                                double s1 = a2 * inner_R * inner_R / 2 - yl * left / 2;
                                double s3 = s2 - s1 - left * (yl - bottom);
                                area_not_hit += s3;
                            }
                        }
                    }
                }

                p[i] = 1 - area_not_hit / (Math.PI * R[i] * R[i] / 4);
            }



            /************************************************/

            string outfile_name = @"F:\!!!20080705\GoogleCodeJam\Program2.0\GCodeJam\1-C-Fly Swatter\C-large.out.txt";

            StreamWriter sw = new StreamWriter(outfile_name);
            for (int i = 0; i < N; i++)
            {
                sw.WriteLine("Case #{0}: {1}", i + 1, p[i]);
            }
            sw.Flush();
            sw.Close();
        }
    }
}

