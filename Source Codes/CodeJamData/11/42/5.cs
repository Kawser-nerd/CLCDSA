using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GoogleCodeJam {
    class Round2B {
        public void gen(StreamWriter sw, StreamReader sr) {
            string[] lines = sr.ReadLine().Split(new char[] { ' ' });
            int R = Convert.ToInt32(lines[0]);
            int C = Convert.ToInt32(lines[1]);
            int D = Convert.ToInt32(lines[2]);
            int[,] mass = new int[R, C];
            for (int i = 0; i < R; i++) {
                string l = sr.ReadLine();
                for (int j = 0; j < C; j++)
                    mass[i, j] = (int)(l[j] - '0');
            }
            int[,] sum_m = new int[R + 1, C + 1];
            int[,] sum_r = new int[R + 1, C + 1];
            int[,] sum_c = new int[R + 1, C + 1];
            for (int i = 1; i <= R; i++)
                for (int j = 1; j <= C; j++) {
                    sum_m[i, j] = sum_m[i, j - 1] + sum_m[i - 1, j] - sum_m[i - 1, j - 1] + mass[i - 1, j - 1];
                    sum_r[i, j] = sum_r[i, j - 1] + sum_r[i - 1, j] - sum_r[i - 1, j - 1] + mass[i - 1, j - 1] * i;
                    sum_c[i, j] = sum_c[i, j - 1] + sum_c[i - 1, j] - sum_c[i - 1, j - 1] + mass[i - 1, j - 1] * j;
                }
            int k = 2;
            for (int i = 0; i + k < R; i++)
                for (int j = 0; j + k < R; j++) {
                    for (int d = k; i + d < R && j + d < R; d++) {
                        int s_m = sum_m[i + d + 1, j + d + 1] - sum_m[i, j + d + 1] - sum_m[i + d + 1, j] + sum_m[i, j];
                        int s_r = sum_r[i + d + 1, j + d + 1] - sum_r[i, j + d + 1] - sum_r[i + d + 1, j] + sum_r[i, j];
                        int s_c = sum_c[i + d + 1, j + d + 1] - sum_c[i, j + d + 1] - sum_c[i + d + 1, j] + sum_c[i, j];
                        s_m -= mass[i, j] + mass[i, j + d] + mass[i + d, j] + mass[i + d, j + d];
                        s_r -= (mass[i, j] + mass[i, j + d]) * (i + 1) + (mass[i + d, j] + mass[i + d, j + d]) * (i + d + 1);
                        s_c -= (mass[i, j] + mass[i + d, j]) * (j + 1) + (mass[i, j + d] + mass[i + d, j + d]) * (j + d + 1);
                        if (s_r * 2 == (i + i + d + 2) * s_m && s_c * 2 == (j + j + d + 2) * s_m)
                            k = d + 1;
                    }
                }
            if (k < 3)
                sw.WriteLine("IMPOSSIBLE");
            else
                sw.WriteLine(k);
        }
    }
}
