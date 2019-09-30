import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.stream.IntStream;
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
        BZL solver = new BZL();
        solver.solve(1, in, out);
        out.close();
    }

    static class BZL {
        public void solve(int testNumber, LightScanner in, LightWriter out) {
            int n = in.ints();
            String s = in.string(), t = in.string();

            boolean[] app = new boolean[26];
            for (int i = 0; i < n; i++) {
                if (isVar(s.charAt(i))) app[s.charAt(i) - 'A'] = true;
                if (isVar(t.charAt(i))) app[t.charAt(i) - 'A'] = true;
            }


            int[] pos = new int[26];
            Arrays.fill(pos, 0b11111_11111);
            UnionFind uf = new UnionFind(26);
            for (int i = 0; i < n; i++) {
                if (isVar(s.charAt(i)) && isVar(t.charAt(i))) {
                    int g1 = uf.find(s.charAt(i) - 'A'), g2 = uf.find(t.charAt(i) - 'A');
                    uf.union(g1, g2);
                    pos[uf.find(g1)] = pos[g1] & pos[g2];
                    if (i == 0) {
                        pos[uf.find(g1)] &= 0b11111_11110;
                    }
                } else if (isVar(s.charAt(i))) {
                    pos[uf.find(s.charAt(i) - 'A')] &= 1 << (t.charAt(i) - '0');
                } else if (isVar(t.charAt(i))) {
                    pos[uf.find(t.charAt(i) - 'A')] &= 1 << (s.charAt(i) - '0');
                }
            }

            long ans = 1;
            for (int i = 0; i < 26; i++) {
                if (uf.find(i) != i || !app[i]) {
                    continue;
                }
                //System.out.println(((char) ('A' + i)) + ": " + BitMath.count(pos[i]));
                ans *= BitMath.count(pos[i]);
            }
            out.ans(ans).ln();
        }

        static boolean isVar(char c) {
            return 'A' <= c && c <= 'Z';
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

    static final class BitMath {
        private BitMath() {
        }

        public static int count(int v) {
            v = (v & 0x55555555) + ((v >> 1) & 0x55555555);
            v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
            v = (v & 0x0f0f0f0f) + ((v >> 4) & 0x0f0f0f0f);
            v = (v & 0x00ff00ff) + ((v >> 8) & 0x00ff00ff);
            v = (v & 0x0000ffff) + ((v >> 16) & 0x0000ffff);
            return v;
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

        public LightWriter ans(long l) {
            return ans(Long.toString(l));
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

    static final class UnionFind {
        private final int[] groups;
        private final int[] rank;

        public UnionFind(int n) {
            groups = IntStream.range(0, n).toArray();
            rank = new int[n];
        }

        public int find(int i) {
            int ans = groups[i];
            if (ans == i) {
                return i;
            } else {
                return groups[i] = find(ans);
            }
        }

        public boolean union(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return false;
            } else if (rank[x] < rank[y]) {
                groups[x] = y;
            } else if (rank[x] == rank[y]) {
                rank[x]++;
                groups[y] = x;
            } else {
                groups[y] = x;
            }
            return true;
        }

    }
}