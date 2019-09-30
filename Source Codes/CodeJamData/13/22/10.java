import gcj.GCJ;

import java.util.Scanner;

public class FallingDiamonds {

    public static void main(String[] args) {
        Scanner s = GCJ.createScanner('B', true);
        int T = s.nextInt();
        for (int i = 1; i <= T; i++) {
            int n = s.nextInt();
            int x = s.nextInt();
            int y = s.nextInt();
            double p = 0;
            int nn = 1;
            int total = 1;
            while (total + nn + 1 + nn + 2 <= n) {
                total += nn + 1 + nn + 2;
                nn += 2;
            }
            int xy = Math.abs(x) + y;
            if (xy < nn) {
                p = 1;
            } else if (xy >= nn + 2) {
                p = 0;
            } else {
                int left = n - total;
                if (left < y + 1) {
                    p = 0;
                } else {
                    nn++;
                    double[][] cand = new double[nn + 1][nn + 1];
                    cand[0][0] = 1;
                    for (int w = 1; w <= left; w++) {
                        for (int u = 0; u < w && u <= nn; u++) {
                            int v = w - u - 1;
                            if (v > nn) {
                                continue;
                            }
                            if (u == nn) {
                                cand[u][v + 1] += cand[u][v];
                            } else if (v == nn) {
                                cand[u + 1][v] += cand[u][v];
                            } else {
                                cand[u + 1][v] += cand[u][v] / 2;
                                cand[u][v + 1] += cand[u][v] / 2;
                            }
                        }
                    }
                    p = 0;
                    for (int u = y + 1; u <= left && u <= nn; u++) {
                        int v = left - u;
                        if (v > nn) {
                            continue;
                        }
                        p += cand[u][v];
                    }
                }
            }
            GCJ.out(i, Double.toString(p));
        }
    }
}
