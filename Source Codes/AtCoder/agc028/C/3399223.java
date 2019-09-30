import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.stream.LongStream;
import java.util.PriorityQueue;
import java.util.Collection;
import java.util.Set;
import java.io.IOException;
import java.io.Reader;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, MyInput in, PrintWriter out) {
//        if (true) { test(); return; }

            int n = in.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
                b[i] = in.nextInt();
            }
            out.println(solve(n, a, b));
        }

        long solve(int n, int[] a, int[] b) {
            PriorityQueue<int[]> que = new PriorityQueue<>(Comparator.comparingInt(x -> x[0]));
            for (int i = 0; i < n; i++) {
                que.add(new int[]{a[i], i, 0});
                que.add(new int[]{b[i], i, 1});
            }
            List<Long> xs = new ArrayList<>();
            Set<Integer> use = new TreeSet<>();
            int[] cnt = new int[2];
            for (int i = 0; i < n; i++) {
                int[] p = que.poll();
                xs.add((long) p[0]);
                use.add(p[1]);
                cnt[p[2]]++;
            }
            if (use.size() == n && cnt[0] > 0 && cnt[1] > 0) {
                long sum = 0;
                Seg2 seg = new Seg2(n);
                for (int i = 0; i < n; i++) {
                    sum += Math.min(a[i], b[i]);
                    seg.update(i, Math.min(a[i], b[i]));
                }
                long ans = Math.min(IntStream.of(a).mapToLong(x -> x).sum(), IntStream.of(b).mapToLong(x -> x).sum());
                for (int i = 0; i < n; i++) {
                    ans = Math.min(ans, sum + Math.max(a[i], b[i]) - Math.max(seg.get(0, i), seg.get(i + 1, n)));
                }
                return ans;
            } else {
                return xs.stream().mapToLong(x -> x).sum();
            }
        }

        class Seg2 {
            final int n;
            final int[] seg;

            public Seg2(final int n) {
                this.n = Integer.highestOneBit(n) << 1;
                seg = new int[this.n << 1];
            }

            int get(int l, int r) {
                return get(l, r, 0, 0, n);
            }

            int get(int l, int r, int k, int curL, int curR) {
                if (curR <= l || curL >= r) return 0;
                if (l <= curL && curR <= r) {
                    return seg[k];
                }
                final int curM = (curL + curR) / 2;
                return Math.max(
                        get(l, r, 2 * k + 1, curL, curM),
                        get(l, r, 2 * k + 2, curM, curR));
            }

            void update(int i, int v) {
                i += n - 1;
                seg[i] = v;
                while (i != 0) {
                    i = (i - 1) / 2;
                    seg[i] = Math.max(seg[2 * i + 1], seg[2 * i + 2]);
                }
            }

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

        static class EndOfFileRuntimeException extends RuntimeException {
        }

    }
}