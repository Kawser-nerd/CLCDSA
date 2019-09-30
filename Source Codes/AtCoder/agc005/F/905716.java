import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        static final long MODULO = 924844033;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            TaskF.Vertex[] vs = new TaskF.Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new TaskF.Vertex();
            }
            for (int i = 0; i < n - 1; ++i) {
                TaskF.Vertex a = vs[in.nextInt() - 1];
                TaskF.Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            vs[0].initSizes();

            long[] invs = new long[n + 1];
            invs[1] = 1;
            for (int i = 2; i < invs.length; ++i) {
                invs[i] = (MODULO - (MODULO / i) * invs[((int) (MODULO % i))] % MODULO) % MODULO;
            }
            long[] facts = new long[n + 1];
            long[] invFacts = new long[n + 1];
            facts[0] = 1;
            invFacts[0] = 1;
            for (int i = 1; i < facts.length; ++i) {
                facts[i] = i * facts[i - 1] % MODULO;
                invFacts[i] = invs[i] * invFacts[i - 1] % MODULO;
            }

            FastFourierTransformModulo ffter = new FastFourierTransformModulo((int) MODULO);

            int[] p = new int[n + 1];
            for (TaskF.Vertex v : vs)
                if (v.subtreeSize < n) {
                    ++p[v.subtreeSize];
                    ++p[n - v.subtreeSize];
                }

            for (int i = 0; i <= n; ++i) {
                p[i] = (int) (p[i] * facts[i] % MODULO);
            }

            int[] q = new int[n + 1];
            for (int i = 0; i <= n; ++i) {
                q[n - i] = (int) invFacts[i];
            }

            int[] prod = ffter.mul(p, q);
            for (int k = 1; k <= n; ++k) {
                long got = invFacts[k] * prod[n + k] % MODULO;
                long total = n * facts[n] % MODULO * invFacts[k] % MODULO * invFacts[n - k] % MODULO;
                out.println((total - got + MODULO) % MODULO);
            }
        }

        static class Vertex {
            int subtreeSize = 0;
            TaskF.Vertex parent = null;
            List<TaskF.Vertex> adj = new ArrayList<>(1);

            public void initSizes() {
                subtreeSize = 1;
                for (TaskF.Vertex v : adj)
                    if (v.subtreeSize == 0) {
                        v.initSizes();
                        subtreeSize += v.subtreeSize;
                    } else {
                        parent = v;
                    }
            }

        }

    }

    static class MathUtils {
        public static int nextPowerOfTwo(int x) {
            if (x < 0 || x > (1 << 30)) throw new RuntimeException();
            if (x == 0) return 1;
            if ((x & (x - 1)) == 0) return x;
            return Integer.highestOneBit(x) << 1;
        }

        static int log2(int x) {
            if (x <= 0 || (x & (x - 1)) != 0) throw new RuntimeException();
            return Integer.numberOfTrailingZeros(x);
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }

    static class FastFourierTransformModulo {
        final int MODULO;
        final int[] roots;

        public FastFourierTransformModulo(int MODULO) {
            for (int i = 2; i * i <= MODULO; ++i) if (MODULO % i == 0) throw new RuntimeException();
            this.MODULO = MODULO;
            int t = MODULO - 1;
            int p2 = 0;
            while (t % 2 == 0) {
                t /= 2;
                ++p2;
            }
            if (p2 == 0) throw new RuntimeException();
            roots = new int[p2 + 1];
            int start;
            for (start = 2; ; ++start)
                if (pow(start, (MODULO - 1) / 2) != 1) break;
            int pw = MODULO - 1;
            for (int i = 0; i < p2; ++i) {
                roots[i] = pow(start, pw);
                pw /= 2;
            }
        }

        public int[] mul(int[] a, int[] b) {
            int len = MathUtils.nextPowerOfTwo(a.length + b.length - 1);
            a = Arrays.copyOf(a, len);
            b = Arrays.copyOf(b, len);
            fft(a, false);
            fft(b, false);
            int[] c = pointwiseMultiply(a, b);
            fft(c, true);
            {
                int mult = pow(c.length, MODULO - 2);
                for (int i = 0; i < c.length; ++i) {
                    c[i] = (int) (c[i] * (long) mult % MODULO);
                }
            }
            return c;
        }

        public int[] pointwiseMultiply(int[] a, int[] b) {
            if (a.length != b.length) throw new RuntimeException();
            int[] c = new int[a.length];
            for (int i = 0; i < a.length; ++i) {
                c[i] = (int) (a[i] * (long) b[i] % MODULO);

            }
            return c;
        }

        private int pow(int a, int k) {
            if (k == 0) return 1;
            if (k % 2 == 0)
                return pow((int) (a * (long) a % MODULO), k / 2);
            return (int) (a * (long) pow(a, k - 1) % MODULO);
        }

        public void fft(int[] arr, boolean inv) {
            if (MathUtils.nextPowerOfTwo(arr.length) != arr.length) throw new RuntimeException();
            int n = arr.length;
            int[] invbits = FastFourierTransformModulo.InvBitsCache.INSTANCE.getInvBits(n);
            for (int i = 0; i < n; ++i) {
                int j = invbits[i];
                if (j > i) {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
            for (int p2 = 1, pow2 = 1; p2 < n; p2 *= 2, pow2 += 1) {
                int w = roots[pow2];
                if (inv) w = pow(w, MODULO - 2);
                for (int big = 0; big < n; big += 2 * p2) {
                    int cur = 1;
                    for (int small = big; small < big + p2; ++small) {
                        int i = small;
                        int j = small + p2;
                        int u = arr[i];
                        int o = arr[j];
                        int v = (int) (o * (long) cur % MODULO);
                        arr[i] = u + v;
                        if (arr[i] >= MODULO) arr[i] -= MODULO;
                        arr[j] = u - v;
                        if (arr[j] < 0) arr[j] += MODULO;
                        cur = (int) (cur * (long) w % MODULO);
                    }
                }
            }
        }

        public static int calcInvBits(int at, int total) {
            int res = 0;
            int rev = total >> 1;
            for (int p2 = 1; p2 < total; p2 <<= 1, rev >>= 1)
                if ((at & p2) != 0)
                    res |= rev;
            return res;
        }

        static class InvBitsCache {
            int[][] cache = new int[0][];
            static FastFourierTransformModulo.InvBitsCache INSTANCE = new FastFourierTransformModulo.InvBitsCache();

            private InvBitsCache() {
            }

            synchronized int[] getInvBits(int size) {
                int logsize = MathUtils.log2(size);
                if (logsize >= cache.length) {
                    cache = Arrays.copyOf(cache, logsize + 1);
                }
                if (cache[logsize] == null) {
                    cache[logsize] = new int[size];
                    for (int i = 0; i < size; ++i) cache[logsize][i] = calcInvBits(i, size);
                }
                return cache[logsize];
            }

        }

    }
}