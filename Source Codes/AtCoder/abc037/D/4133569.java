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
        static final int mod = 1000000007;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int h = in.nextInt();
            int w = in.nextInt();

            Field f = new Field(h, w);
            int[][] a = new int[h][w];

            for (int y = 0; y < h; y++)
                for (int x = 0; x < w; x++)
                    a[y][x] = in.nextInt();
            f.setA(a);

            int sum = 0;
            for (int y = 0; y < h; y++)
                for (int x = 0; x < w; x++)
                    sum = (sum + f.getPath(x, y)) % mod;

            out.println(sum);
        }

        class Field {
            int h;
            int w;
            int[][] a;
            int[][] path;

            Field(int h, int w) {
                this.h = h;
                this.w = w;
                path = new int[h][w];
            }

            void setA(int[][] a) {
                this.a = a;
            }

            private void findPath(int x, int y) {
                path[y][x] = 1;
                if (x > 0 && a[y][x] < a[y][x - 1])
                    path[y][x] = (path[y][x] + getPath(x - 1, y)) % mod;
                if (x < w - 1 && a[y][x] < a[y][x + 1])
                    path[y][x] = (path[y][x] + getPath(x + 1, y)) % mod;
                if (y > 0 && a[y][x] < a[y - 1][x])
                    path[y][x] = (path[y][x] + getPath(x, y - 1)) % mod;
                if (y < h - 1 && a[y][x] < a[y + 1][x])
                    path[y][x] = (path[y][x] + getPath(x, y + 1)) % mod;
            }

            int getPath(int x, int y) {
                if (path[y][x] == 0)
                    findPath(x, y);
                return path[y][x];
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
            this.bufPointer = 0;
            this.bufLength = 0;
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

        public int nextInt() {
            int n = 0;

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

    }
}