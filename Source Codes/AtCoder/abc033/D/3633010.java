import java.awt.geom.Point2D;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static Point[] P;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();

        P = new Point[N];
        for (int i = 0; i < N; i++) {
            P[i] = new Point(fc.nextInt(), fc.nextInt());
        }
        System.out.println(solve());
    }

    static String solve() {
        int don = 0;
        int cyoku = 0;
        for (int i = 0; i < N; i++) {
            Result r = calc(i);
            don += r.don;
            cyoku += r.cyoku;
        }

        // N=2000?long????????????
        long ei = ((long)N * (N-1) * (N-2)) / 6 - don - cyoku;
        return ei + " " + cyoku + " " + don;
    }

    static Result calc(int bi) {
        Point b = P[bi];
        int ai = bi == 0 ? 1 : 0;
        Point a = P[ai];
        Point ba = Point.vector(b, a);
        Pointangle[] angles = new Pointangle[N-1];
        angles[0] = new Pointangle(a, 0.0);
        int idx = 1;
        for (int i = 0; i < N; i++) {
            if( i == ai || i == bi ) continue;

            Point c = P[i];
            Point bc = Point.vector(b, c);

            angles[idx++] = new Pointangle(c, Point.angle(ba, bc));
        }
        Arrays.sort(angles, Comparator.comparingDouble(pa -> pa.angle));

        int don = 0;
        int cyoku = 0;
        // i(0) -> j(90) -> k(180)
        // ?????radian??????????????????...
        int j = 0;
        int k = 0;
        int L = angles.length;
        for (int i = 0; i < L; i++) {
            Pointangle ip = angles[i];
            while( k < i + L ) {
                Pointangle kp = angles[k % L];
                if( canSankaku(ip, kp) ) {
                    k++;

                } else {
                    break;
                }
            }

            while( j < k ) {
                Pointangle jp = angles[j % L];
                if( isCyokuOrUnder(ip, jp, b) ) {
                    j++;

                } else {
                    break;
                }
            }

            // [i, j)????+?????????
            int ei = j - i - 1;
            int san = k - i - 1;
            don += san - ei;

            // ????
            if( isCyoku(ip, angles[(j-1) % L], b)) {
                cyoku++;
            }
        }

        return new Result(don, cyoku);
    }

    static boolean canSankaku(Pointangle ba, Pointangle bc) {
        double angle = bc.angle - ba.angle;
        if( angle < 0 ) angle += Math.PI * 2;
        return angle < Math.PI;
    }

    static boolean isCyokuOrUnder(Pointangle ba, Pointangle bc, Point b) {
        if( isCyoku(ba, bc, b ) ) return true;

        // 2PI???
        double angle = bc.angle - ba.angle;
        if( angle < 0 ) angle += Math.PI * 2;
        return angle < Math.PI / 2;
    }

    static boolean isCyoku(Pointangle ba, Pointangle bc, Point b) {
        Point a = ba.point;
        Point c = bc.point;

        // ??int??????????...
        long ab_d = (long)((int)a.x - (int)b.x) * ((int)a.x - (int)b.x) + (long)((int)a.y - (int)b.y) * ((int)a.y - (int)b.y);
        long cb_d = (long)((int)c.x - (int)b.x) * ((int)c.x - (int)b.x) + (long)((int)c.y - (int)b.y) * ((int)c.y - (int)b.y);
        long ca_d = (long)((int)c.x - (int)a.x) * ((int)c.x - (int)a.x) + (long)((int)c.y - (int)a.y) * ((int)c.y - (int)a.y);

        return ab_d + cb_d == ca_d;
    }

    static class Pointangle {
        Point point;
        double angle;

        public Pointangle(Point point, double angle) {
            this.point = point;
            this.angle = angle;
        }

        public String toString() {
            return "(" + point + ", " + BigDecimal.valueOf(Math.toDegrees(angle)).toPlainString() + ")";
        }
    }

    static class Result {
        int don;
        int cyoku;

        public Result(int don, int cyoku) {
            this.don = don;
            this.cyoku = cyoku;
        }
    }

    static class Point {

        static double angle(Point va, Point vb) {
            double cos = (va.x * vb.x + va.y * vb.y) / (va.scalar() * vb.scalar());
            if( outerProduct(va, vb) > 0 ) {
                return Math.acos(cos);
            } else {
                return Math.PI * 2 - Math.acos(cos);
            }
        }

        static double outerProduct(Point va, Point vb) {
            return va.x * vb.y - va.y * vb.x;
        }

        static Point of(double x, double y) {
            return new Point(x, y);
        }

        static Point vector(Point a, Point b) {
            // a -> b
            return b.subtract(a);
        }

        final double x;
        final double y;

        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        Point subtract(Point p) {
            return of(x - p.x, y - p.y);
        }

        double distance(Point p) {
            return Point2D.distance(x, y, p.x, p.y);
        }

        double scalar() {
            return distance(of(0, 0));
        }

        public String toString() {
            return "(" + BigDecimal.valueOf(x).toPlainString() + ", " + BigDecimal.valueOf(y).toPlainString() + ")";
        }
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}