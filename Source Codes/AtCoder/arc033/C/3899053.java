import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.function.LongBinaryOperator;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            IntSegmentTree st = new IntSegmentTree(new long[200001], (x, y) -> x + y, 0);
            int q = in.ints();
            for (int i = 0; i < q; i++) {
                int t = in.ints(), x = in.ints();
                switch (t) {
                    case 1: {
                        st.update(x, 1);
                        break;
                    }
                    case 2: {
                        int min = 1, max = 200001;
                        while (max - min > 1) {
                            int mid = (min + max) / 2;
                            if (st.query(0, mid) < x) {
                                min = mid;
                            } else {
                                max = mid;
                            }
                        }
                        st.update(min, 0);
                        out.println(min);
                        break;
                    }
                }
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

    static class IntSegmentTree {
        private final int n;
        private final int m;
        private final long[] tree;
        private final LongBinaryOperator op;
        private final long zero;

        public IntSegmentTree(long[] array, LongBinaryOperator op, long zero) {
            this.n = array.length;
            int msb = BitMath.extractMsb(n);
            this.m = n == msb ? msb : (msb << 1);
            this.tree = new long[m * 2 - 1];
            this.op = op;
            this.zero = zero;
            Arrays.fill(tree, zero);
            System.arraycopy(array, 0, this.tree, m - 1, array.length);
            for (int i = m - 2; i >= 0; i--) {
                tree[i] = op.applyAsLong(tree[2 * i + 1], tree[2 * i + 2]);
            }
        }

        public void update(int i, long v) {
            i += m - 1;
            tree[i] = v;
            while (i > 0) {
                i = (i - 1) / 2;
                tree[i] = op.applyAsLong(tree[2 * i + 1], tree[2 * i + 2]);
            }
        }

        public long query(int l, int r) {
            long ans = zero;
            l += m - 1;
            r += m - 1;
            while (l < r) {
                if ((l & 1) == 0) {
                    ans = op.applyAsLong(ans, tree[l]);
                }
                if ((r & 1) == 0) {
                    ans = op.applyAsLong(ans, tree[r - 1]);
                }
                l = l / 2;
                r = (r - 1) / 2;
            }
            return ans;
        }

    }
}