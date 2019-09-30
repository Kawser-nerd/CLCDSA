using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GoogleCodeJam {
    class RPI {
        public void gen(StreamWriter sw, StreamReader sr) {
            int N = Convert.ToInt32(sr.ReadLine());
            int[,] results = new int[N, N];
            for (int i = 0; i < N; i++) {
                string lines = sr.ReadLine();
                for (int j = 0; j < N; j++)
                    if (lines[j] == '.')
                        results[i, j] = -1;
                    else if (lines[j] == '1')
                        results[i, j] = 1;
            }
            double[] WP = new double[N];
            for (int i = 0; i < N; i++) {
                int total = 0;
                for (int j = 0; j < N; j++)
                    if (results[i, j] >= 0) {
                        total++;
                        if (results[i, j] > 0)
                            WP[i]++;
                    }
                WP[i] /= total;
            }
            double[] OWP = new double[N];
            for (int i = 0; i < N; i++) {
                double[] WP_O = new double[N];
                for (int j = 0; j < N; j++) {
                    if (i == j)
                        continue;
                    int total_O = 0;
                    for (int k = 0; k < N; k++)
                        if (i != k && results[j, k] >= 0) {
                            total_O++;
                            if (results[j, k] > 0)
                                WP_O[j]++;
                        }
                    WP_O[j] /= total_O;
                }
                int total = 0;
                for (int j = 0; j < N; j++)
                    if (results[i, j] >= 0) {
                        total++;
                        OWP[i] += WP_O[j];
                    }
                OWP[i] /= total;
            }
            double[] OOWP = new double[N];
            for (int i = 0; i < N; i++) {
                int total = 0;
                for (int j = 0; j < N; j++)
                    if (results[i, j] >= 0) {
                        total++;
                        OOWP[i] += OWP[j];
                    }
                OOWP[i] /= total;
            }
            sw.WriteLine();
            for (int i = 0; i < N; i++)
                sw.WriteLine(0.25 * WP[i] + 0.5 * OWP[i] + 0.25 * OOWP[i]);
        }
    }
}
