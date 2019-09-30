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
        FPermutationAndMinimum solver = new FPermutationAndMinimum();
        solver.solve(1, in, out);
        out.close();
    }

    static class FPermutationAndMinimum {
        boolean[] done;
        long[][][] ways;
        int remain;
        int slots;
        int doneSlots;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] a = in.readIntArray(2 * n);
            boolean[] remove = new boolean[2 * n];
            MiscUtils.decreaseByOne(a);
            remain = 2 * n;
            for (int i = 0; i < 2 * n; i += 2) {
                if (a[i] != -2 && a[i + 1] != -2) {
                    remove[a[i]] = true;
                    remove[a[i + 1]] = true;
                    remain -= 2;
                }
            }
            done = new boolean[remain];
            for (int i = 0; i < 2 * n; i += 2) {
                if ((a[i] != -2) ^ (a[i + 1] != -2)) {
                    int current = a[i] != -2 ? a[i] : a[i + 1];
                    for (int j = current - 1; j >= 0; j--) {
                        if (remove[j]) {
                            current--;
                        }
                    }
                    done[current] = true;
                    doneSlots++;
                }
            }
            slots = remain / 2;
            ways = new long[remain + 1][slots + 1][doneSlots + 1];
            ArrayUtils.fill(ways, -1);
            out.printLine(go(0, 0, 0) * IntegerUtils.factorial(slots - doneSlots, MiscUtils.MOD7) % MiscUtils.MOD7);
        }

        private long go(int current, int freeOpened, int doneOpened) {
            if (freeOpened > slots || doneOpened > doneSlots) {
                return 0;
            }
            if (ways[current][freeOpened][doneOpened] != -1) {
                return ways[current][freeOpened][doneOpened];
            }
            if (current == remain) {
                return ways[current][freeOpened][doneOpened] = (freeOpened == 0 && doneOpened == 0) ? 1 : 0;
            }
            if (done[current]) {
                ways[current][freeOpened][doneOpened] = go(current + 1, freeOpened + 1, doneOpened);
                if (doneOpened > 0) {
                    ways[current][freeOpened][doneOpened] += go(current + 1, freeOpened, doneOpened - 1) * doneOpened;
                }
            } else {
                ways[current][freeOpened][doneOpened] = go(current + 1, freeOpened + 1, doneOpened) + go(current + 1,
                        freeOpened, doneOpened + 1);
                if (freeOpened > 0) {
                    ways[current][freeOpened][doneOpened] += go(current + 1, freeOpened - 1, doneOpened);
                }
            }
            return ways[current][freeOpened][doneOpened] %= MiscUtils.MOD7;
        }

    }

    static class IntegerUtils {
        public static long factorial(int n, long mod) {
            long result = 1;
            for (int i = 2; i <= n; i++) {
                result = result * i % mod;
            }
            return result % mod;
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

    static class ArrayUtils {
        public static void fill(long[][] array, long value) {
            for (long[] row : array) {
                Arrays.fill(row, value);
            }
        }

        public static void fill(long[][][] array, long value) {
            for (long[][] row : array) {
                fill(row, value);
            }
        }

    }
}