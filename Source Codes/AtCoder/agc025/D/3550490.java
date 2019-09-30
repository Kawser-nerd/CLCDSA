import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.HashSet;
import java.util.Objects;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author prakharjain
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        agc025d solver = new agc025d();
        solver.solve(1, in, out);
        out.close();
    }

    static class agc025d {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();

            int d1 = in.nextInt();

            int d2 = in.nextInt();

            Set<point> points = new HashSet<>();

            for (int i = 0; i * i <= d1; i++) {
                int sq = i * i;

                int rem = d1 - sq;

                int root = in.squareRoot(rem);

                if (root * root == rem) {
                    points.add(new point(i, root));
                }
            }

            int[][] isp = new int[2 * n][2 * n];

            boolean[][] vis = new boolean[2 * n][2 * n];
            int[][] l = new int[2 * n][2 * n];

            for (int i = 0; i < 2 * n; i++) {
                for (int j = 0; j < 2 * n; j++) {
                    if (!vis[i][j]) {
                        bfs(isp, i, j, vis, points, 1, l, n);
                    }
                }
            }

            points = new HashSet<>();

            for (int i = 0; i * i <= d2; i++) {
                int sq = i * i;

                int rem = d2 - sq;

                int root = in.squareRoot(rem);

                if (root * root == rem) {
                    points.add(new point(i, root));
                }
            }

            vis = new boolean[2 * n][2 * n];
            l = new int[2 * n][2 * n];

            for (int i = 0; i < 2 * n; i++) {
                for (int j = 0; j < 2 * n; j++) {
                    if (!vis[i][j]) {
                        bfs(isp, i, j, vis, points, 2, l, n);
                    }
                }
            }

            int[] cnt = new int[4];
            for (int i = 0; i < 2 * n; i++) {
                for (int j = 0; j < 2 * n; j++) {
                    cnt[isp[i][j]]++;
                }
            }

            int di = -1;

            int n2 = n * n;

            for (int i = 0; i < 4; i++) {
                if (cnt[i] >= n2) {
                    di = i;
                    break;
                }
            }

            int cc = 0;
            for (int i = 0; i < 2 * n; i++) {
                for (int j = 0; j < 2 * n; j++) {
                    if (isp[i][j] == di) {
                        out.println(i + " " + j);
                        cc++;

                        if (cc == n2) {
                            return;
                        }
                    }
                }
            }
        }

        void bfs(int[][] isp, int sr, int sc, boolean[][] vis, Set<point> points, int add, int[][] l, int n) {
            vis[sr][sc] = true;

            ArrayDeque<point> q = new ArrayDeque<>();

            q.addLast(new point(sr, sc));

            while (!q.isEmpty()) {
                point p = q.removeFirst();

                int i = p.x;
                int j = p.y;

                for (point point : points) {
                    for (int a = -1; a <= 1; a += 2) {
                        for (int b = -1; b <= 1; b += 2) {
                            int x = i + a * point.x;
                            int y = j + b * point.y;

                            if (x >= 0 && x < 2 * n && y >= 0 && y < 2 * n) {
                                if (!vis[x][y]) {
                                    vis[x][y] = true;
                                    if (l[i][j] % 2 == 0) {
                                        isp[x][y] |= add;
                                    }

                                    l[x][y] = l[i][j] + 1;
                                    q.addLast(new point(x, y));
                                }
                            }
                        }
                    }
                }
            }
        }

        class point {
            int x;
            int y;

            public point(int x, int y) {
                this.x = x;
                this.y = y;
            }

            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                point point = (point) o;
                return x == point.x &&
                        y == point.y;
            }

            public int hashCode() {
                return Objects.hash(x, y);
            }

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

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
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

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
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

        public int squareRoot(int num) {
            int squareRoot = (int) Math.sqrt(num);

            while (squareRoot * squareRoot <= num) {
                squareRoot++;
            }

            return squareRoot - 1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}