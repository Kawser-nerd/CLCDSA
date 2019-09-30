using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GoogleCodeJam {
    class Perfect_Harmony {
        public void gen(StreamWriter sw, StreamReader sr) {
            string[] lines = sr.ReadLine().Split(new char[] { ' ' });
            long N = Convert.ToInt64(lines[0]);
            long L = Convert.ToInt64(lines[1]);
            long H = Convert.ToInt64(lines[2]);
            long[] F = new long[N];
            string[] l2 = sr.ReadLine().Split(new char[] {' '});
            for (int i = 0; i < N; i++)
                F[i] = Convert.ToInt64(l2[i]);
            long pos_f = solve(F, L, H);
            if (pos_f == long.MaxValue)
                sw.WriteLine("NO");
            else
                sw.WriteLine(pos_f);
        }
        private long Gcd(long a, long b) {
            if (b == 0)
                return a;
            if (b == 1)
                return 1;
            if (a < b)
                return Gcd(b, a);
            return Gcd(b, a % b);
        }
        private long solve(long[] F, long L, long H) {
            Array.Sort(F);
            if (L < F[0]) {
                long gcd = F[0];
                for (int i = 1; i < F.Length; i++) {
                    if (gcd < L)
                        break;
                    gcd = Gcd(gcd, F[i]);
                }
                if (gcd >= L) {
                    long pos_f = gcd;
                    for (long k = 1; k * k <= gcd; k++)
                        if (gcd % k == 0) {
                            if (k >= L && k <= H)
                                pos_f = Math.Min(pos_f, k);
                            if (gcd / k >= L && gcd / k <= H)
                                pos_f = Math.Min(pos_f, gcd / k);
                        }
                    return pos_f;
                }
            }
            long gdc = 1;
            for (int i = 0; i < F.Length; i++) {
                if (F[i] > H)
                    break;
                if (F[i] >= L) {
                    bool possible = true;
                    for (int j = 0; j < F.Length; j++)
                        if (F[i] % F[j] != 0 && F[j] % F[i] != 0) {
                            possible = false;
                            break;
                        }
                    if (possible)
                        return F[i];
                }
                long mul = F[i] / Gcd(gdc, F[i]);
                if (gdc > H / mul) {
                    gdc = H + 1;
                } else {
                    gdc *= mul;
                }
                if (i != F.Length - 1) {
                    if (F[i + 1] <= L)
                        continue;
                    if (F[i + 1] > gdc) {
                        long gcd = F[i + 1];
                        for (int j = i + 2; j < F.Length; j++) {
                            gcd = Gcd(gcd, F[j]);
                            if (gcd < gdc)
                                break;
                        }
                        if (gcd % gdc == 0) {
                            long pos_f = gdc;
                            for (; pos_f <= gcd; pos_f += gdc)
                                if (pos_f < L)
                                    continue;
                                else if (pos_f > H)
                                    break;
                                else if (gcd % pos_f != 0)
                                    continue;
                                else
                                    return pos_f;
                        }
                    }
                } else {
                    if (gdc <= H) {
                        if (gdc >= L)
                            return gdc;
                        else if (L % gdc == 0)
                            return L;
                        else {
                            gdc *= L / gdc + 1;
                            if (gdc <= H)
                                return gdc;
                        }
                    }
                }
            }
            return long.MaxValue;
        }
    }
}
