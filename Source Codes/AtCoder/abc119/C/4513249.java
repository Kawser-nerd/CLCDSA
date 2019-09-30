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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        CSyntheticKadomatsu solver = new CSyntheticKadomatsu();
        solver.solve(1, in, out);
        out.close();
    }

    static class CSyntheticKadomatsu {
        static int co;
        static int A;
        static int B;
        static int C;

        public static void solve(int a, int b, int c, int index, int ar[], int f1, int f2, int f3) {
            if (index >= ar.length) {
                if (a == 0 || b == 0 || c == 0)
                    return;
                int cost = 0;
                cost += f1 * 10;
                cost += f2 * 10;
                cost += f3 * 10;
                cost += Math.abs(A - a) + Math.abs(B - b) + Math.abs(C - c);
                if (cost < co)
                    co = cost;
                return;
            }
            solve(a + ar[index], b, c, index + 1, ar, f1 + 1, f2, f3);
            solve(a, b + ar[index], c, index + 1, ar, f1, f2 + 1, f3);
            solve(a, b, c + ar[index], index + 1, ar, f1, f2, f3 + 1);
            solve(a, b, c, index + 1, ar, f1, f2, f3);
        }

        public void solve(int testNumber, InputReader sc, OutputWriter out) {
            int n = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            int ar[] = new int[n];
            for (int i = 0; i < n; i++)
                ar[i] = sc.nextInt();
            co = Integer.MAX_VALUE;
            A = a;
            B = b;
            C = c;
            solve(0, 0, 0, 0, ar, -1, -1, -1);
            out.println(co);
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

        public int nextInt() {
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

        public void println(int i) {
            writer.println(i);
        }

    }
}