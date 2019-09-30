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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            long mod = 1000000007;
            long n = in.nextLong();
            long k = in.nextLong();
            Combination c = new Combination(n + k, mod);
            out.println(c.ncr(n + k - 1, k));
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

    }

    static class Combination {
        private long n;
        private long mod;
        private long[] factorial;

        public Combination(long n, long mod) {
            this.n = n;
            this.mod = mod;
            setFactorial();
        }

        private void setFactorial() {
            factorial = new long[(int) n + 1];
            factorial[0] = 1;
            for (long i = 1; i <= n; i++)
                factorial[(int) i] = (factorial[(int) i - 1] * i) % mod;
        }

        private long modPow(long x, long n) {
            if (n == 0)
                return 1;
            if ((n & 1) == 0) {
                long d = modPow(x, (n >> 1));
                return (d * d) % mod;
            } else {
                long d = modPow(x, n - 1);
                return (x * d) % mod;
            }
        }

        public long ncr(long n, long r) {
            if (n < 0 || r < 0 || n < r)
                return 0;
            else if (n == 0 || n == r)
                return 1;
            long ans = factorial[(int) n];
            ans = ans * modPow(factorial[(int) r], mod - 2) % mod;
            ans = ans * modPow(factorial[(int) (n - r)], mod - 2) % mod;
            return ans;
        }

    }
}