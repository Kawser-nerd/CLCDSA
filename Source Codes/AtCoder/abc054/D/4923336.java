import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.nio.charset.Charset;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
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
        LightWriter out = new LightWriter(outputStream);
        DMixingExperiment solver = new DMixingExperiment();
        solver.solve(1, in, out);
        out.close();
    }

    static class DMixingExperiment {
        public void solve(int testNumber, LightScanner in, LightWriter out) {
            // out.setBoolLabel(LightWriter.BoolLabel.YES_NO_FIRST_UP);
            int n = in.ints(), ma = in.ints(), mb = in.ints();
            DMixingExperiment.Drug[] drugs = new DMixingExperiment.Drug[n];
            for (int i = 0; i < n; i++) {
                drugs[i] = new DMixingExperiment.Drug(in.ints(), in.ints(), in.ints());
            }

            int[][][] dp = new int[n + 1][401][401];
            ArrayUtil.fill(dp, 4001);
            dp[0][0][0] = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= 400; j++) {
                    for (int k = 0; k <= 400; k++) {
                        dp[i + 1][j][k] = dp[i][j][k];
                        if (j - drugs[i].a < 0 || k - drugs[i].b < 0) continue;
                        dp[i + 1][j][k] = Math.min(dp[i + 1][j][k], dp[i][j - drugs[i].a][k - drugs[i].b] + drugs[i].c);
                    }
                }
            }

            int ans = 4001;
            for (int i = 1; i * ma <= 400 && i * mb <= 400; i++) {
                ans = Math.min(ans, dp[n][i * ma][i * mb]);
            }
            out.ansln(ans > 4000 ? -1 : ans);
        }

        private static class Drug {
            int a;
            int b;
            int c;

            public Drug(int a, int b, int c) {
                this.a = a;
                this.b = b;
                this.c = c;
            }

        }

    }

    static final class ArrayUtil {
        private ArrayUtil() {
        }

        public static void fill(int[] a, int v) {
            Arrays.fill(a, v);
        }

        public static void fill(int[][] a, int v) {
            for (int i = 0; i < a.length; i++) {
                fill(a[i], v);
            }
        }

        public static void fill(int[][][] a, int v) {
            for (int i = 0; i < a.length; i++) {
                fill(a[i], v);
            }
        }

    }

    static class LightWriter implements AutoCloseable {
        private final Writer out;
        private boolean autoflush = false;
        private boolean breaked = true;

        public LightWriter(Writer out) {
            this.out = out;
        }

        public LightWriter(OutputStream out) {
            this(new BufferedWriter(new OutputStreamWriter(out, Charset.defaultCharset())));
        }

        public LightWriter print(char c) {
            try {
                out.write(c);
                breaked = false;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            return this;
        }

        public LightWriter print(String s) {
            try {
                out.write(s, 0, s.length());
                breaked = false;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            return this;
        }

        public LightWriter ans(String s) {
            if (!breaked) {
                print(' ');
            }
            return print(s);
        }

        public LightWriter ans(int i) {
            return ans(Integer.toString(i));
        }

        public LightWriter ansln(int... n) {
            for (int n1 : n) {
                ans(n1).ln();
            }
            return this;
        }

        public LightWriter ln() {
            print(System.lineSeparator());
            breaked = true;
            if (autoflush) {
                try {
                    out.flush();
                } catch (IOException ex) {
                    throw new UncheckedIOException(ex);
                }
            }
            return this;
        }

        public void close() {
            try {
                out.close();
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
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