import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int nq = in.nextInt();
            long[] q = new long[nq + 1];
            q[0] = n;
            for (int i = 0; i < nq; ++i) {
                q[i + 1] = in.nextLong();
            }
            int ptr = 0;
            for (int i = 0; i <= nq; ++i) {
                q[ptr++] = q[i];
                while (ptr >= 2 && q[ptr - 1] <= q[ptr - 2]) {
                    q[ptr - 2] = q[ptr - 1];
                    --ptr;
                }
            }
            q = Arrays.copyOf(q, ptr);
            long[] toPropagate = new long[ptr];
            toPropagate[ptr - 1] = 1;
            long[] res = new long[n + 1];
            for (int i = ptr - 1; i >= 0; --i) {
                long val = q[i];
                int upto = i;
                long prop = toPropagate[i];
                while (true) {
                    int at = Arrays.binarySearch(q, 0, upto, val);
                    if (at < 0) {
                        at = -at - 2;
                    }
                    if (at < 0) break;
                    long whole = val / q[at];
                    toPropagate[at] += prop * whole;
                    upto = at;
                    val %= q[at];
                }
                res[0] += prop;
                res[((int) val)] -= prop;
            }
            for (int i = 1; i < n; ++i) {
                res[i] += res[i - 1];
            }
            for (int i = 0; i < n; ++i) {
                out.println(res[i]);
            }
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}