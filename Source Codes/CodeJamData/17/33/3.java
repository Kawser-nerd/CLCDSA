import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class C1 {
    FastScanner in;
    PrintWriter out;

    double EPS = 1e-9;

    public void solve() throws IOException {
        int testNo = in.nextInt();

        for (int test = 1; test <= testNo; test++) {

            int n = in.nextInt();
            int k = in.nextInt();

            double u = in.nextDouble();
            double[] p = new double[n];
            for (int i = 0; i < n; i++) {
                p[i] = in.nextDouble();
            }

            if (n != k) {
                System.out.println("Fuck you");
                continue;
            }

            while (u > EPS) {
                Arrays.sort(p);

                int t = n;
                for (int i = 0; i < n - 1; i++) {
                    if (p[i] < p[i + 1] - EPS) {
                        t = i + 1;
                        break;
                    }
                }

                double z;
                if (t == n) {
                    z = 1;
                } else {
                    z = p[t];
                }

                double dv = z - p[0];
                if (dv * t > u) {
                    dv = u / t;
                }

                for (int i = 0; i < t; i++) {
                    p[i] += dv;
                }
                u -= dv * t;
            }

            double ans = 1;
            for (int i = 0; i < n; i++) {
                ans *= p[i];
            }

            out.println("Case #" + test + ": " + ans);
            System.out.println("Case #" + test + ": " + ans);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("C-small-1-attempt0.in"));
            out = new PrintWriter(new File("C-small-1-attempt0.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        Locale.setDefault(Locale.US);
        new C1().run();
    }

    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
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
        double nextDouble() {
            return Double.parseDouble(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}