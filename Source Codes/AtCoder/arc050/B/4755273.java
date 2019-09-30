import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long r = sc.nextLong();
        long b = sc.nextLong();
        long x = sc.nextLong();
        long y = sc.nextLong();
        long ans = binSearch(r, b, x, y);
        System.out.println(ans);
    }
    public static long binSearch(long r, long b, long x, long y) {
        long ok = 0;
        long ng = Math.min(r, b) + 1;
        while (Math.abs(ok - ng) > 1) {
            long mid = (ok + ng) / 2;
            if (solve(mid, r, b, x, y)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok;
    }
    public static boolean solve(long k, long r, long b, long x, long y) {
        long rnum = (r - k) / (x - 1);
        long bnum = (b - k) / (y - 1);
        if (rnum + bnum >= k) {
            return true;
        }
        return false;
    }
}