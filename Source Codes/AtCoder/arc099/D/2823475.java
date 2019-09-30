import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.io.Reader;
import java.io.InputStreamReader;
import java.util.Map;
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
        long X;
        long invX0;

        public void solve(int testNumber, MyInput in, PrintWriter out) {
            int n = in.nextInt();
            char[] cs = in.nextChars();

            final int mod0 = (int) 1e9 + 7;
            final int mod1 = (int) 1e9 + 9;
            X = (int) 1e9 + 3;
            invX0 = powmod(X, mod0 - 2, mod0);
            long invX1 = powmod(X, mod1 - 2, mod1);
            final long[] pow0 = new long[2 * n + 1];
            final long[] pow1 = new long[2 * n + 1];
            pow0[0] = powmod(X, (mod0 - 2L) * n % (mod0 - 1), mod0);
            pow1[0] = powmod(X, (mod1 - 2L) * n % (mod1 - 1), mod1);
            for (int i = 1; i < pow0.length; i++) pow0[i] = pow0[i - 1] * X % mod0;
            for (int i = 1; i < pow1.length; i++) pow1[i] = pow1[i - 1] * X % mod1;

            long[] h0 = new long[n + 1];
            long[] h1 = new long[n + 1];
            int[] xs = new int[n + 1];
            xs[n] = n;
            for (int i = n - 1; i >= 0; i--) {
                xs[i] = xs[i + 1];
                h0[i] = h0[i + 1];
                h1[i] = h1[i + 1];
                if (cs[i] == '>') {
                    xs[i]++;
                }
                if (cs[i] == '<') {
                    xs[i]--;
                }
                if (cs[i] == '+') {
                    h0[i] = round(h0[i] + 1, mod0);
                }
                if (cs[i] == '-') {
                    h0[i] = round(h0[i] + mod0 - 1, mod0);
                }
                if (cs[i] == '>') {
                    h0[i] = round(h0[i] * X, mod0);
                }
                if (cs[i] == '<') {
                    h0[i] = round(h0[i] * invX0, mod0);
                }
                if (cs[i] == '+') {
                    h1[i] = round(h1[i] + 1, mod1);
                }
                if (cs[i] == '-') {
                    h1[i] = round(h1[i] + mod1 - 1, mod1);
                }
                if (cs[i] == '>') {
                    h1[i] = round(h1[i] * X, mod1);
                }
                if (cs[i] == '<') {
                    h1[i] = round(h1[i] * invX1, mod1);
                }
            }

            long ans = 0;
            Map<Long, Integer> mp = new HashMap<>();
            for (int i = n; i >= 0; i--) {
                long key01 = round((h0[i] - h0[0]) * pow0[n - (xs[i] - xs[n])], mod0);
                long key02 = round(h0[i] * pow0[xs[n] - xs[i] + n], mod0);
                long key11 = round((h1[i] - h1[0]) * pow1[n - (xs[i] - xs[n])], mod1);
                long key12 = round(h1[i] * pow1[xs[n] - xs[i] + n], mod1);
                long key1 = key01 << 32 | key11;
                long key2 = key02 << 32 | key12;
                ans += mp.getOrDefault(key1, 0);
                mp.put(key2, mp.getOrDefault(key2, 0) + 1);
            }

            out.println(ans);
        }

        long round(long x, int mod) {
            return (x % mod + mod) % mod;
        }

        static long powmod(long n, long r, int m) {
            long res = 1;
            for (; r != 0; r >>>= 1, n = n * n % m) {
                if ((r & 1) == 1) {
                    res = res * n;
                    if (res >= m) {
                        res %= m;
                    }
                }
            }
            return res;
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

        public char[] nextChars() {
            int len = 0;
            str[len++] = nextChar();
            len = reads(len, isSpace);
            return Arrays.copyOf(str, len);
        }

        static class EndOfFileRuntimeException extends RuntimeException {
        }

    }
}