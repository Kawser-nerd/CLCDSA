import java.util.*;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class A {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("A.in"));
        PrintWriter out = new PrintWriter("A.out");

        int t = in.nextInt();
        in.nextLine();
        for (int tn = 0; tn < t; tn++) {
            out.println("Case #" + (tn + 1) + ": " + solve(in));
        }

        out.close();

    }

    static boolean[][] a;

    private static String solve(Scanner in) {
        int h = in.nextInt();
        int w = in.nextInt();
        a = new boolean[h + 2][w + 2];
        Position start = new Position(new ArrayList<Point>());
        Position finish = new Position(new ArrayList<Point>());
        for (int y = 0; y < h; y++) {
            String s = in.next();
            for (int x = 0; x < w; x++) {
                char c = s.charAt(x);
                if (c != '#') a[y + 1][x + 1] = true;
                if (c == 'o' || c == 'w') start.p.add(new Point(x + 1, y + 1));
                if (c == 'x' || c == 'w') finish.p.add(new Point(x + 1, y + 1));
            }
        }
        Collections.sort(start.p);
        Collections.sort(finish.p);

        int[] dx = {-1, 0, 0, 1};
        int[] dy = {0, -1, 1, 0};

        Queue<Position> q = new LinkedList<Position>();
        Map<Position, Integer> d = new HashMap<Position, Integer>();
        q.add(start);
        d.put(start, 0);
        while (!q.isEmpty()) {
            Position a = q.remove();
            //printPosition(a);
            int ds = d.get(a);
            if (a.equals(finish)) return "" + ds;
            for (int i = 0; i < a.p.size(); i++) {
                for (int j = 0; j < 4; j++) {
                    boolean ok = true;
                    int xx = a.p.get(i).x - dx[j];
                    int yy = a.p.get(i).y - dy[j];
                    if (a.isEmpty(xx, yy)) {

                        List<Point> pp = new ArrayList<Point>(a.p);
                        pp.set(i, new Point(
                                pp.get(i).x + dx[j],
                                pp.get(i).y + dy[j]
                        ));
                        Position b = new Position(pp);
                        if (d.get(b) == null) {
                            if (b.isValid()) {
                                if (a.isStable() || b.isStable()) {
                                    d.put(b, ds + 1);
                                    q.add(b);
                                }
                            }
                        }
                    }
                }
            }
        }
        return "-1";
    }

    private static void printPosition(Position a) {
        System.out.println(a.p);
    }

    static class Position {
        List<Point> p;

        Position(List<Point> p) {
            Collections.sort(p);
            this.p = p;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Position position = (Position) o;

            if (p != null ? !p.equals(position.p) : position.p != null) return false;

            return true;
        }

        public int hashCode() {
            return (p != null ? p.hashCode() : 0);
        }

        public boolean isValid() {
            for (Point point : p) {
                if (!a[point.y][point.x]) return false;
            }
            for (int i = 0; i < p.size(); i++) {
                for (int j = 0; j < i; j++) {
                    if (p.get(i).equals(p.get(j))) return false;
                }
            }
            return true;
        }

        public boolean isStable() {
            int n = p.size();
            int[] q = new int[n];
            for (int i = 0; i < n; i++) q[i] = i;
            int c = n;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++)
                    if (q[i] != q[j]) {
                        if (Math.abs(p.get(i).x - p.get(j).x) + Math.abs(p.get(i).y - p.get(j).y) == 1) {
                            int l = q[i];
                            for (int k = 0; k < n; k++) {
                                if (q[k] == l) q[k] = q[j];
                            }
                            c--;
                        }
                    }
            }
            return c == 1;
        }

        public boolean isEmpty(int x, int y) {
            if (!a[y][x]) return false;
            for (Point point : p) {
                if (point.x == x && point.y == y) return false;
            }
            return true;
        }
    }

    static class Point implements Comparable<Point> {
        final int x;
        final int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Point point = (Point) o;

            if (x != point.x) return false;
            if (y != point.y) return false;

            return true;
        }

        public int hashCode() {
            int result;
            result = x;
            result = 31 * result + y;
            return result;
        }

        public int compareTo(Point point) {
            if (point.y == y) {
                return x - point.x;
            } else {
                return y - point.y;
            }
        }
    }

}