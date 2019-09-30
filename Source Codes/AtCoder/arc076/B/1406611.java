import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.Collections;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Point[] points = new Point[n];
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                points[i] = new Point(x, y, i);
            }

            ArrayList<Street> streets = new ArrayList<>();

            Arrays.sort(points, new Comparator<Point>() {

                public int compare(Point o1, Point o2) {
                    return o1.x - o2.x;
                }
            });

            for (int i = 0; i < n - 1; i++) {
                streets.add(new Street(points[i].i, points[i + 1].i, points[i + 1].x - points[i].x));
            }

            Arrays.sort(points, new Comparator<Point>() {

                public int compare(Point o1, Point o2) {
                    return o1.y - o2.y;
                }
            });

            for (int i = 0; i < n - 1; i++) {
                streets.add(new Street(points[i].i, points[i + 1].i, points[i + 1].y - points[i].y));
            }

            Collections.sort(streets);

            long ans = 0;
            UnionFind unionFind = new UnionFind(n);
            for (int i = 0; i < streets.size(); i++) {
                if (!unionFind.isConnected(streets.get(i).s, streets.get(i).t)) {
                    ans += streets.get(i).d;
                    unionFind.union(streets.get(i).s, streets.get(i).t);
                }
            }

            out.println(ans);
        }

        class Street implements Comparable<Street> {
            int s;
            int t;
            int d;

            public Street(int s, int t, int d) {
                this.s = s;
                this.t = t;
                this.d = d;
            }


            public int compareTo(Street o) {
                return d - o.d;
            }

        }

        class Point {
            int x;
            int y;
            int i;

            public Point(int x, int y, int i) {
                this.x = x;
                this.y = y;
                this.i = i;
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

    static class UnionFind {
        int[] parent;

        public UnionFind(int size) {
            parent = new int[size];
            Arrays.fill(parent, -1);
        }

        public boolean union(int x, int y) {
            x = root(x);
            y = root(y);
            if (x != y) {
                if (parent[y] < parent[x]) {
                    int tmp = y;
                    y = x;
                    x = tmp;
                }
                parent[x] += parent[y];
                parent[y] = x;
                return true;
            }
            return false;
        }

        public boolean isConnected(int x, int y) {
            return root(x) == root(y);
        }

        public int root(int x) {
            return parent[x] < 0 ? x : (parent[x] = root(parent[x]));
        }

    }
}