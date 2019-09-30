import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
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
        DStampRally solver = new DStampRally();
        solver.solve(1, in, out);
        out.close();
    }

    static class DStampRally {
        public void solve(int testNumber, LightScanner in, LightWriter out) {
            int n = in.ints(), m = in.ints();
            if (m == 0) {
                int q = in.ints();
                for (int i = 0; i < q; i++) {
                    out.ansln(-1);
                }
                return;
            }
            PartiallyPersistentUnionFind uf = new PartiallyPersistentUnionFind(n);
            for (int i = 0; i < m; i++) {
                uf.union(in.ints() - 1, in.ints() - 1);
            }

            int queries = in.ints();
            for (int q = 0; q < queries; q++) {
                int x = in.ints() - 1, y = in.ints() - 1, z = in.ints();
                int min = 0, max = m + 1;
                while (max - min > 1) {
                    int mid = (min + max) / 2;

                    int a = uf.find(x, mid), b = uf.find(y, mid);
                    int num = uf.size(a, mid);
                    if (a != b) {
                        num += uf.size(b, mid);
                    }
                    if (num >= z) {
                        max = mid;
                    } else {
                        min = mid;
                    }
                }
                out.ansln(max);
            }
        }

    }

    static class PartiallyPersistentUnionFind {
        private int now = 0;
        private final int[] par;
        private final int[] rank;
        private final int[] time;
        private List<List<PartiallyPersistentUnionFind.Update>> num;

        public PartiallyPersistentUnionFind(int n, int initialCapacity) {
            if (initialCapacity < 1) {
                throw new IllegalArgumentException("Initial capacity must be a positive number");
            }
            par = new int[n];
            rank = new int[n];
            time = new int[n];
            Arrays.fill(time, Integer.MAX_VALUE);
            num = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                par[i] = i;
                num.add(new ArrayList<>(initialCapacity));
                num.get(i).add(new PartiallyPersistentUnionFind.Update(0, 1));
            }
        }

        public PartiallyPersistentUnionFind(int n) {
            this(n, 1);
        }

        public int find(int i, int t) {
            if (t < time[i]) {
                return i;
            } else {
                return find(par[i], t);
            }
        }

        public boolean union(int a, int b) {
            now++;
            a = find(a, now);
            b = find(b, now);
            if (a == b) {
                return false;
            }
            if (rank[a] < rank[b]) {
                int t = a;
                a = b;
                b = t;
            }
            num.get(a).add(new PartiallyPersistentUnionFind.Update(now, size(a, now) + size(b, now)));
            par[b] = a;
            time[b] = now;
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
            return true;
        }

        public int size(int i, int t) {
            i = find(i, t);
            int ok = 0, ng = num.get(i).size();
            while (ng - ok > 1) {
                int mid = (ok + ng) / 2;
                if (num.get(i).get(mid).time <= t) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }

            return num.get(i).get(ok).size;
        }

        private static final class Update {
            int time;
            int size;

            Update(int time, int size) {
                this.time = time;
                this.size = size;
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
}