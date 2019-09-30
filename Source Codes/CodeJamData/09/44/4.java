import java.util.*;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class D {
    private static final double EPS = 1e-9;
    private static final int TT = 100;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("D.in"));
        PrintWriter out = new PrintWriter("D.out");

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
            p[i] = new Point(in.nextInt(), in.nextInt(), in.nextInt());
        }

        List<Double> angles = new ArrayList<Double>();

        angles.add(0.0);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!p[i].equals(p[j])) {
                    angles.add(Math.atan2(p[j].y - p[i].y, p[j].x - p[i].x));
                    angles.add(Math.atan2(p[j].y - p[i].y, p[j].x - p[i].x) + Math.PI / 2);
                }
            }
        }

        Collections.sort(angles);
        List<Double> t = angles;
        angles = new ArrayList<Double>();
        for (int i = 0; i < t.size(); i++) {
            if (i == 0 || t.get(i) > t.get(i - 1) + 1e-9) {
                angles.add(t.get(i));
            }
        }

        double lo = 0;
        for (int i = 0; i < n; i++) {
            lo = Math.max(lo, p[i].r);
        }
        double hi = 10000;
        while (hi > lo + 1e-9) {
            double rr = (hi + lo) / 2;
            boolean ok = false;
            for (final Double angle : angles) {
                Arrays.sort(p, new Comparator<Point>() {
                    public int compare(Point a, Point b) {
                        double da = a.x * Math.cos(angle) + a.y * Math.sin(angle);
                        double db = b.x * Math.cos(angle) + b.y * Math.sin(angle);
                        return Double.compare(da, db);
                    }
                });

                for (int i = 0; i < n; i++) {
                    if (covers(p, 0, i, rr) && covers(p, i + 1, n - 1, rr)) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
            if (ok) hi = rr;
            else lo = rr;
        }

        return "" + hi;
    }

    private static boolean covers(Point[] p, int l, int r, double rr) {
        if (l >= r) return true;
        if (r > l + 1) return false;
        return p[l].distanceTo(p[r]) + p[l].r + p[r].r <= 2 * rr;
    }

    static class Point implements Comparable<Point> {
        double x;
        double y;
        double r;

        Point(double x, double y, double r) {
            this.x = x;
            this.y = y;
            this.r = r;
        }

        public int compareTo(Point point) {
            return Double.compare(x, point.x);
        }

        public double distanceTo(Point a) {
            return Math.hypot(a.x - x, a.y - y);
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Point point = (Point) o;

            if (Double.compare(point.x, x) != 0) return false;
            if (Double.compare(point.y, y) != 0) return false;

            return true;
        }

        public int hashCode() {
            int result;
            long temp;
            temp = x != +0.0d ? Double.doubleToLongBits(x) : 0L;
            result = (int) (temp ^ (temp >>> 32));
            temp = y != +0.0d ? Double.doubleToLongBits(y) : 0L;
            result = 31 * result + (int) (temp ^ (temp >>> 32));
            return result;
        }
    }

}