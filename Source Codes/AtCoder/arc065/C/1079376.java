import java.util.*;

/**
 * Created by zzt on 17-1-16.
 */
public class Main {
    static Map<Integer, List<Point>> xSet = new HashMap<>();
    static Map<Integer, List<Point>> ySet = new HashMap<>();
    static Map<Integer, TreeSet<Point>> xTree = new HashMap<>();
    static Map<Integer, TreeSet<Point>> yTree = new HashMap<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int a = scanner.nextInt() - 1;
        int b = scanner.nextInt() - 1;

        int[][] pinholes = new int[N][2];
        for (int i = 0; i < N; i++) {
            pinholes[i][0] = scanner.nextInt();
            pinholes[i][1] = scanner.nextInt();
        }

        int d = Math.abs(pinholes[a][0] - pinholes[b][0]) + Math.abs(pinholes[a][1] - pinholes[b][1]);
        for (int i = 0; i < N; i++) {
            Point point = new Point(pinholes[i][0] + pinholes[i][1], pinholes[i][1] - pinholes[i][0]);
            xSet.computeIfAbsent(point.x, integer -> new ArrayList<>()).add(point);
            ySet.computeIfAbsent(point.y, integer -> new ArrayList<>()).add(point);
            xTree.computeIfAbsent(point.x, integer -> new TreeSet<>(Comparator.comparing(Point::getY))).add(point);
            yTree.computeIfAbsent(point.y, integer -> new TreeSet<>(Comparator.comparing(Point::getX))).add(point);
        }

        xSet.values().forEach(points -> points.sort(Comparator.comparing(Point::getY)));
        ySet.values().forEach(points -> points.sort(Comparator.comparing(Point::getX)));

        Point root = new Point(pinholes[a][0] + pinholes[a][1], pinholes[a][1] - pinholes[a][0]);
        xTree.get(root.x).remove(root);
        yTree.get(root.y).remove(root);
        System.out.println(dfs(root,d)/2);
    }

    static long dfs(Point p, int d) {
        long ret = 0;
        List<Point> uSet = ySet.get(p.y + d);
        if (uSet != null) {
            int u1 = Collections.binarySearch(uSet, new Point(p.x + d, p.y + d),
                    Comparator.comparing(Point::getX));
            int u2 = Collections.binarySearch(uSet, new Point(p.x - d, p.y + d),
                    Comparator.comparing(Point::getX));
            ret += getRet(u1, u2);
            TreeSet<Point> points = yTree.get(p.y + d);
            while (true) {
                Point target = points.ceiling(new Point(p.x - d, p.y + d));
                if (target == null || target.x > p.x + d) break;
                points.remove(target);
                xTree.get(target.getX()).remove(target);
                ret += dfs(target, d);
            }
        }

        List<Point> dSet = ySet.get(p.y - d);
        if (dSet != null) {
            int d1 = Collections.binarySearch(dSet, new Point(p.x + d, p.y - d),
                    Comparator.comparing(Point::getX));
            int d2 = Collections.binarySearch(dSet, new Point(p.x - d, p.y - d),
                    Comparator.comparing(Point::getX));
            ret += getRet(d1, d2);
            TreeSet<Point> points = yTree.get(p.y - d);
            while (true) {
                Point target = points.ceiling(new Point(p.x - d, p.y - d));
                if (target == null || target.x > p.x + d) break;
                points.remove(target);
                xTree.get(target.getX()).remove(target);
                ret += dfs(target, d);
            }
        }

        List<Point> rSet = xSet.get(p.x + d);
        if (rSet != null) {
            int r1 = Collections.binarySearch(rSet, new Point(p.x + d, p.y + d - 1),
                    Comparator.comparingInt(Point::getY));
            int r2 = Collections.binarySearch(rSet, new Point(p.x + d, p.y - d + 1),
                    Comparator.comparingInt(Point::getY));
            ret += getRet(r1, r2);

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
            int l1 = Collections.binarySearch(lSet, new Point(p.x - d, p.y + d - 1),
                    Comparator.comparingInt(Point::getY));
            int l2 = Collections.binarySearch(lSet, new Point(p.x - d, p.y - d + 1),
                    Comparator.comparingInt(Point::getY));
            ret += getRet(l1, l2);

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

    static long getRet(long d1, long d2) {
        long ret = 0;
        if (d1 >= 0 && d2 >= 0) {
            ret += d1 - d2 + 1;
        }
        if (d1 >= 0 && d2 < 0) {
            ret += d1 + d2 + 2;
        }
        if (d1 < 0 && d2 >= 0) {
            ret += -(d1 + 1) - d2;
        }
        if (d1 < 0 && d2 < 0) {
            ret += -(d1 + 1) + d2 + 1;
        }
        return ret;
    }
}

class Point {
    int x, y;

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
}