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
        ESequenceGrowingHard solver = new ESequenceGrowingHard();
        solver.solve(1, in, out);
        out.close();
    }

    static class ESequenceGrowingHard {
        int m;
        long[][] ways;
        long[][] sums;
        long[][] c;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int k = in.readInt();
            m = in.readInt();
            ways = new long[k][n];
            ArrayUtils.fill(ways, -1);
            sums = new long[k][n];
            ArrayUtils.fill(sums, -1);
            c = IntegerUtils.generateBinomialCoefficients(n, m);
            long[] result = new long[n + 1];
            result[0] = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    result[i] += result[j] * goSums(k - 1, i - j - 1) % m * c[i - 1][j] % m;
                }
                result[i] %= m;
            }
            out.printLine(result[n]);
        }

        private long goSums(int value, int length) {
            if (sums[value][length] != -1) {
                return sums[value][length];
            }
            sums[value][length] = go(value, length);
            if (value != 0) {
                sums[value][length] += goSums(value - 1, length);
                if (sums[value][length] >= m) {
                    sums[value][length] -= m;
                }
            }
            return sums[value][length];
        }

        private long go(int value, int length) {
            if (ways[value][length] != -1) {
                return ways[value][length];
            }
            if (length == 0) {
                return ways[value][length] = 1;
            }
            if (value == 0) {
                return ways[value][length] = 0;
            }
            ways[value][length] = 0;
            for (int i = 0; i < length; i++) {
                ways[value][length] += go(value, length - i - 1) * goSums(value - 1, i) % m * c[length - 1][i] % m;
            }
            return ways[value][length] %= m;
        }

    }

    static class IntegerUtils {
        public static long[][] generateBinomialCoefficients(int n, long module) {
            long[][] result = new long[n + 1][n + 1];
            if (module == 1) {
                return result;
            }
            for (int i = 0; i <= n; i++) {
                result[i][0] = 1;
                for (int j = 1; j <= i; j++) {
                    result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
                    if (result[i][j] >= module) {
                        result[i][j] -= module;
                    }
                }
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

    static class ArrayUtils {
        public static void fill(long[][] array, long value) {
            for (long[] row : array) {
                Arrays.fill(row, value);
            }
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

        public void printLine(long i) {
            writer.println(i);
        }

    }
}