import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    class P {
        int i;
        long r;
        long h;

        public P(int i, long r, long h) {
            this.i = i;
            this.r = r;
            this.h = h;
        }

        public String toString() {
            return "r = " + r + ", h = " + h;
        }
    }

    public void solve() throws IOException {
        int testNo = in.nextInt();

        for (int test = 1; test <= testNo; test++) {
            int n = in.nextInt();
            int k = in.nextInt();
            double ans = 0;

            P[] p = new P[n];
            for (int i = 0; i < n; i++) {
                p[i] = new P(i, in.nextInt(), in.nextInt());
            }

            Arrays.sort(p, new Comparator<P>() {
                @Override
                public int compare(P o1, P o2) {
                    return o1.r < o2.r || o1.r == o2.r && o1.i < o2.i ? -1 : o1.i == o2.i ? 0 : 1;
                }
            });

            for (int i = k - 1; i < n; i++) {
                P[] q = new P[i];
                for (int j = 0; j < i; j++) {
                    q[j] = p[j];
                }

                Arrays.sort(q, new Comparator<P>() {
                    @Override
                    public int compare(P o1, P o2) {
                        return o1.r * o1.h > o2.r * o2.h || o1.r * o1.h == o2.r * o2.h && o1.i < o2.i ? -1 : o1.i == o2.i ? 0 : 1;
                    }
                });

                double val = 0;
                for (int j = 0; j < k - 1; j++) {
                    val += 2 * Math.PI * q[j].r * q[j].h;
                }
                val += 2 * Math.PI * p[i].r * p[i].h + Math.PI * p[i].r * p[i].r;

                if (val > ans) {
                    ans = val;
                }

            }
            System.out.println("Case #" + test + ": " + ans);
            out.println("Case #" + test + ": " + ans);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("A-large.in"));
            out = new PrintWriter(new File("A-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        Locale.setDefault(Locale.US);
        new A().run();
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
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}