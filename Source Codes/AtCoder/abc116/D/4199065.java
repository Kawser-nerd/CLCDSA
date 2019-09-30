import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.PriorityQueue;
import java.util.HashMap;
import java.util.AbstractCollection;
import java.nio.charset.Charset;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.io.Writer;
import java.io.BufferedReader;
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
        DVariousSushi solver = new DVariousSushi();
        solver.solve(1, in, out);
        out.close();
    }

    static class DVariousSushi {
        public void solve(int testNumber, LightScanner in, LightWriter out) {
            int n = in.ints();
            int k = in.ints();
            Vec2i[] vs = new Vec2i[n];
            in.objs(vs, Vec2i::new);
            IntroSort.sort(vs, Comparator.comparing(e -> -e.y));
            Map<Integer, Integer> max = new HashMap<>();
            PriorityQueue<Integer> removable = new PriorityQueue<>();
            PriorityQueue<Integer> addable = new PriorityQueue<>(Comparator.reverseOrder());
            long t = 0;
            for (int i = 0; i < k; i++) {
                t += vs[i].y;
                if (!max.containsKey(vs[i].x)) {
                    max.put(vs[i].x, vs[i].y);
                } else {
                    removable.add(vs[i].y);
                }
            }
            //System.out.println(Arrays.toString(vs));
            long v = max.size();
            long ans = t + v * v;
            for (int i = k; i < n; i++) {
                if (!max.containsKey(vs[i].x)) {
                    max.put(vs[i].x, vs[i].y);
                    addable.add(vs[i].y);
                }
            }
            //System.out.println(addable);
            //System.out.println(removable);
            for (long d = v + 1; d <= n; d++) {
                //System.out.println("d=" + d + " add=" + addable.size() + " rem=" + removable.size());
                if (addable.isEmpty() || removable.isEmpty()) {
                    break;
                }
                t -= removable.poll();
                t += addable.poll();
                ans = Math.max(ans, t + d * d);
                //System.out.println("ans=" + ans);
            }
            out.ans(ans).ln();
        }

    }

    static final class ArrayUtil {
        private ArrayUtil() {
        }

        public static <T> void swap(T[] a, int x, int y) {
            T t = a[x];
            a[x] = a[y];
            a[y] = t;
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

    static class HeapSort {
        private HeapSort() {
        }

        private static <T> void heapfy(T[] a, int low, int high, int i, T val, Comparator<? super T> comparator) {
            int child = 2 * i - low + 1;
            while (child < high) {
                if (child + 1 < high && comparator.compare(a[child], a[child + 1]) < 0) {
                    child++;
                }
                if (comparator.compare(val, a[child]) >= 0) {
                    break;
                }
                a[i] = a[child];
                i = child;
                child = 2 * i - low + 1;
            }
            a[i] = val;
        }

        static <T> void sort(T[] a, int low, int high, Comparator<T> comparator) {
            for (int p = (high + low) / 2 - 1; p >= low; p--) {
                heapfy(a, low, high, p, a[p], comparator);
            }
            while (high > low) {
                high--;
                T pval = a[high];
                a[high] = a[0];
                heapfy(a, low, high, 0, pval, comparator);
            }
        }

    }

    static class IntroSort {
        private static int INSERTIONSORT_THRESHOLD = 16;

        private IntroSort() {
        }

        static <T> void sort(T[] a, int low, int high, int maxDepth, Comparator<T> comparator) {
            while (high - low > INSERTIONSORT_THRESHOLD) {
                if (maxDepth-- == 0) {
                    HeapSort.sort(a, low, high, comparator);
                    return;
                }
                int cut = QuickSort.step(a, low, high, comparator);
                sort(a, cut, high, maxDepth, comparator);
                high = cut;
            }
            InsertionSort.sort(a, low, high, comparator);
        }

        public static <T> void sort(T[] a, Comparator<T> comparator) {
            sort(a, 0, a.length, 2 * BitMath.msb(a.length), comparator);
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

        public static int msb(int v) {
            if (v == 0) {
                throw new IllegalArgumentException("Bit not found");
            }
            v |= (v >> 1);
            v |= (v >> 2);
            v |= (v >> 4);
            v |= (v >> 8);
            v |= (v >> 16);
            return count(v) - 1;
        }

    }

    static class Vec2i {
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

        public <T> void objs(T[] array, BiIntFunction<T> constructor) {
            for (int i = 0; i < array.length; i++) {
                array[i] = constructor.apply(ints(), ints());
            }
        }

    }

    static interface BiIntFunction<T> {
        T apply(int t, int u);

    }

    static class QuickSort {
        private QuickSort() {
        }

        private static <T> void med(T[] a, int low, int x, int y, int z, Comparator<? super T> comparator) {
            if (comparator.compare(a[z], a[x]) < 0) {
                ArrayUtil.swap(a, low, x);
            } else if (comparator.compare(a[y], a[z]) < 0) {
                ArrayUtil.swap(a, low, y);
            } else {
                ArrayUtil.swap(a, low, z);
            }
        }

        static <T> int step(T[] a, int low, int high, Comparator<? super T> comparator) {
            int x = low + 1, y = low + (high - low) / 2, z = high - 1;
            if (comparator.compare(a[x], a[y]) < 0) {
                med(a, low, x, y, z, comparator);
            } else {
                med(a, low, y, x, z, comparator);
            }

            int lb = low + 1, ub = high;
            while (true) {
                while (comparator.compare(a[lb], a[low]) < 0) {
                    lb++;
                }
                ub--;
                while (comparator.compare(a[low], a[ub]) < 0) {
                    ub--;
                }
                if (lb >= ub) {
                    return lb;
                }
                ArrayUtil.swap(a, lb, ub);
                lb++;
            }
        }

    }

    static class InsertionSort {
        private InsertionSort() {
        }

        static <T> void sort(T[] a, int low, int high, Comparator<? super T> comparator) {
            for (int i = low; i < high; i++) {
                for (int j = i; j > low && comparator.compare(a[j - 1], a[j]) > 0; j--) {
                    ArrayUtil.swap(a, j - 1, j);
                }
            }
        }

    }
}