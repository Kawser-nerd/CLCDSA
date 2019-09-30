import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int k;
        char[] s;
        int[][][] dp;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            s = in.next().toCharArray();
            int n = s.length;
            k = in.nextInt();
            dp = new int[n][n][k + 1];
            AUtils.deepFill(dp, -1);
            out.println(solve(0, n - 1, k));
        }

        int solve(int front, int back, int rem) {
            if (front > back) return 0;
            if (front == back) return 1;
            if (dp[front][back][rem] != -1) return dp[front][back][rem];
            int ans = AUtils.max(
                    solve(front + 1, back, rem),
                    solve(front, back - 1, rem)
            );
            if (s[front] == s[back]) {
                ans = AUtils.max(ans, 2 + solve(front + 1, back - 1, rem));
            } else if (rem > 0) {
                ans = AUtils.max(ans, 2 + solve(front + 1, back - 1, rem - 1));
            }
            return dp[front][back][rem] = ans;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }

    static class AUtils {
        public static <E extends Comparable<E>> E max(E... arr) {
            E res = arr[0];
            for (E x : arr) if (x.compareTo(res) > 0) res = x;
            return res;
        }

        public static void deepFill(int[][][] x, int val) {
            for (int[][] y : x) deepFill(y, val);
        }

        public static void deepFill(int[][] x, int val) {
            for (int[] y : x) deepFill(y, val);
        }

        public static void deepFill(int[] x, int val) {
            Arrays.fill(x, val);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public String next() {
            int c;
            while (isSpaceChar(c = this.read())) {
                ;
            }

            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);

            while (!isSpaceChar(c = this.read())) {
                result.appendCodePoint(c);
            }

            return result.toString();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.