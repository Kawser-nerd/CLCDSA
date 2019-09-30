import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        int MOD = 1000000007;
        int MAX = 510000;
        long[] fac = new long[MAX];
        long[] finv = new long[MAX];
        long[] inv = new long[MAX];
        COMinit(fac, finv, inv, MOD, MAX);
        System.out.println(COM(h + w - 2, h - 1, fac, finv, inv, MOD));

    }

    static void COMinit(long[] fac, long[] finv, long[] inv, int MOD, int MAX) {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2 ; i < MAX; i++) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }

    static long COM(int n, int k, long[] fac, long[] finv, long[] inv, int MOD) {
        if (n < k) {
            return 0;
        }
        if (n < 0 || k < 0) {
            return 0;
        }
        return fac[n] * (finv[k]*finv[n - k] % MOD) % MOD;
    }

}