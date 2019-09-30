import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Logging {

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static class Vector {
        final long dx, dy;

        public Vector(long dx, long dy) {
            long g = gcd(Math.abs(dx), Math.abs(dy));
            this.dx = dx / g;
            this.dy = dy / g;
        }

        public long vecMul(Vector v) {
            return v.dx * dy - dx * v.dy;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Vector vector = (Vector) o;

            if (dx != vector.dx) return false;
            return dy == vector.dy;

        }

        @Override
        public int hashCode() {
            int result = (int) (dx ^ (dx >>> 32));
            result = 31 * result + (int) (dy ^ (dy >>> 32));
            return result;
        }

        public static final Comparator<Vector> LIKE_ATAN2 = new Comparator<Vector>() {
            @Override
            public int compare(Vector v1, Vector v2) {
                if (v1.equals(v2))
                    return 0;
                if (v1.dy == 0 && v1.dx > 0)
                    return -1;
                if (v1.dy > 0 && v2.dy < 0)
                    return -1;
                if (v1.dy < 0 && v2.dy > 0)
                    return 1;
                if (v2.dy == 0 && v2.dx > 0)
                    return 1;
                return Long.signum(v1.vecMul(v2));
            }
        };

        @Override
        public String toString() {
            return "(" + dx + ", " + dy + ")";
        }
    }

    static class Point {
        final long x, y;

        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    static int solve(ArrayList<Point> points, Point center) {
        if (points.size() == 0)
            return 0;
        ArrayList<Vector> vectors = new ArrayList<>();
        for (Point p : points) {
            vectors.add(new Vector(p.x - center.x, p.y - center.y));
        }
        Collections.sort(vectors, Vector.LIKE_ATAN2);
        vectors.addAll(vectors); // lol it works
        vectors.addAll(vectors);
        int right = 0;
        for (right = 0; right < vectors.size(); right++) {
            int s = Long.signum(vectors.get(0).vecMul(vectors.get(right)));
            //System.out.println(vectors.get(0) + " vs " + vectors.get(right) + " : " + s);
            if (s == 1) {
                break;
            }
            if (right >= points.size())
                return 0;
        }
        right--;
        int left = 0;
        while (vectors.get(left).vecMul(vectors.get(right)) == 0)
            right++;

        int ans = right - left;
        outer: while (right < vectors.size() && left < vectors.size()) {
            while (vectors.get(left).vecMul(vectors.get(right)) < 0) {
                right++;
                if (right == vectors.size())
                    break outer;
            }
            left++;
            ans = Math.min(ans, right - left);
        }

        return Math.max(ans, 0);
    }

    static ArrayList<Integer> solve(ArrayList<Point> points) {
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < points.size(); i++) {
            ArrayList<Point> withoutI = new ArrayList<>(points);
            withoutI.remove(i);
            res.add(solve(withoutI, points.get(i)));
        }
        return res;
    }

    public static void main(String[] args) {
        /*
        ArrayList<Point> vs = new ArrayList<>();
        for (int dx = -1; dx < 2; dx++) {
            for (int dy = -1; dy < 2; dy++) {
                if (dx != 0 || dy != 0) {
                    vs.add(new Point(dx, dy));
                }
            }
        }
        System.out.println(solve(vs, new Point(10, 10)));
        if (true)
            return;
        */
        Scanner in = new Scanner(System.in);
        int tests = in.nextInt();
        for (int t = 0; t < tests; t++) {
            System.err.println(t);
            int n = in.nextInt();
            ArrayList<Point> points = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                points.add(new Point(in.nextLong(), in.nextLong()));
            }
            ArrayList<Integer> ans = solve(points);
            System.out.println("Case #" + (t + 1) + ":");
            for (int i : ans) {
                System.out.println(i);
            }
        }
    }
}
