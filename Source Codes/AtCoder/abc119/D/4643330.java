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
            long ok = a + 1;
            long ng = -1;
            while (Math.abs(ok - ng) > 1) {
                long mid = (ok + ng) / 2;
                if (solve(s[(int) mid], x[i])) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }

            long sb = s[(int) ok];
            long sa = s[(int) ok - 1];
            ok = b + 1;
            ng = -1;
            while (Math.abs(ok - ng) > 1) {
                long mid = (ok + ng) / 2;
                if (solve(t[(int) mid], x[i])) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            long tb = t[(int) ok];
            long ta = t[(int) ok - 1];

            // System.out.println("sa = " + sa);
            // System.out.println("ta = " + ta);
            // System.out.println("sb = " + sb);
            // System.out.println("tb = " + tb);
            long res1 = Math.abs(tb - x[i]) * 2 + Math.abs(sa - x[i]);
            long res2 = Math.abs(sa - x[i]) * 2 + Math.abs(tb - x[i]);
            long res3 = Math.abs(ta - x[i]) * 2 + Math.abs(sb - x[i]);
            long res4 = Math.abs(sb - x[i]) * 2 + Math.abs(ta - x[i]);
            long res5 = Math.abs(ta - x[i]) + Math.abs(sa - ta);
            long res6 = Math.abs(sa - x[i]) + Math.abs(ta - sa);
            long res7 = Math.abs(tb - x[i]) + Math.abs(sb - tb);
            long res8 = Math.abs(sb - x[i]) + Math.abs(tb - sb);
            // System.out.println("res1 = " + res1);
            // System.out.println("res2 = " + res2);
            // System.out.println("res3 = " + res3);
            // System.out.println("res4 = " + res4);
            // System.out.println("res5 = " + res5);
            // System.out.println("res6 = " + res6);
            // System.out.println("res7 = " + res7);
            // System.out.println("res8 = " + res8);
            long ans = Math.min(res1,
                Math.min(res2,
                    Math.min(res3,
                        Math.min(res4, Math.min(res5, Math.min(res6, Math.min(res7, res8)))))));
            System.out.println(ans);
        }
    }
    public static boolean solve(long s, long x) {
        if (s > x) {
            return true;
        }
        return false;
    }
}