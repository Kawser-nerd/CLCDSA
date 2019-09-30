using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GoogleCodeJam {
    class Round2A {
        public void gen(StreamWriter sw, StreamReader sr) {
            string[] lines = sr.ReadLine().Split(new char[] { ' ' });
            int X = Convert.ToInt32(lines[0]);
            int S = Convert.ToInt32(lines[1]);
            int R = Convert.ToInt32(lines[2]);
            int t = Convert.ToInt32(lines[3]);
            int N = Convert.ToInt32(lines[4]);
            int[] B = new int[N];
            int[] E = new int[N];
            int[] w = new int[N];
            for (int i = 0; i < N; i++) {
                string[] l = sr.ReadLine().Split(new char[] { ' ' });
                B[i] = Convert.ToInt32(l[0]);
                E[i] = Convert.ToInt32(l[1]);
                w[i] = Convert.ToInt32(l[2]);
            }
            int[] L = new int[N + 1];
            int[] W = new int[N + 1];
            L[0] = X;
            W[0] = 0;
            for (int i = 0; i < N; i++) {
                L[i + 1] = E[i] - B[i];
                W[i + 1] = w[i];
                L[0] -= L[i + 1];
            }
            Array.Sort(W, L);
            double res = 0.0, T = t;
            for (int i = 0; i <= N; i++) {
                double r = (L[i] + 0.0) / (W[i] + S);
                if (T > 0) {
                    double s = (L[i] + 0.0) / (W[i] + R);
                    if (s < T) {
                        T -= s;
                        res += s;
                    } else {
                        res += T + (L[i] - T * (W[i] + R)) / (W[i] + S);
                        T = 0;
                    }
                } else {
                    res += r;
                }
            }
            sw.WriteLine(res);
        }
    }
}
