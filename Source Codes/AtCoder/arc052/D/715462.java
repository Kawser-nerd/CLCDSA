import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.stream.Stream;

/**
 * Created by hama_du on 5/2/16.
 */
public class Main {

    static final long THRESHOLD = 30000;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        long k = in.nextLong();
        long m = in.nextLong();
        if (k < THRESHOLD) {
            out.println(solveSmallK((int)k, m));
        } else {
            out.println(solveLargeK(k, m));
        }
        out.flush();
    }

    private static long solveLargeK(long k, long m) {
        long ret = 0;
        for (long mod = 0 ; mod <= 100 ; mod++) {
            long now = mod;
            while (now <= m) {
                long nn = now;
                long ds = 0;
                while (nn > 0) {
                    ds += nn % 10;
                    nn /= 10;
                }
                if (ds == mod) {
                    ret++;
                }
                now += k;
            }
        }
        return ret - 1;
    }

    private static long solveSmallK(int k, long m) {
        int[] digits = String.format("%d", m).chars().map(c -> c - '0').toArray();
        int[] ten = new int[digits.length];
        ten[ten.length-1] = 1 % k;
        for (int i = ten.length-2 ; i >= 0 ; i--) {
            ten[i] = (ten[i+1] * 10) % k;
        }

        long[][][][] dp = new long[2][2][101][k];
        dp[0][0][0][0] = 1;

        for (int i = 0; i < digits.length ; i++) {
            int upto = Math.min(100, i * 10);
            int fi = i % 2;
            int ti = 1 - fi;
            for (int s = 0; s <= 1; s++) {
                for (int d = 0; d <= upto; d++) {
                    Arrays.fill(dp[ti][s][d], 0);
                }
            }

            for (int s = 0; s <= 1; s++) {
                for (int d = 0; d <= upto; d++) {
                    for (int mod = 0; mod < k ; mod++) {
                        long base = dp[fi][s][d][mod];
                        if (base == 0) {
                            continue;
                        }
                        for (int ud = 0; ud <= (s == 0 ? digits[i] : 9) ; ud++) {
                            int ts = (s == 0 && ud == digits[i]) ? 0 : 1;
                            int td = (d + ud) % k;
                            int tmod = (mod + ten[i] * ud) % k;
                            dp[ti][ts][td][tmod] += base;
                        }
                    }
                }
            }
        }


        long ret = 0;
        for (int s = 0; s <= 1; s++) {
            for (int d = 0; d <= 100 && d < k ; d++) {
                ret += dp[digits.length % 2][s][d][d];
            }
        }
        return ret - 1;
   }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
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

        public char nextChar() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            if ('a' <= c && c <= 'z') {
                return (char) c;
            }
            if ('A' <= c && c <= 'Z') {
                return (char) c;
            }
            throw new InputMismatchException();
        }

        public String nextToken() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}