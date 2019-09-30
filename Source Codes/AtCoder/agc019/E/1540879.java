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
        static final long MODULO = 998244353;
        static int[] invs;
        static int[] facts;
        static int[] invfacts;

        static {
            int k = (int) 1e4;
            invs = new int[k + 2];
            invs[1] = 1;
            for (int i = 2; i <= k + 1; ++i) {
                invs[i] = (int) ((MODULO - (MODULO / i) * (long) invs[(int) (MODULO % i)] % MODULO) % MODULO);
            }
            facts = new int[k + 2];
            invfacts = new int[k + 2];
            facts[0] = 1;
            invfacts[0] = 1;
            for (int i = 1; i <= k + 1; ++i) {
                facts[i] = (int) (facts[i - 1] * (long) i % MODULO);
                invfacts[i] = (int) (invfacts[i - 1] * (long) invs[i] % MODULO);
            }
        }

        long c(int n, int k) {
            return facts[n] * (long) invfacts[k] % MODULO * (long) invfacts[n - k] % MODULO;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String src = in.next();
            String dst = in.next();
            int maxa = 0;
            int maxb = 0;
            for (int i = 0; i < src.length(); ++i) {
                if (src.charAt(i) == '1') {
                    if (dst.charAt(i) == '1') {
                        ++maxb;
                    } else {
                        ++maxa;
                    }
                }
            }
            long[] w = new long[maxb + 1];
            long[] nw = new long[maxb + 1];
            w[0] = 1;
            for (int a = 1; a <= maxa; ++a) {
                Arrays.fill(nw, 0);
                for (int b = 0; b <= maxb; ++b) {
                    if (a > 0) {
                        nw[b] = (nw[b] + a * (long) a % MODULO * w[b]) % MODULO;
                    }
                    if (a > 0 && b > 0) {
                        nw[b] = (nw[b] + b * (long) a % MODULO * nw[b - 1]) % MODULO;
                    }
                }
                long[] tmp = w;
                w = nw;
                nw = tmp;
            }
            long res = 0;
            for (int k = 0; k <= maxb; ++k) {
                res = (res + w[maxb - k] * c(maxb, k) % MODULO * facts[k] % MODULO * facts[k] % MODULO * c(maxa + maxb, k)) % MODULO;
            }
            out.println(res);
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

    }
}