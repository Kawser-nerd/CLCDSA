import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;

public class Main {
    final FastScanner in = new FastScanner(System.in);

    final long MOD = (long)((1e9) + 9);

    public void solve() {
        int N = in.nextInt();
        String[] s = in.nextStringArray(N);

        long[][] colHash = new long[2*N][2*N+1];
        long[][] rowHash = new long[2*N+1][2*N];
        long[] pow = new long[2*N+1];
        pow[0] = 1;
        for (int i = 0; i < 2 * N; i++) {
            pow[i+1] = (pow[i] * 31) % MOD;
            for (int j = 0; j < 2 * N; j++) {
                colHash[i][j+1] = (colHash[i][j] * 31 + (s[i%N].charAt(j%N) - 'a' + 1)) % MOD;
                rowHash[i+1][j] = (rowHash[i][j] * 31 + (s[i%N].charAt(j%N) - 'a' + 1)) % MOD;
            }
        }

        int res = 0;
        for (int a = 0; a < N; a++) {
            for (int b = 0; b < N; b++) {
                long hash1 = 0, hash2 = 0;
                for (int i = 0; i < N; i++) {
                    hash1 = (hash1 + (colHash[i+a][b+N] - (colHash[i+a][b] * pow[N]) % MOD + MOD) % MOD) % MOD;
                }
                for (int j = 0; j < N; j++) {
                    hash2 = (hash2 + (rowHash[a+N][j+b] - (rowHash[a][j+b] * pow[N]) % MOD + MOD) % MOD) % MOD;
                }
                if (hash1 == hash2) res++;
            }
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