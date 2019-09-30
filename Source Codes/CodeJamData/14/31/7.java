import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class A {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            System.out.println("Test " + test);

            long p = in.nextLong();
            long q = in.nextLong();
            long d = gcd(p, q);
            p /= d;
            q /= d;

            int p2 = 0;
            boolean good = true;
            while (q > 1) {
                if (q % 2 != 0) {
                    good = false;
                    break;
                }
                q /= 2;
                p2++;
            }

            if (good) {
                while (p > 1) {
                    p /= 2;
                    p2--;
                }
                out("Case #%d: %d\n",test,  p2);
            } else {
                out("Case #%d: impossible\n", test);
            }
        }
    }

    long gcd(long x, long y) {
        while (y != 0) {
            long t = y; y = x % y; x = t;
        }
        return x;
    }
    
    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
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
        new A().run();
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
                    st = new StringTokenizer(br.readLine(), "/");
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