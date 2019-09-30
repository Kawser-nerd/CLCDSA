import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.io.Reader;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.stream.Stream;
import java.util.Optional;
import java.io.BufferedReader;
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
        TreeSet<Integer> use = new TreeSet<>();
        final long inf = Long.MAX_VALUE / 4;
        long[] memo = new long[51];

        public void solve(int testNumber, MyInput in, PrintWriter out) {

            int n = in.nextInt();
            int[] a = in.nextIntArray(n);
            int[] b = in.nextIntArray(n);

            for (int i = 0; i < n; i++) {
                int idx = -1;
                long cur = -1;
                for (int j = 0; j < n; j++) {
                    if (a[j] != b[j]) {
                        Arrays.fill(memo, -1L);
                        long c = rec(a[j], b[j]);
//                    dump(i, idx, cur, j, c);
                        if (c >= inf) {
                            out.println(-1);
                            return;
                        }
                        if (cur < c) {
                            cur = c;
                            idx = j;
                        }
                    }
                }
//            dump(i, idx, cur);
                if (idx < 0) break;
                Arrays.fill(memo, -1L);
                rec(a[idx], b[idx]);
                restore(a[idx], b[idx]);
                a[idx] = b[idx];
            }

//        dump(use);
            out.println(use.stream().map(x -> 1L << x).reduce((x, y) -> x + y).orElseGet(() -> 0L));
        }

        long rec(int a, int b) {
            if (a == b) return 0;
            if (memo[a] < 0) {
                memo[a] = inf;
                for (int i = 1; i <= a; i++) {
                    memo[a] = Math.min(memo[a], rec(a % i, b) + (use.contains(i) ? 0 : 1L << i));
                }
            }
            return memo[a];
        }

        long restore(int a, int b) {
            if (a == b) return 0;
            for (int i = 1; i <= a; i++) {
                if (memo[a] == rec(a % i, b) + (use.contains(i) ? 0 : 1L << i)) {
//                dump("restore", a, a % i, b);
                    restore(a % i, b);
                    use.add(i);
                }
            }
            return memo[a];
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

        static class EndOfFileRuntimeException extends RuntimeException {
        }

    }
}