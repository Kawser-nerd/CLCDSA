import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
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
 *
 * @author Скромная Няша Стесняша Блять; Зверь нахуй
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
                if (toRun == null || candidate.lastModified() > toRun.lastModified()) {
                    toRun = candidate;
                }
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
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }

    static class TaskB {
        Boolean[] used;

        boolean f(int v, boolean[][] mat) {
            if (used[v] != null) {
                return used[v];
            }

            if (v == mat.length - 1) {
                return true;
            }
            boolean can = false;
            for (int to = 0; to < mat.length; to++) {
                if (mat[v][to]) {
                    mat[v][to] &= f(to, mat);
                }
                can |= mat[v][to];
            }
            return used[v] = can;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {

            int n;
            long cntWay;
            boolean[][] mat;

            n = in.readInt();
            final long CNTWAY = cntWay = in.readLong();
            mat = new boolean[n][n];

            long[] val = new long[n - 1];
            Arrays.fill(val, 1);
            for (int i = 1; i < val.length; i++) {
                for (int j = i + 1; j < val.length; j++) {
                    val[j] += val[i];
                    mat[i][j] = true;
//                if (1e18 <= val[j])
//                    val[j] = 0;
                }
            }
            for (int to = 1; to < n - 1; to++) {
                mat[0][to] = true;
            }

            long totalWay = 0;
            for (int i = 0; i < val.length; i++) {
                totalWay += val[i];
//            out.printLine("totalWay: " + totalWay);
            }

//        out.printLine("::totalWay: " + totalWay);
            if (totalWay == cntWay) {
                for (int i = 0; i < n - 1; i++) {
                    mat[i][n - 1] = true;
                }
                cntWay = 0;
            } else {
                for (int i = 0; i < val.length; i++) {
                    if ((cntWay & val[i]) != 0) {
                        cntWay &= ~val[i];
                        mat[i][n - 1] = true;
                    }
                }
            }
            used = new Boolean[n];
            f(0, mat);

            if (cntWay == 0) {
                out.print("Case #" + testNumber + ": POSSIBLE");
                out.printLine();
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (mat[i][j]) {
                            out.print("1");
                        } else {
                            out.print("0");
                        }
                    }
                    out.printLine();
                }

                long[] cnt = new long[n];
                cnt[0] = 1;
                for (int v = 0; v < n; v++) {
                    for (int to = 0; to < n; to++) {
                        if (mat[v][to]) {
                            cnt[to] += cnt[v];
                        }
                    }
                }
                if (cnt[n - 1] != CNTWAY) {
                    throw new RuntimeException();
                }
            } else {
                out.print("Case #" + testNumber + ": IMPOSSIBLE");
                out.printLine();
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

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine() {
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}

