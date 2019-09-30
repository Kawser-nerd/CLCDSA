import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int n = in.nextInt();
            if (n == 3) {
                out.println("2 5 63");
                return;
            }
            int[] a = new int[n];
            int p = 0;
            long s = 0;
            for (int i = 1; p < n; ++i)
                if (i % 2 == 0 || i % 3 == 0) {
                    a[p++] = i;
                    s += i;
                }
            for (int elast = 0; ; ++elast) {
                for (int eprev = 0; eprev <= elast; ++eprev) {
                    int u = a[n - 2] + eprev;
                    int v = a[n - 1] + elast;
                    if (u % 2 == 0 || u % 3 == 0) {
                        if (v % 2 == 0 || v % 3 == 0) {
                            if ((s + eprev + elast) % 6 == 0) {
                                a[n - 2] = u;
                                a[n - 1] = v;
                                for (int x : a) out.print(x + " ");
                                out.println();
                                return;
                            }
                        }
                    }
                }
            }
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
}