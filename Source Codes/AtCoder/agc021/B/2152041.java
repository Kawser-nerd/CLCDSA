// package agc.agc021;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);


        int n = in.nextInt();
        long[][] pt = new long[n][2];
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < 2 ; j++) {
                pt[i][j] = in.nextLong();
            }
        }
        double[] ret = solve(pt);
        for (double d : ret) {
            out.println(String.format("%.12f", d));
        }
        out.flush();
    }

    private static double[] solve(long[][] pt) {
        int n = pt.length;
        if (n == 2) {
            return new double[]{0.5, 0.5};
        }

        Point[] points = new Point[n];
        for (int i = 0; i < n ; i++) {
            points[i] = new Point(i, pt[i][0], pt[i][1]);
        }
        List<Point> hull = convexHull(points);

        double[] possibility = new double[n];
        int hn = hull.size();
        for (int i = 0; i < hn ; i++) {
            Point c = hull.get(i);
            Point a = hull.get((i-1+hn)%hn);
            Point b = hull.get((i+1)%hn);
            double ax = a.x - c.x;
            double ay = a.y - c.y;
            double bx = b.x - c.x;
            double by = b.y - c.y;
            double cross = ax * bx + ay * by;
            double norm = Math.hypot(ax, ay) * Math.hypot(bx, by);
            double cos = Math.max(-1, Math.min(1, cross / norm));

            double rad = Math.acos(cos);
            double rate = Math.PI - rad;
            possibility[c.id] = rate / (Math.PI * 2);
        }
        return possibility;
    }

    static class Point implements Comparable<Point> {
        int id;
        long x;
        long y;

        Point(int i, long _x, long _y) {
            id = i;
            x = _x;
            y = _y;
        }

        Point(Point a, Point b) {
            x = b.x - a.x;
            y = b.y - a.y;
        }

        public int compareTo(Point o) {
            if (x != o.x) {
                return Long.signum(x - o.x);
            }
            return Long.signum(y - o.y);
        }

        public long det(Point other) {
            return x * other.y - y * other.x;
        }

        public String toString() {
            return "(" + x + "," + y + ")";
        }
    }

    public static List<Point> convexHull(Point[] points) {
        int n = points.length;
        Arrays.sort(points);
        Point[] candidate = new Point[n * 2];
        int k = 0;

        // downer
        for (int i = 0; i < n; i++) {
            while (k > 1) {
                Point a = new Point(candidate[k - 2], candidate[k - 1]);
                Point b = new Point(candidate[k - 1], points[i]);
                if (a.det(b) <= 0) {
                    k--;
                } else {
                    break;
                }
            }
            candidate[k++] = points[i];
        }

        // upper
        int t = k;
        for (int i = n - 2; i >= 0; i--) {
            while (k > t) {
                Point a = new Point(candidate[k - 2], candidate[k - 1]);
                Point b = new Point(candidate[k - 1], points[i]);
                if (a.det(b) <= 0) {
                    k--;
                } else {
                    break;
                }
            }
            candidate[k++] = points[i];
        }
        List<Point> ret = new ArrayList<>();
        for (int i = 0; i < k - 1; i++) {
            ret.add(candidate[i]);
        }
        return ret;
    }

    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
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
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}