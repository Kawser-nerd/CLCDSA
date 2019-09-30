import java.util.*;
import java.util.List;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class C {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("C.in"));
        PrintWriter out = new PrintWriter("C.out");

        int t = in.nextInt();
        in.nextLine();
        for (int tn = 0; tn < t; tn++) {
            out.println("Case #" + (tn + 1) + ": " + solve(in));
        }

        out.close();

    }

    private static String solve(Scanner in) {
        int n = in.nextInt();
        Point[] p = new Point[n];
        for (int i = 0; i < n; i++) {
            p[i] = new Point(in.nextInt(), in.nextInt());
        }
        Arrays.sort(p, new Comparator<Point>() {
            public int compare(Point a, Point b) {
                return b.x - a.x;
            }
        });

        Point[] l = new Point[32];
        boolean ok = true;
        for (Point point : p) {
            int y = point.y;
            for (int yy = y - 1; yy <= y + 1; yy++) {
                if (l[yy] != null) {
                    ok = false;
                    point.q.add(l[yy]);
                    l[yy].q.add(point);
                }
            }
            l[y] = point;
        }
        if (ok) return "1";

        ok = true;
        for (Point point : p) {
            if (point.c == 0 && !dfs(point, 1)) ok = false;
        }
        if (ok) return "2";

        pp = new int[n];
        for (int i = 0; i < n; i++) pp[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int k = 0;
                List<Point> q = new ArrayList<Point>();
                for (Point point : p[i].q) {
                    if (p[j].q.contains(point)) {
                        q.add(point);
                    }
                }
                boolean b = false;
                for (int ii = 0; ii < q.size(); ii++) {
                    for (int jj = 0; jj < ii; jj++) {
                        if (q.get(ii).q.contains(q.get(jj))) {
                            b = true;
                        }
                    }
                }
                if (b) {
                    union(i, j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (get(i) == get(j) && p[i].q.contains(p[j])) {
                    return "4";
                }
            }
        }

        return "3";
    }

    private static boolean dfs(Point point, int c) {
        if (point.c > 0) {
            return point.c == c;
        }
        point.c = c;
        for (Point p : point.q) {
            if (!dfs(p, 3 - c)) return false;
        }
        return true;
    }

    static Random random = new Random(323423);


    private static void union(int i, int j) {
        i = get(i);
        j = get(j);
        if (random.nextBoolean()) pp[i] = j;
        else pp[j] = i;
    }

    private static int get(int i) {
        if (pp[i] == i) return i;
        pp[i] = get(pp[i]);
        return pp[i];
    }

    static int[] pp;

    static class Point {
        int x;
        int y;
        Set<Point> q = new HashSet<Point>();
        public int c;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

}