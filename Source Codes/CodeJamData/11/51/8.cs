using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GoogleCodeJam {
    class Irregular_Cakes {
        public void gen(StreamWriter sw, StreamReader sr) {
            string[] lines = sr.ReadLine().Split(new char[] { ' ' });
            int W = Convert.ToInt32(lines[0]);
            int L = Convert.ToInt32(lines[1]);
            int U = Convert.ToInt32(lines[2]);
            int G = Convert.ToInt32(lines[3]);
            for (int i = 0; i < L; i++) {
                string[] ll = sr.ReadLine().Split(new char[] { ' ' });
                L_X.Add(Convert.ToInt32(ll[0]));
                L_Y.Add(Convert.ToInt32(ll[1]));
            }
            for (int i = 0; i < U; i++) {
                string[] lu = sr.ReadLine().Split(new char[] { ' ' });
                U_X.Add(Convert.ToInt32(lu[0]));
                U_Y.Add(Convert.ToInt32(lu[1]));
            }
            sw.WriteLine();
            double total = area(W);
            for (int i = 1; i < G; i++)
                sw.WriteLine(find_area(total * i / G));
        }
        private List<int> L_X = new List<int>();
        private List<int> L_Y = new List<int>();
        private List<int> U_X = new List<int>();
        private List<int> U_Y = new List<int>();
        private double area(double x) {
            double area_l = 0.0;
            for (int i = 1; i < L_X.Count; i++) {
                if (L_X[i] > x) {
                    double y = (x - L_X[i - 1]) * (L_Y[i] - L_Y[i - 1]) / (L_X[i] - L_X[i - 1]) + L_Y[i - 1];
                    area_l += (x - L_X[i - 1]) * (y + L_Y[i - 1]) / 2.0;
                    break;
                } else {
                    area_l += (L_X[i] - L_X[i - 1]) * (L_Y[i] + L_Y[i - 1]) / 2.0;
                }
            }
            double area_u = 0.0;
            for (int i = 1; i < U_X.Count; i++) {
                if (U_X[i] > x) {
                    double y = (x - U_X[i - 1]) * (U_Y[i] - U_Y[i - 1]) / (U_X[i] - U_X[i - 1]) + U_Y[i - 1];
                    area_u += (x - U_X[i - 1]) * (y + U_Y[i - 1]) / 2.0;
                    break;
                } else {
                    area_u += (U_X[i] - U_X[i - 1]) * (U_Y[i] + U_Y[i - 1]) / 2.0;
                }
            }
            return area_u - area_l;
        }
        private double find_area(double a) {
            double l = 0, r = L_X[L_X.Count - 1];
            while (r - l > 0.00000001) {
                double m = (l + r) / 2.0;
                double am = area(m);
                if (am > a)
                    r = m;
                else
                    l = m;
            }
            return r;
        }
    }
}
