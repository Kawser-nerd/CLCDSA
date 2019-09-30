import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Deque;
import java.util.ArrayDeque;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            final short h = (short) in.nextInt();
            final short w = (short) in.nextInt();

            char[][] g = new char[w][h];
            byte[][] d = new byte[w][h];
            short sx = 0, sy = 0, gx = 0, gy = 0;
            for (short y = 0; y < h; y++) {
                String s = in.next();
                for (short x = 0; x < w; x++) {
                    d[x][y] = Byte.MAX_VALUE;
                    char c = s.charAt(x);
                    g[x][y] = c;
                    if (c == 's') {
                        sx = x;
                        sy = y;
                        d[x][y] = 0;
                    } else if (c == 'g') {
                        gx = x;
                        gy = y;
                    }
                }
            }

            Deque<Short> xq = new ArrayDeque<>();
            Deque<Short> yq = new ArrayDeque<>();
            xq.add(sx);
            yq.add(sy);
            final short dx[] = {-1, 1, 0, 0};
            final short dy[] = {0, 0, -1, 1};
            while (xq.size() > 0) {
                short cx = xq.poll();
                short cy = yq.poll();
                byte cd = d[cx][cy];
                for (byte i = 0; i < 4; i++) {
                    short cdx = (short) (cx + dx[i]);
                    short cdy = (short) (cy + dy[i]);
                    boolean isIn = (cdx >= 0 && cdx < w) && (cdy >= 0 && cdy < h);
                    if (!isIn)
                        continue;
                    byte cdd = cd;
                    if (g[cdx][cdy] == '#')
                        cdd++;
                    if (cdd <= 2 && cdd < d[cdx][cdy]) {
                        xq.add(cdx);
                        yq.add(cdy);
                        d[cdx][cdy] = cdd;
                    }
                }
            }

            out.println(d[gx][gy] <= 2 ? "YES" : "NO");
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