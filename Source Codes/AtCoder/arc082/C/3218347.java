import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    static long __startTime = System.currentTimeMillis();

    static final long MOD = 998244353;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long[][] xy = new long[n][2];
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < 2 ; j++) {
                xy[i][j] = in.nextInt();
            }
        }

        long[][] C = new long[300][300];
        for (int i = 0; i < C.length; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i ; j++) {
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
            }
        }


        long all = 1;
        for (int i = 0; i < n ; i++) {
            all *= 2;
            all %= MOD;
        }

        long one = n;
        long two = n * (n - 1) / 2;
        long three = 0;

        boolean[][] done = new boolean[n][n];
        for (int i = 0; i < n ; i++) {
            for (int j = i+1 ; j < n ; j++) {
                if (done[i][j]) {
                    continue;
                }
                int cnt = 0;
                List<Integer> on = new ArrayList<>();
                for (int k = 0; k < n ; k++) {
                    if (onLine(xy[i], xy[j], xy[k])) {
                        on.add(k);
                        cnt++;
                    }
                }

                for (int l = 3 ; l <= cnt ; l++) {
                    three += C[cnt][l];
                    three %= MOD;
                }

                for (int a : on) {
                    for (int b : on) {
                        done[a][b] = true;
                    }
                }
            }
        }

        debug(all, one, two, three);

        out.println((all - one - two - three - 1 + MOD * 4) % MOD);
        out.flush();
    }

    static boolean onLine(long[] a, long[] b, long[] c) {
        return cross(b[0]-a[0], b[1]-a[1], c[0]-a[0], c[1]-a[1]) == 0;
    }

    static long cross(long ax, long ay, long bx, long by) {
        return ax*by-ay*bx;
    }

    private static void printTime(String label) {
        debug(label, System.currentTimeMillis() - __startTime);
    }

    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
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

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}