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
        DColoringDominoes solver = new DColoringDominoes();
        solver.solve(1, in, out);
        out.close();
    }

    static class DColoringDominoes {
        private static final int MOD = (int) 1e9 + 7;

        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints();
            String s1 = in.string(), s2 = in.string();
            int m = 0;
            boolean[] v = new boolean[n];
            int i = 0;
            while (i < n) {
                if (s1.charAt(i) == s2.charAt(i)) {
                    i++;
                } else {
                    v[m] = true;
                    i += 2;
                }
                m++;
            }
            long ans = v[0] ? 6 : 3;
            for (i = 1; i < m; i++) {
                if (v[i]) {
                    if (v[i - 1]) {//??
                        ans *= 3;
                        ans %= MOD;
                    } else {//??
                        ans *= 2;
                        ans %= MOD;
                    }
                } else {
                    if (v[i - 1]) {//??
                        //pass
                    } else {//??
                        ans *= 2;
                        ans %= MOD;
                    }
                }
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

        public int ints() {
            return Integer.parseInt(string());
        }

    }
}