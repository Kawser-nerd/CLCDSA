import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.stream.IntStream;
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
        DPeopleOnALine solver = new DPeopleOnALine();
        solver.solve(1, in, out);
        out.close();
    }

    static class DPeopleOnALine {
        private static final String YES = "Yes";
        private static final String NO = "No";

        public void solve(int testNumber, LightScanner in, LightWriter out) {
            int n = in.ints(), m = in.ints();
            IntWeightedUnionFind uf = new IntWeightedUnionFind(n);
            for (int i = 0; i < m; i++) {
                int l = in.ints() - 1, r = in.ints() - 1, d = in.ints();
                if (!uf.union(l, r, d)) {
                    out.ansln(NO);
                    return;
                }
            }
            out.ansln(YES);
        }

    }

    static class IntWeightedUnionFind {
        private final int[] groups;
        private final int[] rank;
        private final long[] weight;

        public IntWeightedUnionFind(int n) {
            groups = IntStream.range(0, n).toArray();
            rank = new int[n];
            this.weight = new long[n];
        }

        public int find(int i) {
            int parent = groups[i];
            if (parent == i) {
                return i;
            } else {
                int root = find(parent);
                weight[i] += weight[parent];
                return groups[i] = root;
            }
        }

        public long getWeight(int i) {
            find(i);
            return weight[i];
        }

        public long getDistance(int x, int y) {
            return getWeight(y) - getWeight(x);
        }

        public boolean union(int x, int y, long w) {
            w += getWeight(x);
            w -= getWeight(y);
            x = find(x);
            y = find(y);
            if (x == y) {
                return getDistance(x, y) == w;
            } else if (rank[x] < rank[y]) {
                groups[x] = y;
                weight[x] = -w;
            } else if (rank[x] == rank[y]) {
                rank[x]++;
                groups[y] = x;
                weight[y] = w;
            } else {
                groups[y] = x;
                weight[y] = w;
            }
            return true;
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

        public LightWriter ansln(String... n) {
            for (String n1 : n) {
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