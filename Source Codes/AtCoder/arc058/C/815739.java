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
 *
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        int mask;
        long[][] answer;
        int end;
        long[] ten;

        long solve(int n, int cm) {
            if (answer[n][cm] != -1) {
                return answer[n][cm];
            }
            if ((cm & mask) == mask) {
                return answer[n][cm] = ten[n];
            }
            if (n == 0) {
                return answer[n][cm] = 0;
            }
            answer[n][cm] = 0;
            for (int i = 1; i <= 10; i++) {
                answer[n][cm] += solve(n - 1, ((cm << i) + 1) & end);
            }
            return answer[n][cm] %= MiscUtils.MOD7;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int x = in.readInt();
            int y = in.readInt();
            int z = in.readInt();
            mask = 1 + (1 << z) + (1 << (z + y)) + (1 << (x + y + z));
            answer = new long[n + 1][1 << (x + y + z + 1)];
            end = (1 << (x + y + z + 1)) - 1;
            ArrayUtils.fill(answer, -1);
            ten = IntegerUtils.generatePowers(10, n + 1, MiscUtils.MOD7);
            out.printLine(solve(n, 1));
        }

    }

    static class ArrayUtils {
        public static void fill(long[][] array, long value) {
            for (long[] row : array) {
                Arrays.fill(row, value);
            }
        }

    }

    static class IntegerUtils {
        public static long[] generatePowers(long base, int count, long mod) {
            long[] result = new long[count];
            if (count != 0) {
                result[0] = 1 % mod;
            }
            for (int i = 1; i < count; i++) {
                result[i] = result[i - 1] * base % mod;
            }
            return result;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
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
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class MiscUtils {
        public static final int MOD7 = (int) (1e9 + 7);

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

        public void printLine(long i) {
            writer.println(i);
        }

    }
}