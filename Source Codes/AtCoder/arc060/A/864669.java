import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.Writer;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Niyaz Nigmatullin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        FastPrinter out = new FastPrinter(outputStream);
        Cards solver = new Cards();
        solver.solve(1, in, out);
        out.close();
    }

    static class Cards {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int x = in.nextInt();
            int sh = 50 * 50 + 1;
            long[] dp = new long[2 * sh];
            dp[sh] = 1;
            for (int i = 0; i < n; i++) {
                int y = in.nextInt() - x;
                long[] next = new long[2 * sh];
                if (y <= 0) {
                    for (int j = 0; j < 2 * sh; j++) {
                        next[j] += dp[j];
                        if (j - y < 2 * sh) {
                            next[j] += dp[j - y];
                        }
                    }
                } else {
                    for (int j = 2 * sh - 1; j >= 0; j--) {
                        next[j] += dp[j];
                        if (j - y >= 0) {
                            next[j] += dp[j - y];
                        }
                    }
                }
                dp = next;
            }
            out.println(dp[sh] - 1);
        }

    }

    static class FastScanner extends BufferedReader {
        public FastScanner(InputStream is) {
            super(new InputStreamReader(is));
        }


        public int read() {
            try {
                int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
                return ret;
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }

        static boolean isWhiteSpace(int c) {
            return c >= 0 && c <= 32;
        }

        public int nextInt() {
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int ret = 0;
            while (c >= 0 && !isWhiteSpace(c)) {
                if (c < '0' || c > '9') {
                    throw new NumberFormatException("digit expected " + (char) c
                            + " found");
                }
                ret = ret * 10 + c - '0';
                c = read();
            }
            return ret * sgn;
        }

        public String readLine() {
            try {
                return super.readLine();
            } catch (IOException e) {
                return null;
            }
        }

    }

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
        }

    }
}