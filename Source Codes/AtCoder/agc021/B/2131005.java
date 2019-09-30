import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            ConvexHull.Point[] points = new ConvexHull.Point[n];
            ConvexHull.Point[] points2 = new ConvexHull.Point[n];
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                points[i] = new ConvexHull.Point(x, y);
                points2[i] = new ConvexHull.Point(x, y);
            }

            ConvexHull.Point[] convex = ConvexHull.convexHull(points2);
            double[] ans = new double[n];
            double[] tmp = new double[convex.length];
            for (int i = 0; i < convex.length; i++) {
                ConvexHull.Point now = convex[i];
                ConvexHull.Point next = convex[(i + 1) % convex.length];

                double tx = next.x - now.x;
                double ty = next.y - now.y;

                double tmpx = Math.atan2(-ty, tx) / (2 * Math.PI);
                tmp[i] = tmpx;
            }

            for (int i = 0; i < convex.length; i++) {
                double ttt = tmp[i] - tmp[(i - 1 + convex.length) % convex.length];
                if (ttt < 0) ttt += 1;
                for (int j = 0; j < n; j++) {
                    if (convex[i].x == points[j].x && convex[i].y == points[j].y) {
                        ans[j] = ttt;
                        break;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                out.println(ans[i]);
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

    static class ConvexHull {
        public static ConvexHull.Point[] convexHull(ConvexHull.Point[] points) {
            Arrays.sort(points, (a, b) -> Integer.compare(a.x, b.x) != 0 ? Integer.compare(a.x, b.x) : Integer.compare(a.y, b.y));
            int n = points.length;
            ConvexHull.Point[] hull = new ConvexHull.Point[n + 1];
            int cnt = 0;
            for (int i = 0; i < 2 * n; i++) {
                int j = i < n ? i : 2 * n - 1 - i;
                while (cnt >= 2 && isNotRightTurn(hull[cnt - 2], hull[cnt - 1], points[j]))
                    --cnt;
                hull[cnt++] = points[j];
            }
            return Arrays.copyOf(hull, cnt - 1);
        }

        static boolean isNotRightTurn(ConvexHull.Point a, ConvexHull.Point b, ConvexHull.Point c) {
            long cross = (long) (a.x - b.x) * (c.y - b.y) - (long) (a.y - b.y) * (c.x - b.x);
            long dot = (long) (a.x - b.x) * (c.x - b.x) + (long) (a.y - b.y) * (c.y - b.y);
            return cross < 0 || cross == 0 && dot <= 0;
        }

        public static class Point {
            public final int x;
            public final int y;

            public Point(int x, int y) {
                this.x = x;
                this.y = y;
            }

        }

    }
}