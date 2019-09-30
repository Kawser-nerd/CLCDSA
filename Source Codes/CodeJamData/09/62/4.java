import java.util.*;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class B {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("B.in"));
        PrintWriter out = new PrintWriter("B.out");

        int t = in.nextInt();
        in.nextLine();
        for (int tn = 0; tn < t; tn++) {
            System.out.println("" + tn + " of " + t);
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
        int l = 1000000000;
        while (true) {
            Map<Point, List<Point>> m = new HashMap<Point, List<Point>>();
            boolean ok = true;
            outer:for (int i = 0; i < n; i++) {
                int xx = p[i].x / l;
                int yy = p[i].y / l;
                for (int dx = 0; dx < 2; dx ++) {
                    for (int dy = 0; dy < 2; dy++) {
                        Point w = new Point(xx + dx, yy + dy);
                        List<Point> q = m.get(w);
                        if (q == null) {
                            q = new ArrayList<Point>();
                            m.put(w, q);
                        }
                        q.add(p[i]);
                        if (q.size() > 100) {
                            ok = false;
                            break outer;
                        }
                    }
                }
            }
            if (ok) {
                double res = 1e100;
                for (Point point : m.keySet()) {
                    List<Point> q = m.get(point);
                    if (q.size() < 3) continue;
                    for (int i = 0; i < q.size(); i++) {
                        for (int j = i + 1; j < q.size(); j++) {
                            double len = q.get(i).distanceTo(q.get(j));
                            if (len > res) continue;
                            for (int k = j + 1; k < q.size(); k++) {
                                double len2 = len + q.get(i).distanceTo(q.get(k)) + q.get(j).distanceTo(q.get(k));
                                res = Math.min(res, len2);
                            }
                        }
                    }
                }
                return "" + res;
            } else {
                l /= 2;
            }
        }        
    }

    static class Point {
        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Point point = (Point) o;

            if (x != point.x) return false;
            if (y != point.y) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }

        public double distanceTo(Point point) {
            return Math.hypot(x - point.x, y - point.y);
        }
    }
}
