import java.util.*;

import static java.lang.System.*;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String S = ns();

        long ans = 0;
        int cnt = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == 'W') {
                ans += i - cnt;
                cnt++;
            }
        }

        out.println(ans);
    }

    static int ni() {
        return sc.nextInt();
    }

    static long nl() {
        return sc.nextLong();
    }

    static String ns() {
        return sc.next();
    }

    static int[] niarr(int N) {
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }
        return a;
    }

    static long[] nlarr(int N) {
        long[] a = new long[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextLong();
        }
        return a;
    }
}