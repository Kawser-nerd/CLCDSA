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
            int w = in.nextInt();
            int h = in.nextInt();
            TaskB.Rectangle r = new TaskB.Rectangle(w, h);
            int n = in.nextInt();
            for (int i = 0; i < n; i++)
                r.paint(in.nextInt(), in.nextInt(), in.nextInt());
            out.println(r.getWhiteSum());
        }

        private static class Rectangle {
            private int w;
            private int h;
            boolean[][] bw;

            Rectangle(int w, int h) {
                this.w = w;
                this.h = h;
                bw = new boolean[w][h];
            }

            void paint(int x, int y, int a) {
                switch (a) {
                    case 1:
                        for (int i = 0; i < x; i++)
                            for (int j = 0; j < h; j++)
                                bw[i][j] = true;
                        break;
                    case 2:
                        for (int i = x; i < w; i++)
                            for (int j = 0; j < h; j++)
                                bw[i][j] = true;
                        break;
                    case 3:
                        for (int i = 0; i < y; i++)
                            for (int j = 0; j < w; j++)
                                bw[j][i] = true;
                        break;
                    case 4:
                        for (int i = y; i < h; i++)
                            for (int j = 0; j < w; j++)
                                bw[j][i] = true;
                        break;
                }
            }

            int getWhiteSum() {
                int n = 0;
                for (boolean[] x : bw)
                    for (boolean isBlack : x)
                        if (!isBlack)
                            n++;
                return n;
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
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