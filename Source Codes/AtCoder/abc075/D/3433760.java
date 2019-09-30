import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Objects;
import java.util.StringTokenizer;
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
        PrintWriter out = new PrintWriter(outputStream);
        DAxisParallelRectangle solver = new DAxisParallelRectangle();
        solver.solve(1, in, out);
        out.close();
    }

    static class DAxisParallelRectangle {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints(), k = in.ints();
            IntPair[] rx = new IntPair[n];
            in.objs(rx, IntPair::new);
            Arrays.sort(rx, Comparator.comparing(r -> r.key));
            IntPair[] ry = rx.clone();
            Arrays.sort(ry, Comparator.comparing(r -> r.value));

            long ans = Long.MAX_VALUE;
            for (int xs = 0; xs <= n - k; xs++) {
                for (int ys = 0; ys <= n - k; ys++) {
                    for (int xe = xs; xe < n; xe++) {
                        for (int ye = ys; ye < n; ye++) {
                            int count = 0;
                            for (int i = xs; i < n; i++) {
                                if (rx[i].key <= rx[xe].key && ry[ys].value <= rx[i].value && rx[i].value <= ry[ye].value) {
                                    count++;
                                }
                            }
                            if (count >= k) {
                                ans = Math.min(ans, (rx[xe].key - rx[xs].key) * (long) (ry[ye].value - ry[ys].value));
                            }
                        }
                    }
                }
            }
            out.println(ans);
        }

    }

    static class IntPair {
        public int key;
        public int value;

        public IntPair(int key, int value) {
            this.key = key;
            this.value = value;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(key, pair.key) &&
                    Objects.equals(value, pair.value);
        }

        public int hashCode() {
            return Objects.hash(key, value);
        }

        public String toString() {
            return "Pair{" +
                    "key=" + key +
                    ", value=" + value +
                    '}';
        }

    }

    static interface BiIntFunction<T> {
        T apply(int t, int u);

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

    static final class Pair<K, V> {
        public K key;
        public V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(key, pair.key) &&
                    Objects.equals(value, pair.value);
        }

        public int hashCode() {
            return Objects.hash(key, value);
        }

        public String toString() {
            return "Pair{" +
                    "key=" + key +
                    ", value=" + value +
                    '}';
        }

    }
}