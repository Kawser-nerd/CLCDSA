import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        LightScanner in = new LightScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DWeLoveABC solver = new DWeLoveABC();
        solver.solve(1, in, out);
        out.close();
    }

    static class DWeLoveABC {
        private static final int MOD = (int) 1e9 + 7;

        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            String s = in.string();
            int n = s.length();

            long[] pow = new long[n + 1];
            pow[0] = 1;
            for (int i = 1; i <= n; i++) {
                pow[i] = (pow[i - 1] * 3) % MOD;
            }

            int[] a = new int[n + 2];
            int[] c = new int[n + 2];
            int[] q = new int[n + 2];
            for (int i = 0; i < n; i++) {
                a[i + 1] = a[i] + (s.charAt(i) == 'A' ? 1 : 0);
                c[i + 1] = c[i] + (s.charAt(i) == 'C' ? 1 : 0);
                q[i + 1] = q[i] + (s.charAt(i) == '?' ? 1 : 0);
            }
            a[n + 1] = a[n];
            c[n + 1] = c[n];
            q[n + 1] = q[n];

            long ans = 0;
            for (int i = 0; i < n; i++) {
                int d = q[n + 1];
                if (s.charAt(i) == 'A' || s.charAt(i) == 'C') {
                    continue;
                } else if (s.charAt(i) == '?') {
                    d--;
                }
                ans += pow[d] * a[i] * (c[n + 1] - c[i + 1]);
                ans %= MOD;
                ans += pow[Math.max(d - 1, 0)] * a[i] * (q[n + 1] - q[i + 1]);
                ans %= MOD;
                ans += pow[Math.max(d - 1, 0)] * q[i] * (c[n + 1] - c[i + 1]);
                ans %= MOD;
                ans += pow[Math.max(d - 2, 0)] * q[i] * (q[n + 1] - q[i + 1]);
                ans %= MOD;
            }
            out.println(ans);
        }

    }

    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }
            return tokenizer.nextToken();
        }

    }
}