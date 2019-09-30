import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.Reader;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.TreeMap;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        TreeMap<Integer, Integer> mp = new TreeMap<>();

        public void solve(int testNumber, MyInput in, PrintWriter out) {
            if (false)
                for (int k = 30; k <= 30; k++) {
                    TreeSet<Integer> find = new TreeSet<>();
                    for (int i = 1; i <= 1000; i++) {
//                if (snim(i, k) == 1) {
//                if (find.add(snim(i, k))) {
                        dump(i, k, snim(i, k));
//                }
//                }
                    }
                }

            int g = 0;
            int n = in.nextInt();
            for (int i = 0; i < n; i++) {
                int a = in.nextInt();
                int k = in.nextInt();
                g ^= calc(a, k);
            }
            out.println(g == 0 ? "Aoki" : "Takahashi");
        }

        int calc(int x, int k) {
            while (x % k != 0) {
                if (x < k) return 0;
                long v = x / k + 1;
                long low = 1, high = 1000000000;
                while (high - low > 1) {
                    long mid = (low + high) / 2;
                    if ((x - v * mid) / k + 1 == v) {
                        low = mid;
                    } else {
                        high = mid;
                    }
                }
                x -= low * v;
            }
            return x / k;
        }

        int snim(int n, int k) {
            if (mp.containsKey(n)) return mp.get(n);
            TreeSet<Integer> set = new TreeSet<>();
            for (int i = 1; i <= n / k; i++) {
                set.add(snim(n - i, k));
            }
            for (int i = 0; ; i++) {
                if (!set.contains(i)) {
                    mp.put(n, i);
                    return i;
                }
            }
        }

        static void dump(Object... o) {
            System.err.println(Arrays.deepToString(o));
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