import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.nio.charset.Charset;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.BitSet;
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
        COneStrokePath solver = new COneStrokePath();
        solver.solve(1, in, out);
        out.close();
    }

    static class COneStrokePath {
        private static int n;

        public void solve(int testNumber, LightScanner in, LightWriter out) {
            // out.setBoolLabel(LightWriter.BoolLabel.YES_NO_FIRST_UP);
            n = in.ints();
            int m = in.ints();
            COneStrokePath.Node[] nodes = new COneStrokePath.Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new COneStrokePath.Node(i);
            }
            for (int i = 0; i < m; i++) {
                int a = in.ints() - 1, b = in.ints() - 1;
                nodes[a].neg.add(nodes[b]);
                nodes[b].neg.add(nodes[a]);
            }

            nodes[0].dfs(new BitSet(n));
            long ans = 0;
            for (int i = 0; i < n; i++) {
                ans += nodes[i].ans;
            }
            out.ansln(ans);
        }

        private static class Node {
            int index;
            List<COneStrokePath.Node> neg = new ArrayList<>();
            int ans = 0;

            public Node(int index) {
                this.index = index;
            }

            private void dfs(BitSet bs) {
                bs.set(index);
                if (bs.cardinality() == n) {
                    ans++;
                    return;
                }
                for (COneStrokePath.Node n : neg) {
                    if (bs.get(n.index)) {
                        continue;
                    }
                    BitSet cl = (BitSet) bs.clone();
                    n.dfs(cl);
                }
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

        public LightWriter ansln(long... n) {
            for (long n1 : n) {
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
}