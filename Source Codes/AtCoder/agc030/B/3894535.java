import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.Reader;
import java.io.InputStreamReader;
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
        BTreeBurning solver = new BTreeBurning();
        solver.solve(1, in, out);
        out.close();
    }

    static class BTreeBurning {
        public void solve(int testNumber, MyInput in, PrintWriter out) {
            int l = in.nextInt();
            int n = in.nextInt();
            int[] x = new int[2 * n + 1];
            for (int i = 0; i < n; i++) {
                int v = in.nextInt();
                x[i] = -(l - v);
                x[i + n + 1] = v;
            }

            long ans = 0;
            for (int t = 0; t < 2; t++) {
//            dump(x);
                long[] sum = new long[x.length + 1];
                for (int i = 0; i < x.length; i++) {
                    sum[i + 1] = sum[i] + x[i];
                }

                for (int i = 0; i <= n; i++) {
                    int left = n - i, right = i;
                    if (left >= right) {
                        long cur = x[n] - x[n - (left - right)];
                        cur += 2 * (sum[n + right + 1] - sum[n + 1]);
                        cur -= 2 * (sum[n - (left - right) + 1] - sum[n - left]);
                        cur += x[n - left] + x[n - (left - right)];
                        ans = Math.max(ans, cur);

//                    dump(i, left, right, cur,
//                            x[n] - x[n - (left - right)],
//                            2 * (sum[n + right + 1] - sum[n + 1]),
//                            2 * (sum[n - (left - right) + 1] - sum[n - left]),
//                            x[n - left] + x[n - (left - right)]);

                        if (n - (left - right) - 1 >= 0) {
                            cur = x[n] - x[n - (left - right) - 1];
                            cur += 2 * (sum[n + right + 1] - sum[n + 1]);
                            cur -= 2 * (sum[n - (left - right)] - sum[n - left]);
                            cur += -x[n + right] + x[n - (left - right) - 1];
                            ans = Math.max(ans, cur);
                        }
                    }
                }

                for (int i = 0; i < x.length / 2; i++) {
                    swap(x, i, x.length - 1 - i);
                }
                for (int i = 0; i < x.length; i++) {
                    x[i] = -x[i];
                }
            }
            out.println(ans);
        }

        static void swap(int[] xs, int i, int j) {
            int t = xs[i];
            xs[i] = xs[j];
            xs[j] = t;
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