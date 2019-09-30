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
 *
 * @author Egor Kulikov (egor@egork.net)
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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int k = in.readInt();
            int[] a = new int[k];
            int[] b = new int[k];
            in.readIntArrays(a, b);
            MiscUtils.decreaseByOne(a, b);
            long[] add = new long[n - k + 1];
            add[0] = 1;
            for (int i = 1; i <= n - k; i++) {
                add[i] = add[i - 1] * (2 * i - 1) % MiscUtils.MOD7;
            }
            long[][] ways = new long[2 * n][2 * n];
            boolean[][] valid = new boolean[2 * n][2 * n];
            long answer = 0;
            for (int i = 0; i < 2 * n; i++) {
                for (int j = i + 2; j < 2 * n; j += 2) {
                    boolean good = true;
                    int inside = (j - i) >> 1;
                    for (int l = 0; l < k; l++) {
                        if (a[l] >= i && a[l] < j || a[l] + 2 * n < j) {
                            if (b[l] >= i && b[l] < j || b[l] + 2 * n < j) {
                                inside--;
                            } else {
                                good = false;
                                break;
                            }
                        } else {
                            if (b[l] >= i && b[l] < j || b[l] + 2 * n < j) {
                                good = false;
                                break;
                            }
                        }
                    }
                    if (!good) {
                        continue;
                    }
                    valid[i][j] = true;
                    ways[i][j] = add[inside];
                    answer += ways[i][j] * add[n - k - inside] % MiscUtils.MOD7;
                }
            }
            answer += add[n - k];
            long[][] curCycles = new long[2 * n][2 * n];
            for (int i = 0; i < 2 * n; i++) {
                System.arraycopy(ways[i], 0, curCycles[i], 0, 2 * n);
            }
            long[][] nextCycles = new long[2 * n][2 * n];
            long[] mult = new long[n + 1];
            long[][] c = IntegerUtils.generateBinomialCoefficients(n + 1, MiscUtils.MOD7);
            for (int i = 2; i <= n; i++) {
                mult[i] = i - 1;
                for (int j = 2; j < i; j++) {
                    mult[i] -= mult[j] * c[i][j] % MiscUtils.MOD7;
                }
                mult[i] %= MiscUtils.MOD7;
            }
            int[][] extra = new int[2 * n][2 * n];
            for (int i = 0; i < 2 * n; i++) {
                for (int j = i + 2; j < 2 * n; j += 2) {
                    extra[i][j] = n - ((j - i) >> 1);
                    for (int l = 0; l < k; l++) {
                        if ((a[l] < i || a[l] >= j) && (b[l] < i || b[l] >= j)) {
                            extra[i][j]--;
                        }
                    }
                }
            }
            for (int i = 0; i < 2 * n; i++) {
                for (int j = i + 2; j < 2 * n; j += 2) {
                    if (!valid[i][j]) {
                        continue;
                    }
                    for (int l = i + 2; l < j; l += 2) {
                        nextCycles[i][j] -= (nextCycles[i][l] + ways[i][l]) * ways[l][j] % MiscUtils.MOD7;
                    }
                    nextCycles[i][j] %= MiscUtils.MOD7;
                    answer += nextCycles[i][j] * add[extra[i][j]] % MiscUtils.MOD7;
                }
            }
/*        for (int x = 3; x <= n; x++) {
            for (int i = 0; i < 2 * n; i++) {
                for (int j = i + 2 * (x - 1); j < 2 * n; j += 2) {
                    nextCycles[i][j] = 0;
                    if (!valid[i][j]) {
                        continue;
                    }
                    for (int l = i + 2 * (x - 2); l < j; l += 2) {
                        nextCycles[i][j] += curCycles[i][l] * ways[l][j] % MOD7;
                    }
                    nextCycles[i][j] %= MOD7;
                    if (nextCycles[i][j] == 0) {
                        continue;
                    }
                    answer += nextCycles[i][j] * add[extra[i][j]] % MOD7 * mult[x] % MOD7;
                }
            }
            long[][] temp = curCycles;
            curCycles = nextCycles;
            nextCycles = temp;
        }*/
            answer %= MiscUtils.MOD7;
            answer += MiscUtils.MOD7;
            answer %= MiscUtils.MOD7;
            out.printLine(answer);
        }

    }

    static class MiscUtils {
        public static final int MOD7 = (int) (1e9 + 7);

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

        public void readIntArrays(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
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