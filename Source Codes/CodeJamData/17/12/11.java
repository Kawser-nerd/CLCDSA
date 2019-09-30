import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "B-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("b.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        private static final int MAX_CNT = 3 * 1000 * 1000;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            out.printFormat("Case #%d: ", testNumber);
            int n = in.readInt();
            int p = in.readInt();
            long[] req = IOUtils.readLongArray(in, n);
            long[][] a = IOUtils.readLongTable(in, n, p);
            for (long[] row : a) {
                Arrays.sort(row);
            }
            boolean[][] used = new boolean[n][p];
            long ans = 0;
            long[] low = new long[n];
            long[] high = new long[n];
            for (int cnt = 1; cnt <= MAX_CNT; cnt++) {
                for (int i = 0; i < n; i++) {
                    long x = req[i] * cnt;
                    low[i] = (long) (x * 0.9 - 5);
                    high[i] = (long) (x * 1.1 + 5);
                    if (low[i] < 1) {
                        low[i] = 1;
                    }
                    while (low[i] * 10 < x * 9 && low[i] < x) { // low[i] < x * 9 / 10
                        low[i]++;
                    }
                    while (high[i] * 10 > x * 11 && high[i] > x) { // high[i] > x * 11 / 10
                        high[i]--;
                    }
                    if (low[i] > high[i]) {
                        throw new AssertionError();
                    }
                }

                boolean someoneIsOutOfRange = false;
                for (int i = 0; i < n; i++) {
                    if (a[i][p - 1] < low[i]) {
                        someoneIsOutOfRange = true;
                    }
                }
                if (someoneIsOutOfRange) {
                    break;
                }

                int min = Integer.MAX_VALUE;
                for (int i = 0; i < n; i++) {
                    int valid = 0;
                    for (int j = 0; j < p; j++) {
                        if (!used[i][j] && low[i] <= a[i][j] && a[i][j] <= high[i]) {
                            valid++;
                        }
                    }
                    min = Math.min(min, valid);
                }
                if (min == 0) {
                    continue;
                }

                for (int i = 0; i < n; i++) {
                    int rem = min;
                    for (int j = 0; j < p; j++) {
                        if (!used[i][j] && low[i] <= a[i][j] && a[i][j] <= high[i]) {
                            used[i][j] = true;
                            rem--;
                            if (rem == 0) {
                                break;
                            }
                        }
                    }
                }

//            System.err.println("cnt = " + cnt);
//            System.err.println("req = " + Arrays.toString(req));
//            System.err.println("low = " + Arrays.toString(low));
//            System.err.println("high = " + Arrays.toString(high));

                ans += min;
            }
            System.err.println("Finished test case " + testNumber);
            System.err.flush();
            out.printLine(ans);
        }

    }

    static class IOUtils {
        public static long[] readLongArray(InputReader in, int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = in.readLong();
            }
            return array;
        }

        public static long[][] readLongTable(InputReader in, int rowCount, int columnCount) {
            long[][] table = new long[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = readLongArray(in, columnCount);
            }
            return table;
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

        public void printFormat(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

        public void printLine(long i) {
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

        public long readLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
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

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
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

        public String next() {
            return readString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}

