import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class R2 {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;

    public void solveOne(String prefix) throws IOException {
        int c = nextInt();
        int d = nextInt();
        int[] x = new int[c];
        int[] v = new int[c];
        int sum = 0;
        for (int i = 0; i < c; ++i) {
            x[i] = nextInt();
            v[i] = nextInt();
            sum += v[i];
        }
        if (sum == 1) {
            out.println(prefix + " 0.0");
            return;
        }

        double min = 0, max = (double) (sum - 1) * d;
        for (int it = 0; it < 100; ++it) {
            double mid = (min + max) / 2;

            double cx = x[0] - mid;
            boolean ok = true;
            for (int i = 0; i < c; ++i) {
                if (cx < x[i] - mid) {
                    cx = x[i] - mid;
                }
                if (Math.abs(cx - x[i]) > mid) {
                    ok = false;
                    break;
                }
                cx += (double) (d) * (v[i] - 1);
                if (Math.abs(cx - x[i]) > mid) {
                    ok = false;
                    break;
                }
                cx += d;
            }
            if (ok) {
                max = mid;
            } else {
                min = mid;
            }
        }

//        min = Math.round(2 * min) / 2.0;

        out.println(prefix + " " + min);
    }

    public void run() throws IOException {
        in = new BufferedReader(new FileReader("B.in"));
        out = new PrintWriter("B.out");

        int nTests = nextInt();

        for (int i = 1; i <= nTests; ++i) {
            solveOne(String.format("Case #%d:", i));
        }

        out.close();
        in.close();
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static void main(String[] args) throws IOException {
        new R2().run();
    }
}
