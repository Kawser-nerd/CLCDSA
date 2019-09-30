import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.Reader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.function.Consumer;
import java.util.List;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyInput in = new MyInput(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static @SuppressWarnings("ALL")
    class TaskF {
        int X;
        int K;
        int Q;
        int[] r;
        int[][] qs;

        public void solve(int testNumber, MyInput in, PrintWriter out) {
            X = in.nextInt();
            K = in.nextInt();
            r = new int[K + 1];
            System.arraycopy(in.nextIntArray(K), 0, r, 0, K);
            r[K] = Integer.MAX_VALUE;
            Q = in.nextInt();
            qs = in.nextIntArray2DWithIndex(Q, 2);
            Arrays.sort(qs, Comparator.comparingInt(a -> a[1]));
            for (int i = 0; i < Q; i++) {
                qs[i][2] = i;
            }
            Content.X = X;
            Buckets buckets = new Buckets(Q, (l, r) -> {
                int[] v = new int[r - l];
                for (int i = l; i < r; i++) v[i - l] = qs[i][1];
                return new Content(v);
            });

            int[] ans = new int[Q];
            Arrays.sort(qs, Comparator.comparingInt(a -> a[0]));
            for (int i = 0, j = 0; i <= K && j < Q; i++) {
                final int sign = i % 2 == 0 ? -1 : 1;
                for (; j < Q && qs[j][0] < r[i]; j++) {
                    final int dt = qs[j][0] - (i == 0 ? 0 : r[i - 1]);
                    BucketAccessor<Content, Integer> f = (Bucket<Content> b, int offset) -> b.t.get(offset, sign * dt);
                    ans[j] = (int) buckets.<Integer>get(qs[j][2], f);
                }
                final int dt = r[i] - (i == 0 ? 0 : r[i - 1]);
                final int v = sign * dt;
                Consumer<Bucket<Content>> updater = b -> b.t.update(b.l, b.r, v);
                buckets.foreach(updater);
            }
            for (int a : ans) out.println(a);
        }

    }

    static class Bucket<T> {
        public final int l;
        public final int r;
        public final T t;

        public Bucket(int l, int r, T t) {
            this.l = l;
            this.r = r;
            this.t = t;
        }

    }

    static class MyInput {
        private final BufferedReader in;
        private static int pos;
        private static int readLen;
        private static final char[] buffer = new char[1024 * 8];
        private static char[] str = new char[500 * 8 * 2];
        private static boolean[] isDigit = new boolean[256];
        private static boolean[] isSpace = new boolean[256];
        private static boolean[] isLineSep = new boolean[256];

        static {
            for (int i = 0; i < 10; i++) {
                isDigit['0' + i] = true;
            }
            isDigit['-'] = true;
            isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
            isLineSep['\r'] = isLineSep['\n'] = true;
        }

        public MyInput(InputStream is) {
            in = new BufferedReader(new InputStreamReader(is));
        }

        public int read() {
            if (pos >= readLen) {
                pos = 0;
                try {
                    readLen = in.read(buffer);
                } catch (IOException e) {
                    throw new RuntimeException();
                }
                if (readLen <= 0) {
                    throw new MyInput.EndOfFileRuntimeException();
                }
            }
            return buffer[pos++];
        }

        public int nextInt() {
            int len = 0;
            str[len++] = nextChar();
            len = reads(len, isSpace);
            int i = 0;
            int ret = 0;
            if (str[0] == '-') {
                i = 1;
            }
            for (; i < len; i++) ret = ret * 10 + str[i] - '0';
            if (str[0] == '-') {
                ret = -ret;
            }
            return ret;
        }

        public char nextChar() {
            while (true) {
                final int c = read();
                if (!isSpace[c]) {
                    return (char) c;
                }
            }
        }

        int reads(int len, boolean[] accept) {
            try {
                while (true) {
                    final int c = read();
                    if (accept[c]) {
                        break;
                    }
                    if (str.length == len) {
                        char[] rep = new char[str.length * 3 / 2];
                        System.arraycopy(str, 0, rep, 0, str.length);
                        str = rep;
                    }
                    str[len++] = (char) c;
                }
            } catch (MyInput.EndOfFileRuntimeException e) {
            }
            return len;
        }

        public int[] nextIntArray(final int n) {
            final int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt();
            }
            return res;
        }

        public int[][] nextIntArray2DWithIndex(final int n, final int k) {
            final int[][] res = new int[n][k + 1];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < k; j++) {
                    res[i][j] = nextInt();
                }
                res[i][k] = i;
            }
            return res;
        }

        static class EndOfFileRuntimeException extends RuntimeException {
        }

    }

    static class Buckets<T> {
        List<Bucket<T>> buckets;
        int B;
        int S;
        int n;

        public Buckets(int n, BucketSupplier<T> supplier) {
            this.n = n;
            S = (int) Math.sqrt(n);
            B = (n + S - 1) / S;
            buckets = new ArrayList<>(B);
            for (int i = 0; i < B; i++) {
                int l = i * S;
                int r = Math.min((i + 1) * S, n);
                T val = supplier.supply(l, r);
                buckets.add(new Bucket<>(l, r, val));
            }
        }

        public <U> U get(int idx, BucketAccessor<T, U> f) {
            int b = idx / S, offset = idx % S;
            return f.access(buckets.get(b), offset);
        }

        public void foreach(Consumer<Bucket<T>> consumer) {
            buckets.forEach(consumer);
        }

    }

    static interface BucketAccessor<T, U> {
        U access(Bucket<T> bucket, int offset);

    }

    static interface BucketSupplier<T> {
        T supply(int l, int r);

    }

    static class Content {
        static int X;
        public int set;
        public int add;
        public int[] value;

        public Content(int[] v) {
            set = -1;
            value = v;
        }

        public void update(int l, int r, int d) {
            int lv = get(0, d);
            int rv = get(value.length - 1, d);
            if (rv <= 0) {
                set = 0;
                add = 0;
                return;
            }
            if (lv >= X) {
                set = X;
                add = 0;
                return;
            }
            if (lv > 0 && rv < X) {
                add += d;
                return;
            }
            for (int i = 0; i < value.length; i++) {
                value[i] = Math.max(0, Math.min(value[i] + add + d, X));
            }
            add = 0;
        }

        public int get(int i, int d) {
            int v = set == -1 ? value[i] : set;
            return Math.max(0, Math.min(v + add + d, X));
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.