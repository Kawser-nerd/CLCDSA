import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int X = sc.nextInt();

        // X-xn??????????????OK
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = Math.abs(sc.nextInt() - X);
        }

        long ans = Long.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            long tmp_ans = gcd(a[i], a[0]);
            ans = Math.min(ans, tmp_ans);
        }

        out.println(ans);
    }

    //????? ?????????? O(logN)
    public static long gcd(long m, long n) {
        if(m < n) return gcd(n, m);
        if(n == 0) return m;
        return gcd(n, m % n);
    }
}