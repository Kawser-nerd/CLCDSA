import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.function.IntUnaryOperator;
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
            PersistentUnionFind uf = new PersistentUnionFind(n, m, 2 * m);
            for (int i = 0; i < m; i++) {
                uf.union(in.ints() - 1, in.ints() - 1);
            }

        /* for (int i = 0; i <= m; i++) {
            System.out.println("t=" + i);
            uf.debug(i);
        } */

            int queries = in.ints();
            for (int q = 0; q < queries; q++) {
                int x = in.ints() - 1, y = in.ints() - 1, z = in.ints();
                int min = 0, max = m + 1;
                while (max - min > 1) {
                    int mid = (min + max) / 2;
                    //System.out.println("mid=" + mid);
                    //uf.debug(mid);
                    Vec2i a = uf.findWithSize(x, mid), b = uf.findWithSize(y, mid);
                    int num = a.y;
                    if (a.x != b.x) {
                        num += b.y;
                    }
                    //System.out.println("num=" + num);
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

    static class TimeOutOfBoundsException extends RuntimeException {
        public TimeOutOfBoundsException() {
        }

        public TimeOutOfBoundsException(String message) {
            super(message);
        }

        public TimeOutOfBoundsException(String message, Throwable cause) {
            super(message, cause);
        }

        public TimeOutOfBoundsException(Throwable cause) {
            super(cause);
        }

    }

    static class PersistentIntArray {
        private static final int BASE = 4;
        private static final int MASK = (1 << BASE) - 1;
        private final int n;
        private final int height;
        private int lastUpdate = 0;
        private int[] roots;
        private int newElements;
        private int elementsLength;
        private int[][] nodes;

        public PersistentIntArray(int[] array, int initialTimeCapacity, int initialNodeCapacity) {
            if (array.length == 0) {
                throw new IllegalArgumentException("Empty array is not supported");
            } else if (initialTimeCapacity < 1 || initialNodeCapacity < 1) {
                throw new IllegalArgumentException("Initial capacity must be a positive number");
            }
            n = array.length;
            int log = 1;
            while (n > (1 << (log * BASE))) {
                log++;
            }
            height = log - 1;

            roots = new int[1 + initialTimeCapacity];
            nodes = new int[1 << BASE][nodes(height) + initialNodeCapacity * (height + 1)];
            elementsLength = initialNodeCapacity;
            int i = 0;
            for (; i < nodes(height - 1); i++) {
                for (int j = 0; j < (1 << BASE); j++) {
                    nodes[j][i] = (1 << BASE) * i + j + 1;  // ?????????
                }
            }
            int j = 0;
            for (; j < n; j++) {
                nodes[j & MASK][i + (j >> BASE)] = array[j];       // ????????
            }
            for (; i + (j >> BASE) < nodes(height); j++) {
                nodes[j & MASK][i + (j >> BASE)] = -1;      // ??
            }
            newElements = 0;
        }

        public PersistentIntArray(int[] array) {
            this(array, 1, 1);
        }

        public int get(int i, int t) {
            if (i < 0 || n <= i) {
                throw new ArrayIndexOutOfBoundsException("Index " + i + " is out of bounds");
            } else if (t < 0 || lastUpdate < t) {
                throw new TimeOutOfBoundsException("Time " + t + " is out of bounds");
            }
            int c = roots[t];
            for (int ss = BASE * height; ss >= 0; ss -= BASE) {
                c = nodes[(i >>> ss) & MASK][c];
            }
            return c;
        }

        private void growRoots(int minCapacity) {
            int capacity = roots.length - 1;
            while (capacity < minCapacity) {
                capacity <<= 1;
            }
            roots = Arrays.copyOf(roots, 1 + capacity);
        }

        private void growNodes(int minCapacity) {
            int capacity = elementsLength;
            while (capacity < minCapacity) {
                capacity <<= 1;
            }
            elementsLength = capacity;
            for (int i = 0; i < (1 << BASE); i++) {
                nodes[i] = Arrays.copyOf(nodes[i], nodes(height) + capacity * (height + 1));
            }
        }

        public int set(int i, IntUnaryOperator x, int t, boolean tick) {
            if (i < 0 || n <= i) {
                throw new ArrayIndexOutOfBoundsException("Index " + i + " is out of bounds");
            } else if (t < 0 || lastUpdate < t) {
                throw new TimeOutOfBoundsException("Time " + t + " is out of bounds");
            }
            if (newElements == elementsLength) {
                growNodes(newElements + 1);
            }

            int c = roots[t];
            int d = nodes(height) + newElements * (height + 1);
            if (tick) {
                lastUpdate++;
                if (lastUpdate == roots.length) {
                    growRoots(lastUpdate + 1);
                }
            }
            roots[lastUpdate] = d;
            for (int ss = BASE * height; ss > 0; ss -= BASE) {
                for (int j = 0; j < (1 << BASE); j++) {
                    nodes[j][d] = nodes[j][c];
                }
                nodes[(i >> ss) & MASK][d] = ++d;
                c = nodes[(i >>> ss) & MASK][c];
            }
            for (int j = 0; j < (1 << BASE); j++) {
                nodes[j][d] = nodes[j][c];
            }
            newElements++;
            nodes[i & MASK][d] = x.applyAsInt(nodes[i & MASK][d]);
            return lastUpdate;
        }

        public int set(int i, int x, boolean tick) {
            return set(i, unused -> x, lastUpdate, tick);
        }

        public int set(int t) {
            if (lastUpdate + 1 == roots.length) {
                growRoots(lastUpdate + 1);
            }
            roots[++lastUpdate] = roots[t];
            return newElements;
        }

        public static int nodes(int h) {
            return ((1 << (BASE * (h + 1))) - 1) / ((1 << BASE) - 1);
        }

        public int getLastUpdate() {
            return lastUpdate;
        }

    }

    static class Vec2i implements Comparable<Vec2i> {
        public int x;
        public int y;

        public Vec2i(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Vec2i vec2i = (Vec2i) o;
            return x == vec2i.x && y == vec2i.y;
        }

        public int hashCode() {
            return 31 * x + y;
        }

        public String toString() {
            return "(" + x + ", " + y + ")";
        }

        public int compareTo(Vec2i o) {
            if (x == o.x) {
                return Integer.compare(y, o.y);
            }
            return Integer.compare(x, o.x);
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

    static class PersistentUnionFind {
        private final PersistentIntArray array;

        public PersistentUnionFind(int n, int initialTimeCapacity, int initialNodeCapacity) {
            int[] init = new int[n];
            Arrays.fill(init, -1);
            this.array = new PersistentIntArray(init, initialTimeCapacity, initialNodeCapacity);
        }

        public PersistentUnionFind(int n) {
            int[] init = new int[n];
            Arrays.fill(init, -1);
            this.array = new PersistentIntArray(init);
        }

        public Vec2i findWithSize(int i, int t) {
            int c = array.get(i, t);
            while (c >= 0) {
                i = c;
                c = array.get(i, t);
            }
            return new Vec2i(i, -c);
        }

        public boolean union(int a, int b, int t) {
            Vec2i av = findWithSize(a, t);
            Vec2i bv = findWithSize(b, t);
            if (av.x == bv.x) {
                array.set(array.getLastUpdate());
                return false;
            }
            Vec2i parent, child;
            if (av.y < bv.y) {
                parent = bv;
                child = av;
            } else {
                parent = av;
                child = bv;
            }
            array.set(parent.x, v -> -parent.y - child.y, t, true);
            array.set(child.x, parent.x, false);
            return true;
        }

        public boolean union(int a, int b) {
            return union(a, b, getLastUpdate());
        }

        public int getLastUpdate() {
            return array.getLastUpdate();
        }

    }
}