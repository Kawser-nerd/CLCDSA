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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int from = in.readInt();
            int to = in.readInt();

            if (Integer.bitCount(from ^ to) % 2 == 0) {
                out.printLine("NO");
                return;
            }

            out.printLine("YES");
            int[] change = new int[1 << n];
            int[] a = new int[n];
            int idx = 0;
            int xor = from ^ to;
            boolean[] swap = new boolean[n];
            for (int i = 0; i < n; i++) {
                if ((xor >> i & 1) == 1) {
                    a[idx] = i;
                    if (idx > 0) swap[idx] = true;
                    idx++;
                }
            }
            for (int i = 0; i < n; i++) {
                if ((xor >> i & 1) == 0) {
                    a[idx] = i;
                    idx++;
                }
            }

            for (int i = 1; i < 1 << n; i++) {
                int x = n - 1 - (("" + Integer.toBinaryString(Integer.lowestOneBit(i))).length() - 1);
                int tmp = x;
                if (tmp % 2 == 0) tmp--;
                if (swap[x] && i < (1 << (n - tmp))) {
                    change[i] = a[x % 2 == 0 ? x - 1 : x + 1];
                } else {
                    change[i] = a[x];
                }
            }

            out.print(from);
            for (int i = 1; i < 1 << n; i++) {
                from ^= 1 << change[i];
                out.print(" " + from);
            }
            out.printLine();
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

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
        }

    }
}