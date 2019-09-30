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
        DRotationSort solver = new DRotationSort();
        solver.solve(1, in, out);
        out.close();
    }

    static class DRotationSort {
        int n;
        long[][] answer;
        int[] p;
        long a;
        long b;
        int[][] qty;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.readInt();
            a = in.readInt();
            b = in.readInt();
            p = in.readIntArray(n);
            MiscUtils.decreaseByOne(p);
            answer = new long[n + 1][n + 1];
            ArrayUtils.fill(answer, -1);
            qty = new int[n + 1][n + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < n; j++) {
                    qty[i][j + 1] = qty[i][j];
                    if (p[j] < i) {
                        qty[i][j + 1]++;
                    }
                }
            }
            out.printLine(go(0, 0));
        }

        private long go(int x, int y) {
            if (x == n) {
                return 0;
            }
            if (answer[x][y] != -1) {
                return answer[x][y];
            }
            if (p[x] < y) {
                return answer[x][y] = go(x + 1, y);
            }
            return answer[x][y] =
                    Math.min(go(x + 1, y) + a, go(x + 1, Math.max(y, p[x])) + b * query(x + 1, n - 1, y, p[x] - 1));
        }

        private int query(int posFrom, int posTo, int valFrom, int valTo) {
            if (valTo < valFrom) {
                return 0;
            }
            return qty[valTo + 1][posTo + 1] - qty[valTo + 1][posFrom] - qty[valFrom][posTo + 1] +
                    qty[valFrom][posFrom];
        }

    }

    static class MiscUtils {
        public static void decreaseByOne(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
                }
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

    static class ArrayUtils {
        public static void fill(long[][] array, long value) {
            for (long[] row : array) {
                Arrays.fill(row, value);
            }
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

        public int[] readIntArray(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
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
}