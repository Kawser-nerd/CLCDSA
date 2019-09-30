import java.util.*;
public class Main {
    static long INF = 1000000000000L;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int q = sc.nextInt();
        long[] s = new long[a + 2];
        long[] t = new long[b + 2];
        long[] x = new long[q + 2];
        s[0] = -INF;
        for (int i = 1; i <= a; i++) {
            s[i] = sc.nextLong();
        }
        s[a + 1] = INF;

        t[0] = -INF;
        for (int i = 1; i <= b; i++) {
            t[i] = sc.nextLong();
        }
        t[b + 1] = INF;

        for (int i = 0; i < q; i++) {
            x[i] = sc.nextLong();
        }
        Arrays.sort(s);
        Arrays.sort(t);
        for (int i = 0; i < q; i++) {
            int ok = binSearch(s, a + 1, -1, x[i]);
            long sb = s[ok];
            long sa = s[ok - 1];

            ok = binSearch(t, b + 1, -1, x[i]);
            long tb = t[ok];
            long ta = t[ok - 1];

            long res1 = Math.abs(tb - x[i]) * 2 + Math.abs(sa - x[i]);
            long res2 = Math.abs(sa - x[i]) * 2 + Math.abs(tb - x[i]);
            long res3 = Math.abs(ta - x[i]) * 2 + Math.abs(sb - x[i]);
            long res4 = Math.abs(sb - x[i]) * 2 + Math.abs(ta - x[i]);
            long res5 = Math.abs(ta - x[i]) + Math.abs(sa - ta);
            long res6 = Math.abs(sa - x[i]) + Math.abs(ta - sa);
            long res7 = Math.abs(tb - x[i]) + Math.abs(sb - tb);
            long res8 = Math.abs(sb - x[i]) + Math.abs(tb - sb);
            long ans = Math.min(res1,
                Math.min(res2,
                    Math.min(res3,
                        Math.min(res4, Math.min(res5, Math.min(res6, Math.min(res7, res8)))))));
            System.out.println(ans);
        }
    }
    public static int binSearch(long[] s, long ok, long ng, long x) {
        while (Math.abs(ok - ng) > 1) {
            long mid = (ok + ng) / 2;
            if (solve(s[(int) mid], x)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return (int) ok;
    }
    public static boolean solve(long s, long x) {
        if (s > x) {
            return true;
        }
        return false;
    }
}