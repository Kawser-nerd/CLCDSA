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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, MyReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt() - 1;
            }

            BIT bit = new BIT(m + 5);
            long[] fq = new long[m + 5];

            for (int i = 0; i < n - 1; i++) {
                long cost = (a[i + 1] - a[i] - 1 + 2 * m) % m;
                fq[a[i + 1]] += cost;

                if (a[i] == a[i + 1]) {
                } else if (a[i] < a[i + 1]) {
                    bit.add(a[i] + 1, 1);
                    bit.add(a[i + 1], -1);
                } else {
                    bit.add(a[i] + 1, 1);
                    bit.add(m, -1);

                    bit.add(0, 1);
                    bit.add(a[i + 1], -1);
                }
            }

            long base = 0;
            for (int i = 0; i < n - 1; i++) {
                int from = a[i];
                if (a[i + 1] < a[i]) from = -1;
                base += (a[i + 1] - from + m) % m;
            }

            long mi = base;
            long tot = base;
            for (int x2 = 1; x2 < m; x2++) {
                int x = x2 - 1;
                tot += fq[x];
                tot -= bit.getHeadSum(x);
//            System.err.printf("x2 = %s, tot = %s\n", x2, tot);
                mi = Math.min(mi, tot);
            }

            out.println(mi);
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }

    static class BIT {
        private long[] data;
        private int n;

        public BIT(int n) {
            this.n = n;
            data = new long[n + 2];
        }

        public void add(int idx, long val) {
            int idx2 = idx + 1;
            while (idx2 <= n + 1) {
                data[idx2] += val;
                idx2 += (idx2 & -idx2);
            }
        }

        public long getHeadSum(int idx) {
            int idx2 = idx + 1;

            long sum = 0;
            while (idx2 > 0) {
                sum += data[idx2];
                idx2 = idx2 & (idx2 - 1);
            }

            return sum;
        }

    }
}