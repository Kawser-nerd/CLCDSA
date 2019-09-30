import java.awt.geom.Point2D;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        new Main().solve();
    }

    private void solve() {
        InputReader sc = new InputReader();
        int n = sc.nextInt();

        Point[] ps = new Point[n];
        for (int i = 0; i < n; i++) {
            ps[i] = new Point(sc.nextInt(), sc.nextInt());
        }

        if (n == 2) {
            System.out.println(0.5);
            System.out.println(0.5);
            return;
        }


        double[] ans = new double[n];
        mainLoop: for (int i = 0; i < n; i++) {
            Point startVec = null;
            Point endVec = null;
            Point p = ps[i];
            // System.out.printf("p: %s\n", p);
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                Point q = ps[j];
                Point qp = q.subtract(p);
                Point splitLine = qp.multiply(new Point(0, -1));  // rot 90. ???p????

                if (startVec == null) {
                    startVec = splitLine;
                    endVec = splitLine.multiply(-1);
                    // System.out.printf("qp: %s, sl: %s\n", qp, splitLine);
                }
                else {
                    double crossStart = splitLine.cross(startVec);
                    double crossEnd = splitLine.cross(endVec);
                    boolean isPerfectOpposite = Math.abs(crossStart) < EPS && startVec.dot(splitLine) < EPS
                            || Math.abs(crossEnd) < EPS && endVec.dot(splitLine) > -EPS;
                    boolean needsStartChange = crossStart < -EPS;
                    boolean needsEndChange = crossEnd < -EPS;
                    // System.out.printf("qp: %s, sl: %s, ns: %b, ne: %b\n", qp, splitLine, needsStartChange, needsEndChange);
                    if (isPerfectOpposite || needsStartChange && needsEndChange) {
                        // impossible
                        ans[i] = 0;
                        continue mainLoop;
                    }
                    else if (needsStartChange) {
                        startVec = splitLine;
                    }
                    else if (needsEndChange) {
                        endVec = splitLine.multiply(-1);
                    }
                }
            }

            double cos = startVec.dot(endVec) / startVec.distance() / endVec.distance();
            double angle = Math.acos(Math.max(-1, Math.min(cos, 1)));
            // System.out.printf("!! sv: %s, evInv: %s, ang: %f\n", startVec, endVec, Math.toDegrees(angle));
            ans[i] = angle / (2 * Math.PI);
        }


        for (int i = 0; i < n; i++) {
            System.out.printf("%.12f\n", ans[i]);

        }



    }


    static final double EPS = 1e-9;

    static boolean approxEquals(double a, double b) {
        return Math.abs(a - b) < EPS;
    }

    static class Point extends Point2D.Double implements Comparable<Point> {

        public Point() {
        }

        public Point(double x, double y) {
            super(x, y);
            // x?y?final????????????????????????????????????????
        }

        /** ???dot(v1,v2)=|v1||v2|cos? */
        double dot(Point p) {
            return x * p.x + y * p.y;
        }

        /** ???cross(v1,v2)=|v1||v2|sin? */
        double cross(Point p) {
            return x * p.y - y * p.x;
        }

        double distanceSqr() {
            return x * x + y * y;
        }

        double distance() {
            return Math.hypot(x, y);
        }

        Point add(Point p) {
            return new Point(x + p.x, y + p.y);
        }

        Point multiply(double k) {
            return new Point(k * x, k * y);
        }

        Point multiply(Point p) {  // complex mul: (x+yi)*(p.x+p.yi)
            return new Point(x * p.x - y * p.y, x * p.y + p.x * y);
        }

        Point subtract(Point p) {
            return new Point(x - p.x, y - p.y);
        }

        @Override
        public boolean equals(Object obj) {  // ?????Eclipse????????????????????
            if (this == obj) return true;
            if (obj == null) return false;
            if (getClass() != obj.getClass()) return false;
            Point other = (Point) obj;
            if (!approxEquals(x, other.x)) return false;
            if (!approxEquals(y, other.y)) return false;
            return true;
        }

        @Override
        public int compareTo(Point o) {
            if (!approxEquals(x, o.x)) return (int) Math.signum(x - o.x);
            if (!approxEquals(y, o.y)) return (int) Math.signum(y - o.y);
            return 0;
        }

        @Override
        public String toString() {
            return "(" + x + "," + y + ")";
        }

    }

    /**
     * @return ???? a->b ???????? b->c ??????1??????-1?
     *         ????????
     * @see http://www.prefield.com/algorithm/geometry/ccw.html
     */
    static int ccw(Point a, Point b, Point c) {
        b = b.subtract(a);
        c = c.subtract(a);
        if (b.cross(c) > EPS) return +1;                  // counter clockwise
        if (b.cross(c) + EPS < 0) return -1;              // clockwise
        if (b.dot(c) + EPS < 0) return +2;                // c--a--b on line and a!=c
        if (b.distanceSqr() < c.distanceSqr()) return -2; // a--b--c on line or a==b??????a==b?????????
        return 0;                                         // a--c--b on line or b==c
    }

    static class InputReader extends BufferedReader {
        StringTokenizer st = new StringTokenizer("");

        public InputReader() {
            super(new InputStreamReader(System.in));
        }

        public InputReader(String s) {
            super(new StringReader(s));
        }

        String next() {
            try {
                while (!st.hasMoreTokens())
                    st = new StringTokenizer(readLine());
            }
            catch (IOException e) {
                throw new RuntimeException(e);
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}