using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GoogleCodeJam {
    class Revenge_of_the_Hot_Dogs {
        public void gen(StreamWriter sw, StreamReader sr) {
            string[] lines = sr.ReadLine().Split(new char[] { ' ' });
            int C = Convert.ToInt32(lines[0]);
            long D = Convert.ToInt64(lines[1]);
            long[] P = new long[C];
            int[] V = new int[C];
            for (int i = 0; i < C; i++) {
                string[] l = sr.ReadLine().Split(new char[] { ' ' });
                P[i] = Convert.ToInt64(l[0]);
                V[i] = Convert.ToInt32(l[1]);
            }
            double sec = (V[0] - 1) * D / 2.0;
            double right = P[0] + sec;
            for (int i = 1; i < C; i++) {
                double si = (V[i] - 1) * D / 2.0;
                double li = P[i] - si, ri = P[i] + si;
                if (li - right >= D) {
                    if (sec > si) {
                        right = ri - Math.Min(li - right - D, sec - si);
                    } else {
                        right = ri;
                        sec = si;
                    }
                } else {
                    if (sec > si) {
                        double d = Math.Min(sec - si, right + D - li);
                        li += d;
                        ri += d;
                    } else {
                        double d = Math.Min(si - sec, right + D - li);
                        right -= d;
                        sec = si;
                    }
                    if (li - right >= D) {
                        right = ri;
                    } else {
                        double t = (D - li + right) / 2.0;
                        sec += t;
                        right = ri + t;
                    }
                }
            }
            sw.WriteLine(sec);
        }
    }
}
