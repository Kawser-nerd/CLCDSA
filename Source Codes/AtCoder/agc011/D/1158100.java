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
            try {
                int n = in.readInt();
                int k = in.readInt();
                char[] s = IOUtils.readCharArray(in, n);
                for (int i = 0; i < n; i++) {
                    if (k == 0) {
                        if (i % 2 == 0) {
                            out.print(new String(s, i, n - i));
                            char cur = 'B';
                            for (int j = 0; j < i; j++) {
                                out.print(cur);
                                cur = (char) ('A' + 'B' - cur);
                            }
                            out.printLine();
                            return;
                        } else {
                            for (int j = i; j < n; j++) {
                                out.print((char) ('A' + 'B' - s[j]));
                            }
                            char cur = 'A';
                            for (int j = 0; j < i; j++) {
                                out.print(cur);
                                cur = (char) ('A' + 'B' - cur);
                            }
                            out.printLine();
                            return;
                        }
                    }
                    if (i % 2 == 0 ^ s[i] == 'B') {
                        k--;
                        s[i] = (char) ('A' + 'B' - s[i]);
                        if (k == 0) {
                            if (i % 2 == 0) {
                                out.print(new String(s, i, n - i));
                                char cur = 'B';
                                for (int j = 0; j < i; j++) {
                                    out.print(cur);
                                    cur = (char) ('A' + 'B' - cur);
                                }
                                out.printLine();
                                return;
                            } else {
                                for (int j = i; j < n; j++) {
                                    out.print((char) ('A' + 'B' - s[j]));
                                }
                                char cur = 'A';
                                for (int j = 0; j < i; j++) {
                                    out.print(cur);
                                    cur = (char) ('A' + 'B' - cur);
                                }
                                out.printLine();
                                return;
                            }
                        }
                    }
                    k--;
                }
                if (n % 2 == 0) {
                    char cur = 'B';
                    for (int j = 0; j < n; j++) {
                        out.print(cur);
                        cur = (char) ('A' + 'B' - cur);
                    }
                    out.printLine();
                    return;
                }
                if (k % 2 == 0) {
                    char cur = 'A';
                    for (int j = 0; j < n; j++) {
                        out.print(cur);
                        cur = (char) ('A' + 'B' - cur);
                    }
                    out.printLine();
                    return;
                }
                out.print('B');
                char cur = 'B';
                for (int j = 1; j < n; j++) {
                    out.print(cur);
                    cur = (char) ('A' + 'B' - cur);
                }
                out.printLine();
            } catch (InputMismatchException e) {
                while (true) {
                    ;
                }
            } catch (IndexOutOfBoundsException e) {
            }
        }

    }

    static class IOUtils {
        public static char[] readCharArray(InputReader in, int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = in.readCharacter();
            }
            return array;
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

        public char readCharacter() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            return (char) c;
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

        public void print(char i) {
            writer.print(i);
        }

        public void close() {
            writer.close();
        }

    }
}