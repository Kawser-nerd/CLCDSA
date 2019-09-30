import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    int R, C;
    int X, Y;
    int D, L;

    long MOD = (long)1e9 + 7;

    void run() {

        Scanner sc = new Scanner(System.in);

        R = sc.nextInt();
        C = sc.nextInt();
        X = sc.nextInt();
        Y = sc.nextInt();
        D = sc.nextInt();
        L = sc.nextInt();

        if (X * Y == D + L) {
            long ans = ncr(X * Y, D);
            ans = (ans * (R - X + 1)) % MOD;
            ans = (ans * (C - Y + 1)) % MOD;
            System.out.println(ans);
        } else {
            long ans = (ncr(X * Y, D) * ncr(X * Y - D, L)) % MOD;
            ans = (ans + MOD - (ncr(X * (Y - 1), D) * ncr(X * (Y - 1) - D, L) * 2) % MOD) % MOD;
            ans = (ans + MOD - (ncr((X - 1) * Y, D) * ncr((X - 1) * Y - D, L) * 2) % MOD) % MOD;
            ans = (ans + (ncr(X * Y - X - Y + 1, D) * ncr(X * Y - X - Y + 1 - D, L) * 4) % MOD) % MOD;
            ans = (ans + (ncr((X - 2) * Y, D) * ncr((X - 2) * Y - D, L)) % MOD) % MOD;
            ans = (ans + (ncr(X * (Y - 2), D) * ncr(X * (Y - 2) - D, L)) % MOD) % MOD;
            ans = (ans + MOD - (ncr((X - 1) * (Y - 2), D) * ncr((X - 1) * (Y - 2) - D, L) * 2) % MOD) % MOD;
            ans = (ans + MOD - (ncr((X - 2) * (Y - 1), D) * ncr((X - 2) * (Y - 1) - D, L) * 2) % MOD) % MOD;
            ans = (ans + ncr((X - 2) * (Y - 2), D) * ncr((X - 2) * (Y - 2) - D, L)) % MOD;
            ans = (ans * (R - X + 1) * (C - Y + 1)) % MOD;
            System.out.println(ans);
        }
    }

    long ncr(int n, int c) {
        if (n < c) return 0;
        if (n < 0 || c < 0) return 0;
        BigInteger bi = BigInteger.ONE;
        for (int i = 0; i < c; i++) {
            bi = bi.multiply(BigInteger.valueOf(n - i));
        }
        for (int i = 1; i <= c; i++) {
            bi = bi.divide(BigInteger.valueOf(i));
        }
        debug(bi, bi.divideAndRemainder(BigInteger.valueOf(MOD)));
        return bi.divideAndRemainder(BigInteger.valueOf(MOD))[1].longValue();
    }

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        new Main().run();
    }
}