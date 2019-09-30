import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long x = in.nextInt();
            int k = in.nextInt();
            int[] r = in.readIntArray(k);
            int q = in.nextInt();
            long lo = 0, hi = x;
            int ridx = 0;
            long curtime = 0;
            long highvalue = x;
            long lowvalue = 0;
            int dir = -1;
            long delta = 0;
            while (q-- > 0) {
                int t = in.nextInt(), a = in.nextInt();
                while (ridx < k && r[ridx] <= t) {
                    long pass = r[ridx] - curtime;
                    if (dir > 0) {
                        highvalue = Math.min(x, highvalue + pass);
                        lowvalue = Math.min(x, lowvalue + pass);
                        lo = Math.min(x, lo + pass);
                        hi = Math.min(x, hi + pass);
                    } else {
                        highvalue = Math.max(0, highvalue - pass);
                        lowvalue = Math.max(0, lowvalue - pass);
                        lo = Math.max(0, lo - pass);
                        hi = Math.max(0, hi - pass);
                    }
                    delta += pass * dir;
                    curtime = r[ridx];
                    dir = -dir;
                    ridx++;
                }

                long pass = t - curtime;
                if (dir > 0) {
                    highvalue = Math.min(x, highvalue + pass);
                    lowvalue = Math.min(x, lowvalue + pass);
                    lo = Math.min(x, lo + pass);
                    hi = Math.min(x, hi + pass);
                } else {
                    highvalue = Math.max(0, highvalue - pass);
                    lowvalue = Math.max(0, lowvalue - pass);
                    lo = Math.max(0, lo - pass);
                    hi = Math.max(0, hi - pass);
                }

                delta += pass * dir;

                if (a + delta > hi) out.println(highvalue);
                else if (a + delta < lo) out.println(lowvalue);
                else out.println(a + delta);
                curtime = t;
            }
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
            }
            return ret;
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

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
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

        public void println(long i) {
            writer.println(i);
        }

    }
}