import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

class B implements Runnable {
    public final int MOD = 10009;

    class Monom implements Comparable<Monom> {
        long d;
        int a;

        Monom(long d, int a) {
            this.d = d;
            this.a = a;
        }

        public int compareTo(Monom o) {
            return d < o.d ? -1 : d > o.d ? 1 : 0;
        }
    }

    Monom[] compress(Monom[] v) {
        Arrays.sort(v);
        int j = 0;
        for (int i = 0; i < v.length; i++) {
            if (i == 0 || v[i].d != v[i - 1].d) {
                v[j++] = v[i];
            } else {
                v[j - 1].a = (v[j - 1].a + v[i].a) % MOD;
            }
        }
        Monom[] r = new Monom[j];
        System.arraycopy(v, 0, r, 0, j);
        return r;
    }

    Monom[] mulpoly(Monom[] v, Monom[] w) {
        Monom[] r = new Monom[v.length * w.length];
        int k = 0;
        for (int i = 0; i < v.length; i++) {
            for (int j = 0; j < w.length; j++) {
                r[k++] = new Monom(v[i].d + w[j].d, v[i].a * w[j].a % MOD);
            }
        }
        r = compress(r);
        System.err.println(r.length);
        return r;
    }

    int calc(Monom[] v, int[] deg, int nc) {
        int r = 0;
        for (int i = 0; i < v.length; i++) {
            int t = 1;
            for (int j = 0; j < nc; j++) {
                int d = (int) ((v[i].d >> (16 * j)) & 0xffff);
                for (int q = 0; q < deg[j]; q++) {
                    t = (t * d) % MOD;
                }
            }
            r = (r + t * v[i].a) % MOD;
        }
        return r;
    }

    public void solve() throws IOException {
        Scanner in = new Scanner(new File("B-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new File("B-small-attempt0.out"));

        int testn = in.nextInt();
        for (int test = 0; test < testn; test++) {
            String poly = in.next();
            int K = in.nextInt();
            int n = in.nextInt();
            String[] w = new String[n];
            for (int i = 0; i < n; i++) {
                w[i] = in.next();
            }

            int[] ans = new int[K];
            StringTokenizer st = new  StringTokenizer(poly, "+");
            while (st.hasMoreTokens()) {
                String monom = st.nextToken();
                char[] cc = monom.toCharArray();
                int[] deg = new int[cc.length];
                Arrays.sort(cc);

                int nc = 0;
                for (int i = 0; i < cc.length; i++) {
                    if (i == 0 || cc[i] != cc[i - 1]) {
                        cc[nc++] = cc[i];
                        deg[nc - 1] = 1;
                    } else {
                        deg[nc - 1]++;
                    }
                }

                Monom[] v = new Monom[n];
                for (int i = 0; i < n; i++) {
                    v[i] = new Monom(0, 1);
                    for (int k = 0; k < w[i].length(); k++) {
                        for (int j = 0; j < nc; j++) {
                            if (w[i].charAt(k) == cc[j]) {
                                v[i].d += 1L << (16 * j);
                            }
                        }
                    }
                }
                v = compress(v);
                ans[0] = (ans[0] + calc(v, deg, nc)) % MOD;
                Monom[] u = v.clone();
                for (int i = 1; i < K; i++) {
                    u = mulpoly(u, v);
                    ans[i] = (ans[i] + calc(u, deg, nc)) % MOD;
                }
            }


            System.out.print("Case #" + (test + 1) + ":");
            out.print("Case #" + (test + 1) + ":");
            for (int i = 0; i < K; i++) {
                System.out.print(" " + ans[i]);
                out.print(" " + ans[i]);
            }
            out.println();
            System.out.println();
        }

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
            throw new AssertionError();
        }
    }

    public static void main(String[] args) {
        new Thread(new B()).start();
    }
}