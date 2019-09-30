import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    final FastScanner in = new FastScanner(System.in);

    final long MOD = (long)((1e9) + 7);

    /* MOD_CALCULATION */
    long ADD(long a, long b) {
        return (a + b) % MOD;
    }

    long SUB(long a, long b) {
        return (a - b + MOD) % MOD;
    }

    long MULT(long a, long b) {
        return (a * b) % MOD;
    }

    long POW(long a, long x) {
        long res = 1;
        for ( ; x > 0; x >>= 1) {
            if (x % 2 == 1) res = MULT(res, a);
            a = MULT(a, a);
        }

        return res;
    }

    long DIV(long a, long b) {
        return MULT(a, POW(b, MOD - 2));
    }
    /* end */

    public void solve() {
        int N = in.nextInt();
        if (N == 2) {
            System.out.println(1);
            return;
        } else if (N == 3) {
            System.out.println(4);
            return;
        }

        long[] fact = new long[N+1];
        fact[0] = 1;
        for (int i = 0; i < N; i++) {
            fact[i+1] = MULT(fact[i], i + 1);
        }
        long[] inv = new long[N+1];
        inv[N] = DIV(1, fact[N]);
        for (int i = N - 1; i >= 0; i--) {
            inv[i] = MULT(inv[i+1], i + 1);
        }

        long res = 0;
        long[] cnt = new long[N];
        for (int K = 1; K <= N - 1; K++) {
            if (2 * K < N) {
                continue;
            }
            long comb = MULT(MULT(fact[K-1], inv[N-1-K]), inv[2*K-N]);
            cnt[K] = MULT(comb, MULT(fact[K], fact[N-1-K]));
            res = ADD(res, MULT(K, SUB(cnt[K], cnt[K-1])));
        }
        System.out.println(res);
    }

    public static void main(final String[] args) {
        new Main().solve();
    }

    class FastScanner {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public FastScanner(InputStream stream) {
            this.stream = stream;
            // stream = new FileInputStream(new File("dec.in"));

        }

        int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        boolean isEndline(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; i++)
                array[i] = nextInt();

            return array;
        }

        int[][] nextIntMap(int n, int m) {
            int[][] map = new int[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextIntArray(m);
            }
            return map;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        long[] nextLongArray(int n) {
            long[] array = new long[n];
            for (int i = 0; i < n; i++)
                array[i] = nextLong();

            return array;
        }

        long[][] nextLongMap(int n, int m) {
            long[][] map = new long[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextLongArray(m);
            }
            return map;
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        double[] nextDoubleArray(int n) {
            double[] array = new double[n];
            for (int i = 0; i < n; i++)
                array[i] = nextDouble();

            return array;
        }

        double[][] nextDoubleMap(int n, int m) {
            double[][] map = new double[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = in.nextDoubleArray(m);
            }
            return map;
        }

        String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        String[] nextStringArray(int n) {
            String[] array = new String[n];
            for (int i = 0; i < n; i++)
                array[i] = next();

            return array;
        }

        String nextLine() {
            int c = read();
            while (isEndline(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndline(c));
            return res.toString();
        }
    }
}