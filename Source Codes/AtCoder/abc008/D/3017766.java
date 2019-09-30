import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Objects;
import java.util.Map;
import java.util.Scanner;
import java.util.HashMap;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        static int w;
        static int h;
        static int n;
        static int[] x;
        static int[] y;
        Map<D.Area, Integer> dp = new HashMap<>();

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            /* 1. INPUT */
            w = in.nextInt();
            h = in.nextInt();
            n = in.nextInt();
            x = new int[n];
            y = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
            }

            /* 2. CALC */
            out.println(dfs(new D.Area(0, 0, w + 1, h + 1)));
        }

        private int dfs(D.Area area) {
            // ?????????????????: dp????????
            if (dp.containsKey(area)) {
                return dp.get(area);
            }

            boolean containsMachine = false;
            int max = 0;

            // ?????????????????...????
            for (int i = 0; i < n; i++) {
                if (!area.contains(x[i], y[i])) {
                    continue;
                }
                containsMachine = true;
                int g = 0;
                if (0 < x[i]) {
                    if (0 < y[i]) {
                        g += dfs(new D.Area(area.x1, area.y1, x[i], y[i]));
                    }
                    if (y[i] < h) {
                        g += dfs(new D.Area(area.x1, y[i], x[i], area.y2));
                    }
                }
                if (x[i] < w) {
                    if (0 < y[i]) {
                        g += dfs(new D.Area(x[i], area.y1, area.x2, y[i]));
                    }
                    if (y[i] < h) {
                        g += dfs(new D.Area(x[i], y[i], area.x2, area.y2));
                    }
                }
                max = Math.max(max, g);
            }

            // ????????????????????????????
            if (containsMachine) {
                max += area.y2 - area.y1 + area.x2 - area.x1 - 3;
            }

            dp.put(area, max);
            return max;
        }

        static class Area {
            int x1;
            int y1;
            int x2;
            int y2;

            Area(int x1, int y1, int x2, int y2) {
                this.x1 = x1;
                this.y1 = y1;
                this.x2 = x2;
                this.y2 = y2;
            }

            boolean contains(int x, int y) {
                return x1 < x && x < x2 && y1 < y && y < y2;
            }

            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                D.Area area = (D.Area) o;
                return x1 == area.x1 && y1 == area.y1 && x2 == area.x2 && y2 == area.y2;
            }

            public int hashCode() {
                return Objects.hash(x1, y1, x2, y2);
            }

            public String toString() {
                return String.format("(%d,%d),(%d,%d)", x1, y1, x2, y2);
            }

        }

    }
}