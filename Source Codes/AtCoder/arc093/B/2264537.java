import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Pradyumn
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            Debug debug = new Debug(out);
            int a = in.nextInt();
            int b = in.nextInt();
            char[][] map = new char[100][100];
            for (int i = 0; i < 100; ++i) {
                for (int j = 0; j < 100; ++j) {
                    if (j < 50)
                        map[i][j] = '#';
                    else
                        map[i][j] = '.';
                }
            }

            for (int x = 0, rem = a - 1; rem > 0; x += 2) {
                for (int y = 0; y < 100 && rem > 0; --rem, y += 2) {
                    map[y][x] = '.';
                }
            }
            for (int x = 0, rem = b - 1; rem > 0; x += 2) {
                for (int y = 0; y < 100 && rem > 0; --rem, y += 2) {
                    map[y][99 - x] = '#';
                }
            }
            out.println(100 + " " + 100);
            for (char[] r : map) out.println(new String(r));
        }

    }

    static class FastReader {
        private InputStream stream;
        private byte[] buf = new byte[8192];
        private int curChar;
        private int pnumChars;

        public FastReader(InputStream stream) {
            this.stream = stream;
        }

        private int pread() {
            if (pnumChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= pnumChars) {
                curChar = 0;
                try {
                    pnumChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (pnumChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = pread();
            while (isSpaceChar(c))
                c = pread();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = pread();
            }
            int res = 0;
            do {
                if (c == ',') {
                    c = pread();
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = pread();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class Debug {
        PrintWriter out;
        boolean oj;
        boolean system;
        long timeBegin;
        Runtime runtime;

        public Debug(PrintWriter out) {
            oj = System.getProperty("ONLINE_JUDGE") != null;
            this.out = out;
            this.timeBegin = System.currentTimeMillis();
            this.runtime = Runtime.getRuntime();
        }

        public Debug() {
            system = true;
            oj = System.getProperty("ONLINE_JUDGE") != null;
            OutputStream outputStream = System.out;
            this.out = new PrintWriter(outputStream);
            this.timeBegin = System.currentTimeMillis();
            this.runtime = Runtime.getRuntime();
        }

    }
}