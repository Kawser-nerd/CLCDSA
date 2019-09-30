import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;

    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);

    private static final int INF = Integer.MAX_VALUE / 2;

    private static class Point implements Comparable<Point> {
        long x;
        long y;
        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
        @Override
        public boolean equals(Object o) {
            if (o instanceof Point) {
                Point that = (Point)o;
                return this.x == that.x && this.y == that.y;
            }
            return false;
        }
        @Override
        public int hashCode() {
            int hashCode = 17;
            hashCode = hashCode * 31 + Long.hashCode(x);
            hashCode = hashCode * 31 + Long.hashCode(y);
            return hashCode;
        }
        @Override
        public int compareTo(Point that) {
            if (this.x < that.x) {
                return -1;
            } else if (this.x > that.x) {
                return 1;
            } else if (this.y < that.y) {
                return -1;
            } else if (this.x > that.x) {
                return 1;
            } else {
                return 0;
            }
        }
        @Override
        public String toString() {
            return "(" + x + ", " + y + ")";
        }
    }

    private void solve(Scanner sc) {
        int N = sc.nextInt();
        int K = sc.nextInt();
        Set<Point> pSet = new HashSet<>();
        List<Long> xList = new ArrayList<>();
        List<Long> yList = new ArrayList<>();
        for (int i = 0; i < N; ++i) {
            long x = sc.nextLong();
            long y = sc.nextLong();
            Point p = new Point(x, y);
            pSet.add(p);
            xList.add(x);
            yList.add(y);
        }

        long minX = Long.MIN_VALUE;
        long maxX = Long.MAX_VALUE;
        long minY = Long.MIN_VALUE;
        long maxY = Long.MAX_VALUE;

        long minArea = Long.MAX_VALUE;

        for (long x1 : xList) {
            for (long x2 : xList) {
                if (x1 >= x2) {
                    continue;
                }
                for (long y1 : yList) {
                    for (long y2 : yList) {
                        if (y1 >= y2) {
                            continue;
                        }
                        int cnt = 0;
                        for (Iterator<Point> it = pSet.iterator(); it.hasNext();) {
                            Point p = it.next();
                            if (x1 <= p.x && p.x <= x2 && y1 <= p.y && p.y <= y2) {
                                ++cnt;
                            }
                        }
                        if (cnt >= K) {
                            if ((x2 - x1) * (y2 - y1) < minArea) {
                                minX = x1;
                                maxX = x2;
                                minY = y1;
                                maxY = y2;
                                minArea = (x2 - x1) * (y2 - y1);
                            }
                        }
                    }
                }
            }
        }

        _out.println((maxX - minX) * (maxY - minY));
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