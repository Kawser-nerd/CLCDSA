import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            LineGeometry.Point[] points = new LineGeometry.Point[n];
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                points[i] = new LineGeometry.Point(x, y);
            }

            Modulo modulo = new Modulo(998244353);
            long ans = modulo.pow(2, n);
            ans = modulo.sub(ans, n + 1);
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int count = 0;
                    for (int k = j + 1; k < n; k++) {
                        if (LineGeometry.orientation(points[i], points[j], points[k]) == 0) {
                            count++;
                        }
                    }

                    long tmp = modulo.pow(2, count);
                    ans = modulo.sub(ans, tmp);
                }
            }

            out.println(ans);
        }

    }

    static class Modulo {
        long m;

        public Modulo(long m) {
            this.m = m;
        }

        public long sub(long a, long b) {
            return (a - b + m) % m;
        }

        public long pow(long a, long x) {
            long ans = 1;
            while (x > 0) {
                if ((x & 1) != 0) {
                    ans = (ans * a) % m;
                }
                x >>= 1;
                a = (a * a) % m;
            }
            return ans;
        }

    }

    static class LineGeometry {
        static final double EPS = 1e-10;

        public static int sign(double a) {
            return a < -EPS ? -1 : a > EPS ? 1 : 0;
        }

        public static int orientation(LineGeometry.Point a, LineGeometry.Point b, LineGeometry.Point c) {
            LineGeometry.Point AB = b.minus(a);
            LineGeometry.Point AC = c.minus(a);
            return sign(AB.cross(AC));
        }

        public static class Point implements Comparable<LineGeometry.Point> {
            public double x;
            public double y;

            public Point(double x, double y) {
                this.x = x;
                this.y = y;
            }

            public LineGeometry.Point minus(LineGeometry.Point b) {
                return new LineGeometry.Point(x - b.x, y - b.y);
            }

            public double cross(LineGeometry.Point b) {
                return x * b.y - y * b.x;
            }


            public int compareTo(LineGeometry.Point o) {
                // return Double.compare(Math.atan2(y, x), Math.atan2(o.y, o.x));
                return Double.compare(x, o.x) != 0 ? Double.compare(x, o.x) : Double.compare(y, o.y);
            }

        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tok;

        public String nextString() {
            while (!tok.hasMoreTokens()) {
                try {
                    tok = new StringTokenizer(in.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return tok.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }
}