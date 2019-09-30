import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
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
        PrintWriter out = new PrintWriter(outputStream);
        DJoisinosTravel solver = new DJoisinosTravel();
        solver.solve(1, in, out);
        out.close();
    }

    static class DJoisinosTravel {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            int n = in.ints(), m = in.ints(), r = in.ints();
            int[] d = in.ints(r);
            AdjacencyMatrix g = new AdjacencyMatrix(n);
            for (int i = 0; i < m; i++) {
                g.addEdge(in.ints() - 1, in.ints() - 1, in.ints());
            }
            g.shorten();

            int[] u = IntStream.range(0, r).toArray();
            int ans = Integer.MAX_VALUE;
            do {
                int t = 0;
                for (int i = 1; i < r; i++) {
                    t += g.getWeightBetween(d[u[i - 1]] - 1, d[u[i]] - 1);
                }
                ans = Math.min(ans, t);
            } while ((u = Permutation.nextPermutation(u)) != null);
            out.println(ans);
        }

    }

    static final class AdjacencyMatrix implements Graph {
        private static final int INF = 0x2fffffff;
        private final int n;
        private final long[][] matrix;

        public AdjacencyMatrix(int n) {
            this.n = n;
            this.matrix = new long[n][n];
            ArrayUtil.fill(matrix, INF);
        }

        public void addDirectedEdge(int from, int to, long weight) {
            matrix[from][to] = weight;
        }

        public long getWeightBetween(int from, int to) {
            return matrix[from][to];
        }

        public void shorten() {
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix.length; j++) {
                    for (int k = 0; k < matrix.length; k++) {
                        matrix[j][k] = Math.min(matrix[j][k], matrix[j][i] + matrix[i][k]);
                    }
                }
            }
        }

    }

    static final class Permutation {
        private Permutation() {
        }

        public static int[] nextPermutation(int[] a) {
            if (a == null || a.length < 2) {
                return null;
            }
            int p = 0;
            for (int i = a.length - 2; i >= 0; i--) {
                if (a[i] < a[i + 1]) {
                    p = i;
                    break;
                }
            }
            int q = 0;
            for (int i = a.length - 1; i > p; i--) {
                if (a[i] > a[p]) {
                    q = i;
                    break;
                }
            }
            if (p == 0 && q == 0) {
                return null;
            }
            int temp = a[p];
            a[p] = a[q];
            a[q] = temp;
            ArrayUtil.reverse(a, p + 1, a.length - 1);
            return a;
        }

    }

    static interface Graph {
        void addDirectedEdge(int from, int to, long weight);

        default void addEdge(int one, int other, long weight) {
            addDirectedEdge(one, other, weight);
            addDirectedEdge(other, one, weight);
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

        public int[] ints(int length) {
            return IntStream.range(0, length).map(x -> ints()).toArray();
        }

    }

    static final class ArrayUtil {
        private ArrayUtil() {
        }

        public static void fill(long[] a, long v) {
            Arrays.fill(a, v);
        }

        public static void fill(long[][] a, long v) {
            for (int i = 0; i < a.length; i++) {
                fill(a[i], v);
            }
        }

        public static void reverse(int[] a, int left, int right) {
            while (left < right) {
                int temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                left++;
                right--;
            }
        }

    }
}