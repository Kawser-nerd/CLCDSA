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
            SemiPersistentUnionFind uf = new SemiPersistentUnionFind(n);
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
            //uf.debug();
        }

    }

    static class SemiPersistentUnionFind {
        private int now = 0;
        private final int[] par;
        private final int[] rank;
        private final int[] time;
        private final int[] updateCount;
        private final int[][] updateTime;
        private final int[][] updateSize;

        public SemiPersistentUnionFind(int n, int initialCapacity) {
            if (initialCapacity < 1) {
                throw new IllegalArgumentException("Initial capacity must be a positive number");
            }
            par = IntStream.range(0, n).toArray();
            rank = new int[n];
            time = new int[n];
            Arrays.fill(time, Integer.MAX_VALUE);

            updateCount = new int[n];
            Arrays.fill(updateCount, 1);
            updateTime = new int[n][];
            updateSize = new int[n][];
            for (int i = 0; i < n; i++) {
                updateTime[i] = new int[initialCapacity];
                updateSize[i] = new int[initialCapacity];
                updateSize[i][0] = 1;
            }
        }

        public SemiPersistentUnionFind(int n) {
            this(n, 4);
        }

        public int find(int i, int t) {
            while (time[i] <= t) {
                i = par[i];
            }
            return i;
        }

        public int union(int a, int b) {
            now++;
            a = find(a, now);
            b = find(b, now);
            if (a == b) {
                return now;
            }
            if (rank[a] < rank[b]) {
                int t = a;
                a = b;
                b = t;
            }
            par[a] += par[b];

            int newSize = size(a) + size(b);
            if (updateCount[a] >= updateTime[a].length) {
                updateTime[a] = Arrays.copyOf(updateTime[a], updateTime[a].length << 1);
                updateSize[a] = Arrays.copyOf(updateSize[a], updateSize[a].length << 1);
            }
            updateTime[a][updateCount[a]] = now;
            updateSize[a][updateCount[a]] = newSize;
            updateCount[a]++;

            par[b] = a;
            time[b] = now;
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
            return now;
        }

        public int size(int i, int t) {
            i = find(i, t);
            int ok = 0, ng = updateCount[i];
            while (ng - ok > 1) {
                int mid = (ok + ng) / 2;
                if (updateTime[i][mid] <= t) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            return updateSize[i][ok];
        }

        public int size(int i) {
            return updateSize[i][updateCount[i] - 1];
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