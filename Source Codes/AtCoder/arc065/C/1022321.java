import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.function.Consumer;

public class Main {

    static class Point {
        @Override
        public String toString() {
            return "Point{" +
                   "x=" + x +
                   ", y=" + y +
                   '}';
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) { return true; }
            if (o == null || getClass() != o.getClass()) { return false; }

            Point point = (Point) o;

            if (x != point.x) { return false; }
            return y == point.y;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }
    }

    static Map<Integer, List<Point>> xSet = new HashMap<>();
    static Map<Integer, List<Point>> ySet = new HashMap<>();
    static Map<Integer, TreeSet<Point>> xTree = new HashMap<>();
    static Map<Integer, TreeSet<Point>> yTree = new HashMap<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int a = scanner.nextInt() - 1;
        int b = scanner.nextInt() - 1;
        int[] xs = new int[n];
        int[] ys = new int[n];
        for (int i = 0; i < n; i++) {
            xs[i] = scanner.nextInt();
            ys[i] = scanner.nextInt();
        }
        int d = Math.abs(xs[a] - xs[b]) + Math.abs(ys[a] - ys[b]);
        for (int i = 0; i < n; i++) {
            Point point = new Point(xs[i] + ys[i], ys[i] - xs[i]);
            xSet.computeIfAbsent(point.x, integer -> {
                return new ArrayList<>();
            }).add(point);
            ySet.computeIfAbsent(point.y, integer -> {
                return new ArrayList<>();
            }).add(point);

            xTree.computeIfAbsent(point.x, integer -> {
                return new TreeSet<>(Comparator.comparing(Point::getY));
            }).add(point);
            yTree.computeIfAbsent(point.y, integer -> {
                return new TreeSet<>(Comparator.comparing(Point::getX));
            }).add(point);
        }

        xSet.values().forEach(new Consumer<List<Point>>() {
            @Override
            public void accept(List<Point> points) {
                points.sort(Comparator.comparingInt(Point::getY));
            }
        });
        ySet.values().forEach(new Consumer<List<Point>>() {
            @Override
            public void accept(List<Point> points) {
                points.sort(Comparator.comparingInt(Point::getX));
            }
        });

        Point root = new Point(xs[a] + ys[a], ys[a] - xs[a]);
        xTree.get(root.x).remove(root);
        yTree.get(root.y).remove(root);
        System.out.println(dfs(root, d) / 2);
    }

    static long dfs(Point p, int d) {
        long ret = 0;

        List<Point> uSet = ySet.get(p.y + d);
        if (uSet != null) {
            int u2 = Collections.binarySearch(uSet, new Point(p.x + d, p.y + d),
                                              Comparator.comparingInt(Point::getX));
            int u1 = Collections.binarySearch(uSet, new Point(p.x - d, p.y + d),
                                              Comparator.comparingInt(Point::getX));
            ret += getRet(u2, u1);
            TreeSet<Point> points = yTree.get(p.y + d);
            while (true) {
                Point target = points.ceiling(new Point(p.x - d, p.y + d));
                if (target == null || target.x > p.x + d) {
                    break;
                }
                points.remove(target);
                xTree.get(target.getX()).remove(target);
                ret += dfs(target, d);
            }
        }

        List<Point> dSet = ySet.get(p.y - d);
        if (dSet != null) {
            int d2 = Collections.binarySearch(dSet, new Point(p.x + d, p.y - d),
                                              Comparator.comparingInt(Point::getX));
            int d1 = Collections.binarySearch(dSet, new Point(p.x - d, p.y - d),
                                              Comparator.comparingInt(Point::getX));
            ret += getRet(d2, d1);
            TreeSet<Point> points = yTree.get(p.y - d);
            while (true) {
                Point target = points.ceiling(new Point(p.x - d, p.y - d));
                if (target == null || target.x > p.x + d) {
                    break;
                }
                points.remove(target);
                xTree.get(target.getX()).remove(target);
                ret += dfs(target, d);
            }
        }

        List<Point> rSet = xSet.get(p.x + d);
        if (rSet != null) {
            int r2 = Collections.binarySearch(rSet, new Point(p.x + d, p.y + d - 1),
                                              Comparator.comparingInt(Point::getY));
            int r1 = Collections.binarySearch(rSet, new Point(p.x + d, p.y - d + 1),
                                              Comparator.comparingInt(Point::getY));
            ret += getRet(r2, r1);

            TreeSet<Point> points = xTree.get(p.x + d);
            while (true) {
                Point target = points.ceiling(new Point(p.x + d, p.y - d));
                if (target == null || target.y > p.y + d) {
                    break;
                }
                points.remove(target);
                yTree.get(target.getY()).remove(target);
                ret += dfs(target, d);
            }
        }

        List<Point> lSet = xSet.get(p.x - d);
        if (lSet != null) {
            int l2 = Collections.binarySearch(lSet, new Point(p.x - d, p.y + d - 1),
                                              Comparator.comparingInt(Point::getY));
            int l1 = Collections.binarySearch(lSet, new Point(p.x - d, p.y - d + 1),
                                              Comparator.comparingInt(Point::getY));
            ret += getRet(l2, l1);

            TreeSet<Point> points = xTree.get(p.x - d);
            while (true) {
                Point target = points.ceiling(new Point(p.x - d, p.y - d));
                if (target == null || target.y > p.y + d) {
                    break;
                }
                points.remove(target);
                yTree.get(target.getY()).remove(target);
                ret += dfs(target, d);
            }
        }
        return ret;
    }

    private static long getRet(long d2, long d1) {
        long ret = 0;
        if (d2 >= 0 & d1 >= 0) {
            ret += d2 - d1 + 1;
        }
        if (d2 >= 0 & d1 < 0) {
            ret += d2 + d1 + 1 + 1;
        }
        if (d2 < 0 & d1 >= 0) {
            ret += -(d2 + 1) - d1;
        }
        if (d2 < 0 & d1 < 0) {
            ret += -(d2 + 1) + d1 + 1;
        }
        return ret;
    }
}