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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] a = in.readIntArray(n);
            int[] b = in.readIntArray(n);

            int ans = 0;
            for (int i = 0; i < 29; i++) {
                int[] copyB = Arrays.copyOf(b, b.length);
                for (int j = 0; j < n; j++) {
                    copyB[j] %= 1 << (i + 1);
                }
                Arrays.sort(copyB);

                long count = 0;
                for (int j = 0; j < n; j++) {
                    int t1 = ArrayUtils.lowerBound(copyB, (1 << i) - (a[j] % (1 << (i + 1))));
                    int t2 = ArrayUtils.lowerBound(copyB, 2 * (1 << i) - (a[j] % (1 << (i + 1))));
                    int t3 = ArrayUtils.lowerBound(copyB, 3 * (1 << i) - (a[j] % (1 << (i + 1))));
                    int t4 = ArrayUtils.lowerBound(copyB, 4 * (1 << i) - (a[j] % (1 << (i + 1))));

                    count += t4 - t3 + t2 - t1;
                }
                ans |= (count % 2) << i;
            }

            out.printLine(ans);
        }

    }

    static class ArrayUtils {
        public static int lowerBound(int[] a, int x) {
            int high = a.length;
            int low = -1;
            while (high - low > 1) {
                int mid = (high + low) / 2;
                if (a[mid] < x) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            return high;
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

        public void printLine(int i) {
            writer.println(i);
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