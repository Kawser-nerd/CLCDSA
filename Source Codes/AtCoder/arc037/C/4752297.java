import java.util.*;
public class Main {
    static int n;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        long k = sc.nextLong();
        long[] a = new long[n];
        long[] b = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextLong();
        }
        Arrays.sort(a);
        Arrays.sort(b);
        long max = a[n - 1] * b[n - 1];
        System.out.println(binSearch(max, -1, k, a, b));
    }
    public static long binSearch(long ok, long ng, long k, long[] a, long[] b) {
        while (Math.abs(ok - ng) > 1) {
            long mid = (ok + ng) / 2;
            if (solve(mid, a, b) >= k) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok;
    }
    public static long solve(long k, long[] a, long[] b) {
        long cnt = 0;
        for (int i = 0; i < n; i++) {
            if (b[0] * a[i] > k) {
                continue;
            }
            long ok = 0;
            long ng = n;
            while (Math.abs(ok - ng) > 1) {
                long mid = (ok + ng) / 2;
                if (b[(int) mid] * a[i] <= k) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            cnt += ok + 1;
        }
        return cnt;
    }
}