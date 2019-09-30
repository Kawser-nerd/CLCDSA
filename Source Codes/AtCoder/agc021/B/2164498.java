import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.stream.Stream;
import java.util.StringTokenizer;
import java.util.Optional;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.LinkedList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyScan in = new MyScan(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, MyScan in, PrintWriter out) {
            int n = in.nextInt();
            int[][] pp = new int[n][3];
            for (int s = 0; s < n; s++) {
                pp[s][0] = in.nextInt();
                pp[s][1] = in.nextInt();
                pp[s][2] = s;
            }
            ConvexHull convexHull = new ConvexHull();
            pp = convexHull.calculate(pp);
            double[] res = new double[n];
            for (int i = 0; i < pp.length; i++) {
                int li = (i - 1 + pp.length) % pp.length;
                int ri = (i + 1 + pp.length) % pp.length;

                int[] v11 = ConvexHull.v1(pp[i], pp[li]);
                int[] v12 = ConvexHull.v1(pp[i], pp[ri]);

                res[pp[i][2]] = (Math.PI - ConvexHull.angle(v11, v12)) / 2 / Math.PI;

            }


            for (int i = 0; i < n; i++) {
                out.println(res[i]);
            }
        }

    }

    static class ConvexHull {
        public int[][] calculate(int[][] points) {
            int n = points.length;
            int[] right = Arrays.stream(points).min(Comparator.<int[]>comparingInt(t -> -t[0]).thenComparing(t -> t[1])).get();
            long[] dist = new long[n];
            for (int i = 0; i < n; i++) {
                dist[i] = (long) (points[i][0] - right[0]) * (points[i][0] - right[0])
                        + (long) (points[i][1] - right[1]) * (points[i][1] - right[1]);
            }
            Arrays.sort(points, (s1, s2) -> {
                if (s1 == right) return -1;
                if (s2 == right) return 1;
                int ccw = ccw(s1, s2, right);
                if (ccw != 0) return ccw;
                return Long.compare(dist[s1[2]], dist[s2[2]]);
            });
            LinkedList<int[]> hull = new LinkedList<>();
            hull.add(points[0]);
            hull.add(points[1]);
            for (int s = 2; s < n; s++) {
                while (hull.size() > 1) {
                    int[] p2 = hull.pollLast();
                    int[] p1 = hull.getLast();
                    if (ccw(p2, points[s], p1) <= 0) {
                        hull.add(p2);
                        break;
                    }
                }
                hull.add(points[s]);
            }
            return hull.toArray(new int[0][]);
        }

        public static int[] v1(int[] i1, int[] i2) {
            return new int[]{i1[0] - i2[0], i1[1] - i2[1]};
        }

        private static int ccw(int[] s1, int[] s2, int[] right) {
            long xa = s1[0] - right[0];
            long xb = s1[1] - right[1];
            long ya = s2[0] - right[0];
            long yb = s2[1] - right[1];
            return Long.compare(xb * ya, xa * yb);
        }

        public static long dot(long[] v11, long[] v12) {
            return (long) v11[0] * v12[0] + (long) v11[1] * v12[1];
        }

        public static double f(long[] x) {
            return Math.sqrt(x[0] * x[0] + x[1] * x[1]);
        }

        public static double angle(int[] v1, int[] v2) {
            long[] v11 = new long[v1.length];
            long[] v12 = new long[v2.length];
            for (int s = 0; s < v1.length; s++) {
                v11[s] = v1[s];
            }
            for (int s = 0; s < v12.length; s++) {
                v12[s] = v2[s];
            }

            return Math.acos(dot(v11, v12) / f(v11) / f(v12));
        }

    }

    static class MyScan {
        BufferedReader br;
        StringTokenizer st;

        MyScan(BufferedReader br) {
            this.br = br;
        }

        public MyScan(InputStream in) {
            this(new BufferedReader(new InputStreamReader(in)));
        }

        public void findToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }

        public String next() {
            findToken();
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}