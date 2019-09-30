import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        final int LG = 20;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int x = in.nextInt();
            int k = in.nextInt();
            long[] r = new long[k + 2];
            for (int i = 0; i < k; i++) {
                r[i + 1] = in.nextInt();
            }
            r[k + 1] = 1_000_000_001;
            k += 2;

            long[] sa = new long[k];
            int[] dnext = new int[k];
            boolean[] peak = new boolean[k];
            peak[0] = true;
            int d = -1;
            for (int i = 1; i < k; i++) {
                sa[i] = sa[i - 1] + d * (r[i] - r[i - 1]);
                dnext[i - 1] = d;
                d = -d;
                peak[i] = !peak[i - 1];
            }

            RT rt = new RT(k);
            int[][] next = new int[LG][k + 1];
            next[0][k] = k;
            for (int i = k - 1; i >= 0; i--) {
                if (peak[i]) {
                    int nl = rt.firstL(sa[i] - x);
                    int nr = rt.firstG(sa[i]);
                    next[0][i] = Math.min(nl, nr);
                } else {
                    int nl = rt.firstL(sa[i]);
                    int nr = rt.firstG(sa[i] + x);
                    next[0][i] = Math.min(nl, nr);
                }
                if (i > 0) {
                    rt.update(i, sa[i]);
                }
            }

            for (int p = 1; p < LG; p++) {
                for (int j = 0; j <= k; j++) {
                    next[p][j] = next[p - 1][next[p - 1][j]];
                }
            }

            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                long t = in.nextLong();
                long a = in.nextLong();

                int L = 0;
                int R = k;
                while (L < R - 1) {
                    int M = (L + R) / 2;
                    if (r[M] <= t) {
                        L = M;
                    } else {
                        R = M;
                    }
                }

                int tp = L;

                int nl = rt.firstL(-a);
                int nr = rt.firstG(x - a);
                int np = Math.min(nl, nr);

                long ans;
                if (np <= tp) {
                    int st = LG - 1;
                    while (st >= 0) {
                        if (next[st][np] > tp) {
                            st--;
                        } else {
                            np = next[st][np];
                        }
                    }
                    if (peak[np]) {
                        a = x - sa[np];
                    } else {
                        a = -sa[np];
                    }
                    ans = a + sa[tp] + (t - r[tp]) * dnext[tp];
                } else {
                    ans = a + sa[tp] + (t - r[tp]) * dnext[tp];
                }
                if (ans < 0) {
                    ans = 0;
                }
                if (ans > x) {
                    ans = x;
                }
                out.println(ans);
            }
        }

        class RT {
            int n;
            long[] a;
            long[] b;

            RT(int n) {
                this.n = n;
                a = new long[4 * n];
                Arrays.fill(a, Integer.MAX_VALUE);
                b = new long[4 * n];
                Arrays.fill(b, Integer.MIN_VALUE);
            }

            int firstL(long v) {
                return firstL(0, 0, n, v);
            }

            int firstL(int p, int L, int R, long v) {
                if (a[p] > v) {
                    return n;
                }
                if (L == R - 1) {
                    return L;
                }
                int M = (L + R) / 2;
                if (a[2 * p + 1] > v) {
                    return firstL(2 * p + 2, M, R, v);
                }
                return firstL(2 * p + 1, L, M, v);
            }

            int firstG(long v) {
                return firstG(0, 0, n, v);
            }

            int firstG(int p, int L, int R, long v) {
                if (b[p] < v) {
                    return n;
                }
                if (L == R - 1) {
                    return L;
                }
                int M = (L + R) / 2;
                if (b[2 * p + 1] < v) {
                    return firstG(2 * p + 2, M, R, v);
                }
                return firstG(2 * p + 1, L, M, v);
            }

            void update(int i, long v) {
                update(0, 0, n, i, v);
            }

            void update(int p, int L, int R, int i, long v) {
                if (L == R - 1) {
                    a[p] = b[p] = v;
                    return;
                }

                int M = (L + R) / 2;
                if (i < M) {
                    update(2 * p + 1, L, M, i, v);
                } else {
                    update(2 * p + 2, M, R, i, v);
                }
                a[p] = Math.min(a[2 * p + 1], a[2 * p + 2]);
                b[p] = Math.max(b[2 * p + 1], b[2 * p + 2]);
            }

        }

    }
}