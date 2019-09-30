import java.util.*;
public class Main {
    static int n;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        long[] h = new long[n];
        long[] s = new long[n];
        long hmax = 0;
        long smax = 0;
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextLong();
            s[i] = sc.nextLong();
            hmax = Math.max(hmax, h[i]);
            smax = Math.max(smax, s[i]);
        }
        long ans = binSearch(s, h, hmax + n * smax, -1L);
        System.out.println(ans);
    }
    public static long binSearch(long[] s, long[] h, long ok, long ng) {
        while (Math.abs(ok - ng) > 1) {
            long mid = (ok + ng) / 2;
            if (solve(mid, s, h)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok;
    }
    public static boolean solve(long x, long[] s, long[] h) {
        long[] time = new long[n];
        for (int i = 0; i < n; i++) {
            if (x - h[i] < 0) {
                return false;
            }
            time[i] = (x - h[i]) / s[i];
        }
        Arrays.sort(time);
        for (int i = 0; i < n; i++) {
            // i??????????????
            if (time[i] < i) {
                return false;
            }
        }
        return true;
    }
}