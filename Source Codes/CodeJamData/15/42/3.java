import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {
    FastScanner in;
    PrintWriter out;

    class S {
        double r;
        double c;

        public S(double r, double c) {
            this.r = r;
            this.c = c;
        }
    }

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            int n = in.nextInt();
            double v = in.nextDouble();
            double x = in.nextDouble();

            S[] s = new S[n];
            for (int i = 0; i < n; i++) {
                s[i] = new S(in.nextDouble(), in.nextDouble());
            }

            double sumrcp = 0, sumrcn = 0;
            double sumrvp = 0, sumrvn = 0, sumrvz = 0;
            for (int i = 0; i < n; i++) {
                if (s[i].c > x) {
                    sumrcp += s[i].r * (s[i].c - x);
                    sumrvp += s[i].r;
                } else if (s[i].c < x) {
                    sumrcn += s[i].r * (x - s[i].c);
                    sumrvn += s[i].r;
                } else {
                    sumrvz += s[i].r;
                }
            }

            double alphap = 1;
            double alphan = 1;
            if (sumrcp > sumrcn) {
                if (sumrcp > 0) {
                    alphap = sumrcn / sumrcp;
                }
            } else {
                if (sumrcn > 0) {
                    alphan = sumrcp / sumrcn;
                }
            }
            double vol = sumrvp * alphap + sumrvn * alphan + sumrvz;

            if (vol == 0) {
                out("Case #%d: IMPOSSIBLE\n", test);
            } else {
                double ans = v / vol;
                out("Case #%d: %.20f\n", test, ans);
            }
        }
    }

    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-small-attempt0.in"));
            out = new PrintWriter(new File("B-small-attempt0.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new B().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}