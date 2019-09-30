import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
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
        BCutAndCount solver = new BCutAndCount();
        solver.solve(1, in, out);
        out.close();
    }

    static class BCutAndCount {
        public void solve(int testNumber, LightScanner in, LightWriter out) {
            // out.setBoolLabel(LightWriter.BoolLabel.YES_NO_FIRST_UP);
            int n = in.ints();
            String s = in.string();
            int a = 0;
            for (int i = 0; i <= s.length(); i++) {
                String x = s.substring(0, i), y = s.substring(i);
                int[][] cnt = new int[2][26];
                for (int j = 0; j < x.length(); j++) {
                    cnt[0][x.charAt(j) - 'a']++;
                }
                for (int j = 0; j < y.length(); j++) {
                    cnt[1][y.charAt(j) - 'a']++;
                }
                int ans = 0;
                for (int j = 0; j < 26; j++) {
                    if (cnt[0][j] > 0 && cnt[1][j] > 0) {
                        ans++;
                    }
                }
                a = Math.max(a, ans);
            }
            out.ansln(a);
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