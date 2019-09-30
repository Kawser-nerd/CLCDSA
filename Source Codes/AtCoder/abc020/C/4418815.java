import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Queue;
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
            int h = in.nextInt();
            int w = in.nextInt();
            long t = in.nextLong();

            TaskC.Field f = new TaskC.Field(h, w, t);
            for (int y = 0; y < h; y++) {
                String s = in.next();
                for (int x = 0; x < w; x++) {
                    f.setField(x, y, s.charAt(x));
                }
            }

            long min = 1;
            long max = t;
            while (min < max) {
                long mid = (min + max) / 2;
                if (max - min == 1)
                    mid++;
                f.setT(mid);
                f.setDist();
                if (f.getGoalDist() <= t)
                    min = mid;
                else
                    max = mid - 1;
            }
            out.println(min);
        }

        static class Field {
            private int h;
            private int w;
            private int sy;
            private int sx;
            private int gy;
            private int gx;
            private long t;
            private char[][] field;
            private long[][] dist;

            Field(int h, int w, long t) {
                this.h = h;
                this.w = w;
                this.t = t;

                field = new char[w][h];
                dist = new long[w][h];
            }

            void setField(int x, int y, char c) {
                field[x][y] = c;
                if (c == 'S') {
                    sx = x;
                    sy = y;
                } else if (c == 'G') {
                    gx = x;
                    gy = y;
                }
            }

            private void initDist() {
                for (int y = 0; y < h; y++)
                    for (int x = 0; x < w; x++)
                        dist[x][y] = Long.MAX_VALUE;
                dist[sx][sy] = 0;
            }

            void setDist() {
                initDist();
                Queue<Integer> xq = new ArrayDeque<>();
                Queue<Integer> yq = new ArrayDeque<>();
                xq.add(sx);
                yq.add(sy);
                while (xq.size() > 0) {
                    int cx = xq.poll();
                    int cy = yq.poll();
                    if (isShorter(cx - 1, cy, dist[cx][cy])) {
                        dist[cx - 1][cy] = dist[cx][cy] + getCost(cx - 1, cy);
                        xq.add(cx - 1);
                        yq.add(cy);
                    }
                    if (isShorter(cx + 1, cy, dist[cx][cy])) {
                        dist[cx + 1][cy] = dist[cx][cy] + getCost(cx + 1, cy);
                        xq.add(cx + 1);
                        yq.add(cy);
                    }
                    if (isShorter(cx, cy - 1, dist[cx][cy])) {
                        dist[cx][cy - 1] = dist[cx][cy] + getCost(cx, cy - 1);
                        xq.add(cx);
                        yq.add(cy - 1);
                    }
                    if (isShorter(cx, cy + 1, dist[cx][cy])) {
                        dist[cx][cy + 1] = dist[cx][cy] + getCost(cx, cy + 1);
                        xq.add(cx);
                        yq.add(cy + 1);
                    }
                }
            }

            private long getCost(int x, int y) {
                return field[x][y] == '#' ? t : 1;
            }

            void setT(long t) {
                this.t = t;
            }

            private boolean isShorter(int x, int y, long d) {
                if (x < 0 || x >= w || y < 0 || y >= h)
                    return false;
                return (d + getCost(x, y)) < dist[x][y];
            }

            long getGoalDist() {
                return dist[gx][gy];
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