import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.Objects;
import java.util.List;
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
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints(), k = in.ints();
            List<D.E> e = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                e.add(new D.E(in.longs(), in.doubles()));
            }
            D.E ans = new D.E(0L, 0d);
            for (int i = 0; i < k; i++) {
                final D.E y = ans;
                e.sort(Comparator.comparing(x -> -((x.key * x.value + y.key * y.value) / (x.key + y.key))));
                D.E t = e.remove(0);
                ans = new D.E(ans.key + t.key, (t.key * t.value + ans.key * ans.value) / (t.key + ans.key));
            }
            out.println(ans.value);
        }

        private static class E extends Pair<Long, Double> {
            public E(Long key, Double value) {
                super(key, value);
            }

        }

    }

    static class Pair<K, V> {
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
                    "x=" + key +
                    ", y=" + value +
                    '}';
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
}