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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            TaskB.BinaryImage ni = new TaskB.BinaryImage(n);
            TaskB.BinaryImage mi = new TaskB.BinaryImage(m);
            for (int i = 0; i < n; i++) {
                String s = in.next();
                for (int j = 0; j < n; j++)
                    ni.set(i, j, s.charAt(j) == '#');
            }
            for (int i = 0; i < m; i++) {
                String s = in.next();
                for (int j = 0; j < m; j++)
                    mi.set(i, j, s.charAt(j) == '#');
            }
            out.println(ni.contains(mi) ? "Yes" : "No");
        }

        private static class BinaryImage {
            int n;
            boolean[][] image;

            BinaryImage(int n) {
                this.n = n;
                image = new boolean[n][n];
            }

            public int getN() {
                return n;
            }

            boolean get(int x, int y) {
                return image[x][y];
            }

            void set(int x, int y, boolean b) {
                image[x][y] = b;
            }

            public boolean contains(TaskB.BinaryImage bi) {
                for (int x = 0; x < n - bi.getN() + 1; x++) {
                    for (int y = 0; y < n - bi.getN() + 1; y++) {
                        boolean matched = true;
                        for (int i = 0; i < bi.getN() && matched; i++)
                            for (int j = 0; j < bi.getN() && matched; j++)
                                matched = image[x + i][y + j] == bi.get(i, j);
                        if (matched)
                            return true;
                    }
                }
                return false;
            }

        }

    }

    static class FastScanner {
        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
            this.in = in;
        }

        private int readByte() {
            if (bufPointer >= bufLength) {
                if (bufLength == -1)
                    throw new InputMismatchException();

                bufPointer = 0;
                try {
                    bufLength = in.read(buffer);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (bufLength <= 0)
                    return -1;
            }
            return buffer[bufPointer++];
        }

        private static boolean isPrintableChar(int c) {
            return c >= 33 && c <= 126;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            StringBuilder sb = new StringBuilder();

            int b = readByte();
            while (!isPrintableChar(b))
                b = readByte();

            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }

            return sb.toString();
        }

        public long nextLong() {
            long n = 0;

            int b = readByte();
            while (isSpaceChar(b))
                b = readByte();

            boolean minus = (b == '-');
            if (minus)
                b = readByte();

            while (b >= '0' && b <= '9') {
                n *= 10;
                n += b - '0';
                b = readByte();
            }

            if (!isSpaceChar(b))
                throw new NumberFormatException();

            return minus ? -n : n;
        }

        public int nextInt() {
            long n = nextLong();

            if (n < Integer.MIN_VALUE || n > Integer.MAX_VALUE)
                throw new NumberFormatException();

            return (int) n;
        }

    }
}