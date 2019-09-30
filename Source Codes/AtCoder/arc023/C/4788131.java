import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            long mod = 1_000_000_007;

            int n = in.nextInt();

            long ans = 1;

            long pa = 0;
            long len = 0;
            for (int i = 0; i < n; i++) {
                long ca = in.nextLong();
                if (ca == -1)
                    len++;
                else {
                    if (len > 0) {
                        long da = ca - pa + 1;
                        ans *= Numbers.nhr(da, len, mod);
                        ans %= mod;
                        len = 0;
                    }
                    pa = ca;
                }
            }

            out.println(ans);
        }

    }

    static class Numbers {
        public static long npr(long n, long r, long mod) {
            if (n < r) {
                return 0;
            }
            long ans = 1;
            for (long i = n; i > n - r; i--) {
                ans *= i;
                ans %= mod;
            }
            return ans;
        }

        public static long ncr(long n, long r, long mod) {
            r = Math.min(r, n - r);
            return npr(n, r, mod) * modInverse(npr(r, r, mod), mod) % mod;
        }

        public static long nhr(long n, long r, long mod) {
            return ncr(n + r - 1, r, mod);
        }

        public static long modInverse(long a, long mod) {
            long m = mod;
            long y = 0, x = 1;

            if (mod == 1)
                return 0;

            while (a > 1) {
                long q = a / m;

                long t = m;
                m = a % m;

                a = t;
                t = y;

                y = x - q * y;
                x = t;
            }

            return (x < 0) ? (x + mod) : x;
        }

    }

    static class FastScanner {
        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
            this.in = in;
            this.bufPointer = 0;
            this.bufLength = 0;
        }

        private int readByte() {
            if (bufPointer >= bufLength) {
                if (bufLength == -1)
                    throw new InputMismatchException();

                bufPointer = 0;
                try {
                    bufLength = in.read(buffer);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (bufLength <= 0)
                    return -1;
            }
            return buffer[bufPointer++];
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public long nextLong() {
            long n = 0;

            int b = readByte();
            while (isSpaceChar(b))
                b = readByte();

            boolean minus = (b == '-');
            if (minus)
                b = readByte();

            while (b >= '0' && b <= '9') {
                n *= 10;
                n += b - '0';
                b = readByte();
            }

            if (!isSpaceChar(b))
                throw new NumberFormatException();

            return minus ? -n : n;
        }

        public int nextInt() {
            int n = 0;

            int b = readByte();
            while (isSpaceChar(b))
                b = readByte();

            boolean minus = (b == '-');
            if (minus)
                b = readByte();

            while (b >= '0' && b <= '9') {
                n *= 10;
                n += b - '0';
                b = readByte();
            }

            if (!isSpaceChar(b))
                throw new NumberFormatException();

            return minus ? -n : n;
        }

    }
}