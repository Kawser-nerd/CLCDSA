import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.lang.reflect.Array;
import java.util.function.BiFunction;
import java.nio.charset.Charset;
import java.util.StringTokenizer;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.function.BinaryOperator;
import java.io.UncheckedIOException;
import java.util.Objects;
import java.io.Writer;
import java.security.AccessControlException;
import java.io.BufferedReader;
import java.util.regex.Pattern;
import java.util.Comparator;
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
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        public void solve(int testNumber, LightScanner in, LightWriter out) {

            Debug.autoEnable();
            long n = in.longs();
            int m = in.ints();
            D.Query[] queries = new D.Query[m];
            for (int i = 0; i < m; i++) {
                queries[i] = new D.Query(i - 1, in.longs(), in.doubles(), in.doubles());
            }
            Arrays.sort(queries, Comparator.comparing(q -> q.machine));
            long last = -1;
            int zip = -1;
            for (int i = 0; i < m; i++) {
                if (queries[i].machine != last) {
                    last = queries[i].machine;
                    zip++;
                }
                queries[i].zip = zip;
            }
            zip++;
            if (zip == 0) {
                out.ans(1).ln().ans(1).ln();
                return;
            }

            Arrays.sort(queries, Comparator.comparing(q -> q.index));
            //*/

            Vec2d[] array = new Vec2d[zip];
            Vec2d unit = new Vec2d(1, 0);
            Arrays.fill(array, unit);

            /*Lazy*/
            SegmentTree<Vec2d, Vec2d> st = new /*Lazy*/SegmentTree<>(
                    array, Vec2d.class, /*Vec2d.class, */(a, b) -> new Vec2d(a.x * b.x, a.y * b.x + b.y), unit, (x, q) -> q
                    //,(q1, q2) -> q2, null
            );
            double max = 1, min = 1;
            for (int i = 0; i < m; i++) {
                int q = queries[i].zip;
                double a = queries[i].a, b = queries[i].b;
                st.update(q, new Vec2d(a, b));
                Vec2d e = st.queryTopdown(0, zip);
                double v = e.x + e.y;
                max = Math.max(max, v);
                min = Math.min(min, v);
            }
            out.ans(min, 7).ln().ans(max, 7).ln();
        }

        private static class Query {
            int index;
            long machine;
            double a;
            double b;
            int zip;

            public Query(int index, long machine, double a, double b) {
                this.index = index;
                this.machine = machine;
                this.a = a;
                this.b = b;
            }

        }

    }

    static class SegmentTree<T, U> {
        private final int n;
        private final int m;
        private final T[] tree;
        private final BinaryOperator<T> op;
        private final T zero;
        private final BiFunction<T, U, T> up;

        public SegmentTree(T[] array, Class<T> clazz, BinaryOperator<T> op, T zero, BiFunction<T, U, T> up) {
            this.n = array.length;
            int msb = BitMath.extractMsb(n);
            this.m = n == msb ? msb : (msb << 1);
            this.tree = ArrayUtil.newInstance(clazz, 2 * m - 1);
            this.op = op;
            this.up = up;
            this.zero = zero;
            Arrays.fill(tree, zero);
            System.arraycopy(array, 0, this.tree, m - 1, array.length);
            for (int i = m - 2; i >= 0; i--) {
                tree[i] = op.apply(tree[2 * i + 1], tree[2 * i + 2]);
            }
        }

        public void update(int i, U v) {
            i += m - 1;
            tree[i] = up.apply(tree[i], v);
            while (i > 0) {
                i = (i - 1) / 2;
                tree[i] = op.apply(tree[2 * i + 1], tree[2 * i + 2]);
            }
        }

        private T query(int l, int r, int k, int sl, int sr) {
            if (r <= sl || sr <= l) {
                return zero;
            }
            if (l <= sl && sr <= r) {
                return tree[k];
            } else {
                T left = query(l, r, 2 * k + 1, sl, (sl + sr) / 2);
                T right = query(l, r, 2 * k + 2, (sl + sr) / 2, sr);
                return op.apply(left, right);
            }
        }

        public T queryTopdown(int l, int r) {
            return query(l, r, 0, 0, m);
        }

    }

    static class Debug {
        private static final String DEBUG_PROPERTY = "debug";
        private static final String DEBUG_CALL_PATTERN = "^.+\\.debug\\((.+)\\);.*$";
        private static Pattern debugRegex;
        private static boolean enabled = false;
        private static String src;

        public static void enable(String s) {
            enabled = true;
            src = s;
            if (debugRegex == null) {
                debugRegex = Pattern.compile(DEBUG_CALL_PATTERN);
            }
        }

        public static boolean autoEnable() {
            try {
                String s = System.getProperty(DEBUG_PROPERTY);
                if (s != null) {
                    enable(s);
                    return true;
                }
            } catch (AccessControlException ex) {
                src = null;
            }
            return false;
        }

    }

    static final class ArrayUtil {
        private ArrayUtil() {
        }

        public static <T> T[] newInstance(Class<T> clazz, int length) {
            return (T[]) Array.newInstance(clazz, length);
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

        public long longs() {
            return Long.parseLong(string());
        }

        public double doubles() {
            return Double.parseDouble(string());
        }

    }

    static final class BitMath {
        private BitMath() {
        }

        public static int extractMsb(int v) {
            v = (v & 0xFFFF0000) > 0 ? v & 0xFFFF0000 : v;
            v = (v & 0xFF00FF00) > 0 ? v & 0xFF00FF00 : v;
            v = (v & 0xF0F0F0F0) > 0 ? v & 0xF0F0F0F0 : v;
            v = (v & 0xCCCCCCCC) > 0 ? v & 0xCCCCCCCC : v;
            v = (v & 0xAAAAAAAA) > 0 ? v & 0xAAAAAAAA : v;
            return v;
        }

    }

    static class Vec2d {
        public final double x;
        public final double y;

        public Vec2d(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Vec2d vec2d = (Vec2d) o;
            return Double.compare(vec2d.x, x) == 0 &&
                    Double.compare(vec2d.y, y) == 0;
        }

        public int hashCode() {
            return Objects.hash(x, y);
        }

        public String toString() {
            return "(" + x + ", " + y + ")";
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

        public LightWriter ans(double x, int n) {
            if (!breaked) {
                print(' ');
            }
            if (x < 0) {
                print('-');
                x = -x;
            }
            x += Math.pow(10, -n) / 2;
            print(Long.toString((long) x)).print('.');
            x -= (long) x;
            for (int i = 0; i < n; i++) {
                x *= 10;
                print((char) ('0' + ((int) x)));
                x -= (int) x;
            }
            return this;
        }

        public LightWriter ans(int i) {
            return ans(Integer.toString(i));
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.