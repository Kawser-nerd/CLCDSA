using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class AAAA : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string[] s = Console.ReadLine().Split(' ');
                int W = int.Parse(s[0]);
                int L = int.Parse(s[1]);
                int U = int.Parse(s[2]);
                int G = int.Parse(s[3]);
                int[] lx = new int[L];
                int[] ly = new int[L];
                int[] ux = new int[U];
                int[] uy = new int[U];
                for (int i = 0; i < L; i++)
                {
                    s = Console.ReadLine().Split(' ');
                    lx[i] = int.Parse(s[0]);
                    ly[i] = int.Parse(s[1]);
                }
                for (int i = 0; i < U; i++)
                {
                    s = Console.ReadLine().Split(' ');
                    ux[i] = int.Parse(s[0]);
                    uy[i] = int.Parse(s[1]);
                }
                string[] sOut = cakeCuts(W, lx, ly, ux, uy, G);
                Console.WriteLine("Case #{0}:", iCase);
                for (int j = 0; j < sOut.Length; j++) {
                    Console.WriteLine(sOut[j]);
                }
            }

            if (bManual) Console.ReadKey();
        }

        private string[] cakeCuts(int W, int[] lx, int[] ly, int[] ux, int[] uy, int G)
        {
            double[] lheight = coordstoheight(lx,ly,W);
            double[] uheight = coordstoheight(ux,uy,W);

            double[] height = new double[W + 1];
            for (int i = 0; i < W+1; i++)
            {
                height[i] = uheight[i] - lheight[i];
            }

            double area = 0;
            for (int i = 0; i < W; i++)
            {
                area += height[i] + height[i + 1];
            }
            //area /= 2;

            double guestarea = area / G;
            double cut = 0;
            string[] ret = new string[G - 1];
            int count = 0;
            while (count < G - 1)
            {
                double min = cut;
                double max = W;
                for (int a = 0; a < 200; a++)
                {
                    double ctry = (min + max) / 2;
                    double tryarea = findArea(height, cut, ctry);
                    if (tryarea > guestarea)
                    {
                        max = ctry;
                    }
                    else
                    {
                        min = ctry;
                    }
                }
                cut = min;
                ret[count] = string.Format("{0:0.000000000}", min);
                count++;
            }
            return ret;
        }

        private double findArea(double[] height, double x0, double x1)
        {
            int l = (int)Math.Floor(x0);
            int r = (int)Math.Ceiling(x1);
            if (r == l + 1) return findLittleArea(height, x0, x1);
            double ret = 0;
            ret += findLittleArea(height, x0, l + 1);
            for (int i = l+1; i <= r-2; i++)
            {
                ret += height[i] + height[i + 1];
            }
            ret += findLittleArea(height, r - 1, x1);
            return ret;
        }

        private double findLittleArea(double[] height, double x0, double x1)
        {
            int x = (int)Math.Floor(x0);
            double grad = height[x + 1] - height[x];
            double y0 = height[x] + grad * (x0-x);
            double y1 = height[x] + grad * (x1-x);
            return (y0 + y1) * (x1 - x0);
        }

        private double[] coordstoheight(int[] x, int[] y, int W)
        {
            double[] ret = new double[W + 1];
            int N = x.Length;
            for (int i = 0; i < N-1; i++)
            {
                double grad = y[i + 1] - y[i];
                grad /= (x[i + 1] - x[i]);
                for (int j = x[i]; j <= x[i+1]; j++)
                {
                    ret[j] = y[i] + grad * (j - x[i]);
                }
            }
            return ret;
        }
    }
}
