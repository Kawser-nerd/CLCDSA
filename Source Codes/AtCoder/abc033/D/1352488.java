import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = true;

    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);

    private Map<String, Double> memo = new HashMap<>();

    private void solve(Scanner sc) {
        int N = sc.nextInt();
        List<Point> list = new ArrayList<>();
        for (int i = 0; i < N; ++i) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            list.add(new Point(x, y));
        }
        long ct1 = 0;
        long ct2 = 0;
        long ct3 = 0;
        for (int i = 0; i < N; ++i) {
            int ct = 0;
            double[] atan2 = new double[N + N - 2];
            Point p1 = list.get(i);
            for (int j = 0; j < N; ++j) {
                if (i != j) {
                    Point p2 = list.get(j);
                    atan2[ct] = Math.atan2(p2.y - p1.y, p2.x - p1.x);
                    if (atan2[ct] < 0) {
                        atan2[ct] += Math.PI * 2;
                    }
                    ++ct;
                }
            }
            for (int j = 0; j < N - 1; ++j) {
                atan2[ct++] = atan2[j] + Math.PI * 2;
            }
            Arrays.sort(atan2);
            for (int j = 0; j < N - 1; ++j) {
                int tmp1 = 0;
                for (int k = 0; k < ct && atan2[tmp1] < atan2[j] + Math.PI / 2 - 1e-9; ++k) {
                    ++tmp1;
                }
                int tmp2 = tmp1;
                for (int k = tmp1; k < ct && atan2[tmp2] < atan2[j] + Math.PI / 2 + 1e-9; ++k) {
                    ++tmp2;
                }
                int tmp3 = tmp2;
                for (int k = tmp2; k < ct && atan2[tmp3] < atan2[j] + Math.PI - 1e-9; ++k) {
                    ++tmp3;
                }
                ct2 += tmp2 - tmp1;
                ct3 += tmp3 - tmp2;
            }
        }
        ct1 = (long)N * (N - 1) * (N - 2) / 6 - ct2 - ct3;

        _out.printf("%d %d %d%n", ct1, ct2, ct3);
    }
    private double innerProduct(Point p11, Point p12, Point p21, Point p22) {
        long a1 = p12.x - p11.x;
        long b1 = p12.y - p11.y;
        long a2 = p22.x - p21.x;
        long b2 = p22.y - p21.y;

        return a1 * a2 + b1 * b2;
    }
    private static BigInteger C(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        for (long i = r; i > 1; --i) {
            res = res.divide(BigInteger.valueOf(i));
        }
        return res;
    }
    private static BigInteger P(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        return res;
    }
    private static class Point implements Comparable<Point> {
        long x;
        long y;
        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
        public boolean equals(Object o) {
            if (o instanceof Point) {
                Point that = (Point)o;
                return this.x == that.x && this.y == that.y;
            }
            return false;
        }
        public int hashCode() {
            int hashCode = 17;
            hashCode = hashCode * 31 + (int)(x ^ (x >>> 32));
            hashCode = hashCode * 31 + (int)(y ^ (y >>> 32));
            return hashCode;
        }
        public int compareTo(Point that) {
            if (this.x != that.x) {
                return this.x > that.x ? 1 : -1;
            }
            if (this.y != that.y) {
                return this.y > that.y ? 1 : -1;
            }
            return 0;
        }
    }
    /*
     * 10^10 > Integer.MAX_VALUE = 2147483647 > 10^9
     * 10^19 > Long.MAX_VALUE = 9223372036854775807L > 10^18
     */
    public static void main(String[] args) {
        long S = System.currentTimeMillis();

        Scanner sc = new Scanner(System.in);
        new Main().solve(sc);
        _out.flush();

        long G = System.currentTimeMillis();
        if (elapsed) {
            _err.println((G - S) + "ms");
        }
        _err.flush();
    }
}