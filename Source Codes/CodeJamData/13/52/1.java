package contest;

import java.util.*;
import java.io.*;
import java.awt.*;

class GeometryUtils {
    public static class Point {
        public int x, y;
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static class Segment {
        public Point p1, p2;
        int A, B, C;
        public Segment(Point p1, Point p2) {
            this.p1 = p1;
            this.p2 = p2;

            this.A = p2.y - p1.y;
            this.B = p1.x - p2.x;
            this.C = - A * p1.x - B * p1.y;
        }
        public int signOf(Point p) {
            int Z = p.x * A + p.y * B + C;
            if (Z > 0) return 1;
            if (Z < 0) return -1;
            return 0;
        }
    }

    private static class PolygonSegment extends Segment {
        int polygonId;

        public PolygonSegment(Point p1, Point p2, int polygonId) {
            super(p1, p2);
            this.polygonId = polygonId;
        }
    }

    public enum IntersectionResult {NOTHING, SINGLE_POINT, MANY_POINTS}

    private static IntersectionResult intersectLineSegments(int a, int b, int c, int d) {
        if (a > b) {
            int tmp = a; a = b; b = tmp;
        }
        if (c > d) {
            int tmp = c; c = d; d = tmp;
        }
        int left = Math.max(a, c);
        int right = Math.min(b, d);
        if (left < right) {
            return IntersectionResult.MANY_POINTS;
        }
        if (left == right) {
            return IntersectionResult.SINGLE_POINT;
        }
        return IntersectionResult.NOTHING;
    }

    public static IntersectionResult intersectSegments(Segment a, Segment b) {
        int Z1 = b.signOf(a.p1);
        int Z2 = b.signOf(a.p2);
        int Z3 = a.signOf(b.p1);
        int Z4 = a.signOf(b.p2);

        if (Z1 == 0 && Z2 == 0) {
            if (b.p1.x == b.p2.x) {
                return intersectLineSegments(a.p1.y, a.p2.y, b.p1.y, b.p2.y);
            } else {
                return intersectLineSegments(a.p1.x, a.p2.x, b.p1.x, b.p2.x);
            }
        } else {
            if (Z1 * Z2 <= 0 && Z3 * Z4 <= 0) {
                return IntersectionResult.SINGLE_POINT;
            } else {
                return IntersectionResult.NOTHING;
            }
        }
    }

    public static boolean isPolygon(Polygon p) {
        int N = p.npoints;
        int[] x = p.xpoints;
        int[] y = p.ypoints;
        Segment[] s = new Segment[N];
        for (int i=0; i < N; i++) {
            s[i] = new Segment(new Point(x[i], y[i]), new Point(x[(i+1)%N], y[(i+1)%N]));
            if (s[i].p1.x == s[i].p2.x && s[i].p1.y == s[i].p2.y) {
                return false;
            }
        }
        for (int i=0; i < N; i++) {
            for (int j=i+1; j < N; j++) {
                IntersectionResult exp = (j == i + 1 || j == N - 1 && i == 0 ? IntersectionResult.SINGLE_POINT : IntersectionResult.NOTHING);
                if (exp != intersectSegments(s[i], s[j])) {
                    return false;
                }
            }
        }
        return true;
    }

    public static double polygonArea(Polygon p) {
        double res = 0.0;
        int N = p.npoints;
        int[] x = p.xpoints;
        int[] y = p.ypoints;
        for (int i=0; i < N; i++) {
            res += (x[(i + 1) % N] - x[i]) * (y[i] + y[(i + 1) % N]);
        }
        return Math.abs(res) / 2.0;
    }
}


public class Rural {
    final static String PROBLEM_NAME = "rural";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    int N;
    int[] x, y;
    int[] p;
    double bestArea = -1.0;
    int[] ans;
    boolean[] used;

    void go(int pos) {
        if (pos == N) {
            Polygon poly = new Polygon();
            for (int i=0; i<N; i++)
                poly.addPoint(x[p[i]], y[p[i]]);
            if (GeometryUtils.isPolygon(poly)) {
                double area = GeometryUtils.polygonArea(poly);
                if (area > bestArea) {
                    bestArea = area;
                    ans = p.clone();
                }
            }
            return;
        }
        for (p[pos] = 0; p[pos] < N; p[pos]++) if (!used[p[pos]]) {
            used[p[pos]] = true;
            go(pos+1);
            used[p[pos]] = false;
        }
    }

    void solve(Scanner sc, PrintWriter pw) {
        N = sc.nextInt();
        x = new int[N];
        y = new int[N];
        for (int i=0; i<N; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }
        used = new boolean[N];
        p = new int[N];
        p[0] = 0;
        used[0] = true;
        go(1);
        for (int i=0; i<N; i++) pw.print(" " + ans[i]);
        pw.println();
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Rural().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
