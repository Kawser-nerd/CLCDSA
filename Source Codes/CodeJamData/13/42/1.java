import java.io.*;
import java.util.StringTokenizer;

public class B {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            System.out.println("Test " + test);

            long n = in.nextInt();
            long p = in.nextLong();

            long L = 0;
            long R = 1L << n;
            while (L < R - 1) {
                long M = (L + R) / 2;
                long q = 1L << (n - 1);
                long t = 1;
                long pl = 0;
                while (M >= t) {
                    pl += q;
                    t = (t + 1) * 2 - 1;
                    q /= 2L;
                }
                if (pl >= p) {
                    R = M;
                } else {
                    L = M;
                }
            }
            long maxg = L;

            L = 0;
            R = 1L << n;
            while (L < R - 1) {
                long M = (L + R) / 2;
                long q = 1L << (n - 1);
                long t = 1;
                long pl = (1L << n) - 1;
                while (M <= (1L << n) - 1 - t) {
                    pl -= q;
                    t = (t + 1) * 2 - 1;
                    q /= 2L;
                }
                if (pl < p) {
                    L = M;
                } else {
                    R = M;
                }
            }
            long maxc = L;


            out("Case #%d: %d %d", test, maxg, maxc);
            out("\n");
        }
    }
    
    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-large.in"));
            out = new PrintWriter(new File("B-large.out"));

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
    }
}