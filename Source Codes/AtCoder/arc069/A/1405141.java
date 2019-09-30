import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author toshif
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyReader in = new MyReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        private long n;
        private long m;

        public void solve(int testNumber, MyReader in, PrintWriter out) {
            n = in.nextLong();
            m = in.nextLong();

            long lo = 0, hi = (long) 1E12 + 5L;

            while (hi - lo > 1) {
                long mid = (lo + hi) / 2;
                if (ok(mid)) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            if (ok(hi)) {
                out.println(hi);
            } else {
                out.println(lo);
            }
        }

        boolean ok(long mid) {
            long s = n;
            long c = m;

            if (s < mid) {
                c -= 2 * (mid - s);
            }

            if (c < 0) return false;

            if (c < 2 * mid) return false;

            return true;
        }

    }

    static class MyReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public MyReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}