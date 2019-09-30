using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace cs_console
{
    class G3_A
    {
        public static void Main(String[] args)
        {
            string input = @"../../A.in";
            string output = @"../../A.out";
            using (StreamWriter sw = new StreamWriter(output))
            {
                using (StreamReader sr = new StreamReader(input))
                {
                    long tn = long.Parse(sr.ReadLine());
                    for (long tc = 1; tc <= tn; tc++)
                    {
                        double[] ds = ls(sr);
                        sw.WriteLine("Case #{0}:", tc);
                        foreach(double d in ds)
                        {
                            sw.WriteLine(d);
                        }
                    }
                }
            }
        }

        private static double[] ls(StreamReader sr)
        {
            string[] ss = sr.ReadLine().Split(' ');
            int w = int.Parse(ss[0]);
            int l = int.Parse(ss[1]);
            int u = int.Parse(ss[2]);
            int g = int.Parse(ss[3]);
            int[] lx = new int[l];
            int[] ly = new int[l];
            int[] ux = new int[u];
            int[] uy = new int[u];
            for(int i=0; i<l; i++)
            {
                ss = sr.ReadLine().Split(' ');
                lx[i] = int.Parse(ss[0]);
                ly[i] = int.Parse(ss[1]);
                ly[i] += 1001;
            }
            for(int i=0; i<u; i++)
            {
                ss = sr.ReadLine().Split(' ');
                ux[i] = int.Parse(ss[0]);
                uy[i] = int.Parse(ss[1]);
                uy[i] += 1001;
            }
            double[] ret = new double[g - 1];
            double s = area(lx, ly, ux, uy, w);
            for (int i = 1; i < g; i++)
            {
                ret[i - 1] = find(lx, ly, ux, uy, s * i / g, w);
            }
            return ret;
        }

        private static double find(int[] lx, int[] ly, int[] ux, int[] uy, double a, double w)
        {
            double left = 0;
            double right = w;
            while (left + 1e-7 < right)
            {
                double mid = (left + right) / 2;
                double s = area(lx, ly, ux, uy, mid);
                if (s < a)
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
            return left;
        }

        static double area(int[] lx, int[] ly, int[] ux, int[] uy, double pos)
        {
            return area0(ux, uy, pos) - area0(lx, ly, pos);
        }

        static double area0(int[] x, int[] y, double pos)
        {
            double ret = 0;
            for (int i = 0; i < x.Length - 1; i++)
            {
                if (x[i + 1] >= pos)
                {
                    double k = (double)(y[i + 1] - y[i]) / (double)(x[i + 1] - x[i]);
                    double t = (double)(pos - x[i]) * k + y[i];
                    ret += (double)(t + y[i]) * (pos - x[i]) / 2;
                    break;
                }
                else
                {
                    ret += (double)(y[i + 1] + y[i]) * (x[i + 1] - x[i]) / 2;
                }
            }
            return ret;
        }

        static void assert(bool v)
        {
            if (!v)
            {
                throw new Exception();
            }
        }
    }
}
