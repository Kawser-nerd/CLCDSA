import java.util.*;
import static java.lang.Math.*;

public class C {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int zz = 1; zz <= T; zz++) {
            int N = in.nextInt();
            Point[] P = new Point[N];
            for (int i = 0; i < N; i++)
                P[i] = new Point(in.nextInt(), in.nextInt());

            System.out.format("Case #%d:\n", zz);
            for (int i = 0; i < N; i++) {
                ArrayList<Point> R = new ArrayList<Point>();
                for (int j = 0; j < N; j++) {
                    if (j == i)
                        continue;
                    R.add(P[j].sub(P[i]));
                }
                Collections.sort(R);
                for (int j = 0; j < N - 1; j++)
                    R.add(R.get(j));
                //System.out.println(R);
                int ans = N - 1;
                int end = 1;
                for (int j = 0; j < N - 1; j++) {
                    while (end < j + N - 1) {
                        long ccw = R.get(end).dot(R.get(j).rotate());
                        long dot = R.get(end).dot(R.get(j));
                        //System.out.println("\t\t"+j+" "+end+" "+ccw+" "+dot);
                        if (ccw < 0)
                            break;
                        if (ccw == 0) {
                            if (dot < 0)
                                break;
                            if (end >= N-1)
                                break;
                        }
                        end++;
                    }
                    //System.out.println("\t"+j+" "+end);
                    ans = min(ans, end - j - 1);
                }
                if (ans == N) {
                    System.out.println(N+" "+Arrays.toString(P));
                    throw new RuntimeException();
                }
                System.out.format("%d\n", ans);
            }
        }
    }
    static double eps = 1e-12;
    static boolean eq(double a, double b) {
        return abs(a - b) < eps;
    }
    static class Point implements Comparable<Point> {
        long x, y;
        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
        public Point sub(Point p) {
            return new Point(x - p.x, y - p.y);
        }
        public long dot(Point p) {
            return x * p.x + y * p.y;
        }
        public Point rotate() {
            return new Point(-y, x);
        }
        public double ang() {
            double ang = atan2(y, x);
            if (ang < 0)
                ang += 2*PI;
            return ang;
        }
        public int compareTo(Point p) {
            double a1 = ang();
            double a2 = p.ang();
            if (eq(a1, a2))
                return 0;
            if (a1 < a2)
                return -1;
            return 1;
        }
        public String toString() {
            return String.format("(%d, %d)", x, y);
        }
    }
}
