import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static long pow(long b, long n, long mod) {
        if (n == 0) return 1;
        if (n % 2 == 0) {
            long t = pow(b, n / 2, mod);
            return t * t % mod;
        }
        return b * pow(b, n - 1, mod) % mod;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt(), b = sc.nextInt();
        final int MOD = 1000000007;
        long[] as = new long[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }
        Arrays.sort(as);
        if (a == 1) {
            for (int i = 0; i < n; i++) {
                System.out.println(as[i]);
            }
            return;
        }
        int cnt = 0;
        while (cnt < b && as[0] * a < as[n - 1]) {
            as[0] *= a;
            as[0] %= MOD;
            Arrays.sort(as);
            cnt++;
        }
        b -= cnt;
        for (int i = 0; i < b % n; i++) {
            as[0] *= a;
            as[0] %= MOD;
            long[] nxt = new long[n];
            for (int j = 0; j < n - 1; j++) {
                nxt[j] = as[j + 1];
            }
            nxt[n - 1] = as[0];
            as = nxt;
        }
        for (int i = 0; i < n; i++) {
            as[i] *= pow(a, b / n, MOD);
            System.out.println(as[i] % MOD);
        }
    }
}