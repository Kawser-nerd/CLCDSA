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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            int a = in.readInt();
            int b = in.readInt();
            if (2 * (a + b) > n * m) {
                out.printLine("NO");
                return;
            }
            char[][] answer = new char[n][m];
            ArrayUtils.fill(answer, '.');
            if (n % 2 != 0) {
                for (int i = 0; i + 1 < m; i += 2) {
                    if (a != 0) {
                        answer[n - 1][i] = '<';
                        answer[n - 1][i + 1] = '>';
                        a--;
                    }
                }
            }
            if (m % 2 != 0) {
                for (int i = n % 2; i < n; i += 2) {
                    if (b != 0) {
                        answer[i][m - 1] = '^';
                        answer[i + 1][m - 1] = 'v';
                        b--;
                    }
                }
            }
            for (int i = n - n % 2 - 2; i >= 0; i -= 2) {
                for (int j = 0; j + 1 < m; j += 2) {
                    if (a >= 2) {
                        answer[i][j] = '<';
                        answer[i][j + 1] = '>';
                        answer[i + 1][j] = '<';
                        answer[i + 1][j + 1] = '>';
                        a -= 2;
                    } else if (b >= 2) {
                        answer[i][j] = '^';
                        answer[i][j + 1] = '^';
                        answer[i + 1][j] = 'v';
                        answer[i + 1][j + 1] = 'v';
                        b -= 2;
                    } else if (a == 1 && b == 1 && i == 0 && j == m - 3 && n % 2 == 1) {
                        answer[i][j] = '^';
                        answer[i + 1][j] = 'v';
                        answer[i][j + 1] = '<';
                        answer[i][j + 2] = '>';
                        a--;
                        b--;
                    } else if (a == 1) {
                        answer[i][j] = '<';
                        answer[i][j + 1] = '>';
                        a--;
                    } else if (b == 1) {
                        answer[i][j] = '^';
                        answer[i + 1][j] = 'v';
                        b--;
                    }
                }
            }
            if (a != 0 || b != 0) {
                out.printLine("NO");
                return;
            }
            out.printLine("YES");
            for (char[] row : answer) {
                out.printLine(row);
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

        public void printLine(char[] array) {
            writer.println(array);
        }

        public void close() {
            writer.close();
        }

    }

    static class ArrayUtils {
        public static void fill(char[][] array, char value) {
            for (char[] row : array) {
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