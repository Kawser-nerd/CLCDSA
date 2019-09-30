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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int h = in.nextInt();
            int w = in.nextInt();
            TaskD.BinaryImage bi = new TaskD.BinaryImage(w, h);
            for (int y = 0; y < h; y++) {
                String s = in.next();
                for (int x = 0; x < w; x++) {
                    bi.setImage(x, y, s.charAt(x) == '#');
                }
            }
            TaskD.BinaryImage d = bi.dilation();
            if (!d.erotion().isSame(bi))
                out.println("impossible");
            else {
                out.println("possible");
                StringBuilder sb = new StringBuilder();
                for (int y = 0; y < h; y++) {
                    for (int x = 0; x < w; x++) {
                        sb.append(d.get(x, y) ? '#' : '.');
                    }
                    sb.append('\n');
                }
                out.print(sb);
            }

        }

        private static class BinaryImage {
            int w;
            int h;
            boolean[][] image;

            BinaryImage(int w, int h) {
                this.w = w;
                this.h = h;
                image = new boolean[w][h];
            }

            public void setImage(int x, int y, boolean b) {
                image[x][y] = b;
            }

            private TaskD.BinaryImage dilation() {
                TaskD.BinaryImage rbi = copy();
                for (int x = 0; x < w; x++) {
                    for (int y = 0; y < h; y++) {
                        if (!image[x][y]) {
                            for (int rx = Math.max(x - 1, 0); rx <= x + 1 && rx < w; rx++) {
                                for (int ry = Math.max(y - 1, 0); ry <= y + 1 && ry < h; ry++) {
                                    rbi.setImage(rx, ry, false);
                                }
                            }
                        }
                    }
                }
                return rbi;
            }

            private TaskD.BinaryImage erotion() {
                TaskD.BinaryImage rbi = copy();
                for (int x = 0; x < w; x++) {
                    for (int y = 0; y < h; y++) {
                        if (image[x][y]) {
                            for (int rx = Math.max(x - 1, 0); rx <= x + 1 && rx < w; rx++) {
                                for (int ry = Math.max(y - 1, 0); ry <= y + 1 && ry < h; ry++) {
                                    rbi.setImage(rx, ry, true);
                                }
                            }
                        }
                    }
                }
                return rbi;
            }

            private TaskD.BinaryImage copy() {
                TaskD.BinaryImage cbi = new TaskD.BinaryImage(w, h);
                for (int x = 0; x < w; x++)
                    for (int y = 0; y < h; y++)
                        cbi.setImage(x, y, image[x][y]);
                return cbi;
            }

            public boolean get(int x, int y) {
                return image[x][y];
            }

            public boolean isSame(TaskD.BinaryImage bi) {
                for (int x = 0; x < w; x++)
                    for (int y = 0; y < h; y++)
                        if (bi.get(x, y) != image[x][y])
                            return false;
                return true;
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