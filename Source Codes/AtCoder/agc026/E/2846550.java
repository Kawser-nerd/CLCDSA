import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        ESynchronizedSubsequence solver = new ESynchronizedSubsequence();
        solver.solve(1, in, out);
        out.close();
    }

    static class ESynchronizedSubsequence {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            String s = in.readString();
            int[] a = new int[n];
            int[] b = new int[n];
            int atA = 0;
            int atB = 0;
            for (int i = 0; i < 2 * n; i++) {
                if (s.charAt(i) == 'a') {
                    a[atA++] = i;
                } else {
                    b[atB++] = i;
                }
            }
            boolean canStartB = false;
            for (int i = 0; i < n; i++) {
                if (b[i] < a[i]) {
                    canStartB = true;
                }
            }
            if (!canStartB) {
                int times = 0;
                int at = -1;
                for (int i = 0; i < n; i++) {
                    if (a[i] > at) {
                        times++;
                        at = b[i];
                    }
                }
                StringBuilder answer = new StringBuilder();
                for (int i = 0; i < times; i++) {
                    answer.append("ab");
                }
                out.printLine(answer);
                return;
            }
            String[] best = new String[n + 1];
            best[n] = "";
            for (int i = n - 1; i >= 0; i--) {
                best[i] = best[i + 1];
                if (a[i] < b[i]) {
                    int j = n;
                    while (a[j - 1] > b[i]) {
                        j--;
                    }
                    best[i] = MiscUtils.max(best[i], "ab" + best[j]);
                    continue;
                }
                int include = 1;
                int lastA = a[i];
                for (int j = i + 1; j < n; j++) {
                    if (b[j] < lastA) {
                        include++;
                        lastA = a[j];
                    }
                }
                StringBuilder varBuilder = new StringBuilder(2 * include);
                int aa = i;
                int bb = i;
                for (int j = 0; j < 2 * include; j++) {
                    if (aa == i + include) {
                        varBuilder.append('b');
                        bb++;
                    } else if (bb == i + include) {
                        varBuilder.append('a');
                        aa++;
                    } else if (a[aa] < b[bb]) {
                        varBuilder.append('a');
                        aa++;
                    } else {
                        varBuilder.append('b');
                        bb++;
                    }
                }
                String variant = varBuilder.toString() + best[i + include];
                best[i] = MiscUtils.max(best[i], variant);
            }
            out.printLine(best[0]);
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

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class MiscUtils {
        public static <T extends Comparable<T>> T max(T first, T second) {
            if (first.compareTo(second) <= 0) {
                return second;
            }
            return first;
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

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}