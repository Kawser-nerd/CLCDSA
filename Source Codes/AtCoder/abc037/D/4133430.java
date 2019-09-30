import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Comparator;
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
            int mod = 1000000007;
            int h = in.nextInt();
            int w = in.nextInt();

            int[][] path = new int[h][w];
            Way[][] ways = new Way[h][w];
            PriorityQueue<Way> pq = new PriorityQueue<>(Comparator.comparing(Way::getA));

            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    path[y][x] = 1;
                    ways[y][x] = new Way(y, x, in.nextInt());
                    pq.add(ways[y][x]);
                }
            }

            while (pq.size() > 0) {
                Way cw = pq.poll();
                int x = cw.getX();
                int y = cw.getY();
                if (x > 0 && ways[y][x - 1].getA() < cw.getA())
                    path[y][x] = (path[y][x] + path[y][x - 1]) % mod;
                if (x < w - 1 && ways[y][x + 1].getA() < cw.getA())
                    path[y][x] = (path[y][x] + path[y][x + 1]) % mod;
                if (y > 0 && ways[y - 1][x].getA() < cw.getA())
                    path[y][x] = (path[y][x] + path[y - 1][x]) % mod;
                if (y < h - 1 && ways[y + 1][x].getA() < cw.getA())
                    path[y][x] = (path[y][x] + path[y + 1][x]) % mod;
            }

            long ans = 0;
            for (int[] pa : path)
                for (int p : pa)
                    ans = (ans + p) % mod;

            out.println(ans);
        }

        class Way {
            int x;
            int y;
            int a;

            Way(int y, int x, int a) {
                this.x = x;
                this.y = y;
                this.a = a;
            }

            public int getA() {
                return a;
            }

            public int getX() {
                return x;
            }

            public int getY() {
                return y;
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