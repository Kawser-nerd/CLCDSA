import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Set;
import java.util.NavigableSet;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            double x1 = in.nextInt();
            double y1 = in.nextInt();
            double x2 = in.nextInt();
            double y2 = in.nextInt();

            double maxX = Math.max(x1, x2);
            double minX = Math.min(x1, x2);
            double maxY = Math.max(y1, y2);
            double minY = Math.min(y1, y2);

            int n = in.nextInt();
            if (x1 == x2) {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    int x = in.nextInt();
                    int y = in.nextInt();

                    if (x == x1 && minY < y && y < maxY) {
                        count++;
                    }
                }

                double ans = (maxY - minY) * 100 + (Math.PI * 10 - 20) * count;
                out.println(ans);
                return;
            }

            if (y1 == y2) {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    int x = in.nextInt();
                    int y = in.nextInt();

                    if (y == y1 && minX < x && x < maxX) {
                        count++;
                    }
                }

                double ans = (maxX - minX) * 100 + (Math.PI * 10 - 20) * count;
                out.println(ans);
                return;
            }

            boolean flg = (x2 - x1) * (y2 - y1) < 0;

            List<TaskC.Point> points = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                int y = in.nextInt();

                if (minX <= x && x <= maxX && minY <= y && y <= maxY) {
                    points.add(new TaskC.Point(x, y));
                }
            }
            points.sort(Comparator.comparingDouble(p -> p.x));

            int[] array = new int[points.size()];
            for (int i = 0; i < points.size(); i++) {
                array[i] = (flg ? -1 : 1) * points.get(i).y;
            }

            int len = Lis2.lisSize(array);
            double ans = 100 * (maxY - minY + maxX - minX) + len * (2 * Math.PI * 10 / 4 - 20);
            if (len == Math.min(maxX - minX, maxY - minY) + 1) ans += 2 * Math.PI * 10 / 4;

            out.printf("%.12f", ans);
        }

        static class Point {
            public int x;
            public int y;

            public Point(int x, int y) {
                this.x = x;
                this.y = y;
            }

        }

    }

    static class Lis2 {
        public static int lisSize(int[] a) {
            NavigableSet<Integer> s = new TreeSet<>();
            for (int v : a)
                if (s.add(v)) {
                    Integer higher = s.higher(v);
                    if (higher != null)
                        s.remove(higher);
                }
            return s.size();
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