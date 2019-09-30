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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, MyInput in, PrintWriter out) {
            final int mod = (int) 1e9 + 7;

            int n = in.nextInt();

            Combination comb = new Combination(n + 1, mod);

            long[] cnt = new long[n];
            for (int k = 0; k < cnt.length; k++) {
                // a + b = k - 1
                // a + 2*b = n - 2
                final int b = n - k - 1;
                final int a = k - 1 - b;
                if (a >= 0 && b >= 0) {
                    cnt[k] = comb.get(a + b, a) * comb.getFact(k) % mod * comb.getFact(n - 1 - k) % mod;
                }
            }
            long ans = 0;
            for (int k = 1; k < cnt.length; k++) {
                ans += (cnt[k] - cnt[k - 1]) * k % mod;
            }
            out.println((ans % mod + mod) % mod);
        }

        public class Combination {
            final int mod;
            final int MAX;
            final long[] fact;
            final long[] inv;
            final long[] invfact;

            public Combination(int n, int mod) {
                this.mod = mod;
                MAX = n + 1;
                fact = new long[MAX];
                invfact = new long[MAX];
                inv = new long[MAX];

                inv[1] = 1;
                for (int i = 2; i < inv.length; i++) {
                    inv[i] = inv[mod % i] * (mod - mod / i) % mod;
                }

                fact[0] = 1;
                invfact[0] = 1;
                for (int i = 1; i < inv.length; i++) {
                    fact[i] = i * fact[i - 1] % mod;
                    invfact[i] = inv[i] * invfact[i - 1] % mod;
                }
            }

            public long get(int n, int r) {
                return fact[n] * invfact[n - r] % mod * invfact[r] % mod;
            }

            public long getFact(int n) {
                return fact[n];
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