import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    static long[] lc;
    static long[] rc;
    static long[] lcMax;
    static long[] rcMax;
    static long[] x;
    static long[] v;
    static int n;
    static long c;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        c = sc.nextLong();
        x = new long[n];
        v = new long[n];
        lc = new long[n + 1];
        rc = new long[n + 1];
        lcMax = new long[n + 1];
        rcMax = new long[n + 1];
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextLong();
            v[i] = sc.nextLong();
        }
        for (int i = 0; i < n; i++) {
            lc[i + 1] = lc[i] + v[i];
        }
        for (int i = 0; i < n; i++) {
            lc[i + 1] -= x[i];
        }
        for (int i = 0; i < n; i++) {
            rc[i + 1] = rc[i] + v[n-1-i];
        }
        for (int i = 0; i < n; i++) {
            rc[i + 1] -= rX(n-1-i);
        }
        for (int i = 0; i < n; i++) {
            lcMax[i + 1] = Math.max(lcMax[i], lc[i + 1] - x[i]);
        }
        for (int i = 0; i < n; i++) {
            rcMax[i + 1] = Math.max(rcMax[i], rc[i + 1] - rX(n-1-i));
        }

        List<Long> ret = new ArrayList<>();
        ret.add(0l);
        for (int i = 0; i < n; i++) {
            long score = lc[i + 1];
            ret.add(score);
//            ret = Math.max(ret, score);
            score += rcMax[n - i - 1];
            ret.add(score);
//            ret = Math.max(ret, score);
        }
        for (int i = 0; i < n; i++) {
            long score = rc[i + 1];
            ret.add(score);
//            ret = Math.max(ret, score);
            score += lcMax[n - i - 1];
            ret.add(score);
//            ret = Math.max(ret, score);
        }
    System.out.println(ret.stream().mapToLong(Long::longValue).max().getAsLong());
    }

    public static long rX(int i) {
        return c - x[i];
    }
}